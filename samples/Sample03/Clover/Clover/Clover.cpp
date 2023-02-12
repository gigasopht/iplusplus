// win+ -- clover.cpp -- Clover Drawing Program using Regions

import iplusplus;
using namespace core;

import std.core;

#define two_pi (2.0 * 3.14159)

result __stdcall client(handle, unsigned, parameter, parameter);

int __stdcall WinMain(handle module_handle,
    handle previous,
    character* command,
    int show_command)
{
    window_class<character> wclass;

    wclass.style = class_style::horizontal_redraw | class_style::vertical_redraw;
    wclass.procedure = client;
    wclass.extra = 0;
    wclass.window = sizeof(void*);
    wclass.module = module_handle;
    wclass.icon = load_icon(0, (const character*)icon_identity::application);
    wclass.cursor = load_cursor(0, (const character*)cursor_identity::arrow);
    wclass.brush = (handle)get_standard_object(standard_brush::white);
    wclass.name = L"Clover";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Draw a Clover");

    show_window(window, show_command);

    queue_message queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

struct window_data
{
    handle clipping_region;

    int width_of_client,
        height_of_client;
};

result __stdcall client(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (identity)
    {
    case message::create:
    {
        window_data* data = new window_data();
        set_window_pointer(window_handle, 0, (void*)data);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete_object(data->clipping_region);
        delete data;

    }
    break;

    case message::size:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        data->width_of_client = low_part(parameter2);
        data->height_of_client = high_part(parameter2);

        if (data->clipping_region) delete_object(data->clipping_region);

        handle region_array[6];

        region_array[0] = create_elliptic_region(0,
            data->height_of_client / 3,
            data->width_of_client / 2,
            2 * data->height_of_client / 3);

        region_array[1] = create_elliptic_region(data->width_of_client / 2,
            data->height_of_client / 3,
            data->width_of_client,
            2 * data->height_of_client / 3);

        region_array[2] = create_elliptic_region(data->width_of_client / 3,
            0,
            2 * data->width_of_client / 3,
            data->height_of_client / 2);

        region_array[3] = create_elliptic_region(data->width_of_client / 3,
            data->height_of_client / 2,
            2 * data->width_of_client / 3,
            data->height_of_client);

        region_array[4] = create_rectangular_region(0, 0, 1, 1);
        region_array[5] = create_rectangular_region(0, 0, 1, 1);

        data->clipping_region = create_rectangular_region(0, 0, 1, 1);

        combine_region(region_array[4], region_array[0], region_array[1], region_combine:: _or );
        combine_region(region_array[5], region_array[2], region_array[3], region_combine:: _or );
        combine_region(data->clipping_region, region_array[4], region_array[5], region_combine::exclusive_or);

        for (int i = 0; i < 6; i++) delete_object(region_array[i]);
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        set_viewport_origin(device_context, data->width_of_client / 2, data->height_of_client / 2);
        select_clipping_region(device_context, data->clipping_region);

        double radius = sqrt(data->width_of_client * data->width_of_client / 2.0 + data->height_of_client * data->height_of_client / 2.0);

        for (double Angle = 0; Angle < two_pi; Angle += two_pi / 360)
        {
            move_to(device_context, 0, 0);
            draw_line_to(device_context, (int)(radius * cos(Angle) + 0.5),
                (int)(-radius * sin(Angle) + 0.5));
        }
        end_paint(window_handle, &paint_structure);
    }
    break;

    case message::close:
        post_quit_message();
        break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }

    return 0;
}

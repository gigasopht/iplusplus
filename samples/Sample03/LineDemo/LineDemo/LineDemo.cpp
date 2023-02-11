// win+ -- LineDemo.cpp -- Line Drawing Demonstration Program

import iplusplus;
using namespace iplusplus;

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
    wclass.name = L"LineDemo";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Line Demonstration");

    show_window(window, show_command);

    queue queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

struct window_data
{
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
        delete data;
    }
    break;

    case message::size:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        data->width_of_client = low_part(parameter2);
        data->height_of_client = high_part(parameter2);
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        select_object(device_context, create_solid_brush(0x0000ff));

        draw_rectangle(device_context,
            data->width_of_client / 8,
            data->height_of_client / 8,
            7 * data->width_of_client / 8,
            7 * data->height_of_client / 8);

        move_to(device_context, 0, 0);
        draw_line_to(device_context, data->width_of_client, data->height_of_client);

        move_to(device_context, 0, data->height_of_client);
        draw_line_to(device_context, data->width_of_client, 0);

        delete_object(select_object(device_context, create_solid_brush(0x00ff00)));

        draw_ellipse(device_context,
            data->width_of_client / 8,
            data->height_of_client / 8,
            7 * data->width_of_client / 8,
            7 * data->height_of_client / 8);

        delete_object(select_object(device_context, create_solid_brush(0xff0000)));

        draw_rounded_rectangle(device_context,
            data->width_of_client / 4,
            data->height_of_client / 4,
            3 * data->width_of_client / 4,
            3 * data->height_of_client / 4,
            data->width_of_client / 4,
            data->height_of_client / 4);

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

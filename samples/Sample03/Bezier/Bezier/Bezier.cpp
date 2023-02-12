// win+ -- Bezier.cpp -- Bezier Spline Example

import iplusplus;
using namespace core;

result __stdcall client(handle, unsigned, parameter, parameter);
void draw_bezier(handle, const ipoint*);

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
    wclass.name = L"Bezier";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Bezier Splines");

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
    ipoint point_array[4];
};

result __stdcall client(handle window_handle, unsigned identity, parameter parameter1, parameter parameter2)
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

        int width_of_client = low_part(parameter2);
        int height_of_client = high_part(parameter2);

        data->point_array[0](0) = width_of_client / 4;
        data->point_array[0](1) = height_of_client / 2;

        data->point_array[1](0) = width_of_client / 2;
        data->point_array[1](1) = height_of_client / 4;

        data->point_array[2](0) = width_of_client / 2;
        data->point_array[2](1) = 3 * height_of_client / 4;

        data->point_array[3](0) = 3 * width_of_client / 4;
        data->point_array[3](1) = height_of_client / 2;
    }
    break;

    case message::mouse_move:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        if ((int)parameter1 & mouse_state::left_button || (int)parameter1 & mouse_state::right_button)
        {
            handle device_context = get_device_context(window_handle);

            select_object(device_context, get_standard_object(standard_pen::white));
            draw_bezier(device_context, data->point_array);

            if ((int)parameter1 & mouse_state::left_button)
            {
                data->point_array[1](0) = low_part(parameter2);
                data->point_array[1](1) = high_part(parameter2);
            }

            if ((int)parameter1 & mouse_state::right_button)
            {
                data->point_array[2](0) = low_part(parameter2);
                data->point_array[2](1) = high_part(parameter2);
            }

            select_object(device_context, get_standard_object(standard_pen::black));
            draw_bezier(device_context, data->point_array);
            release_device_context(window_handle, device_context);
        }
    }
    break;

    case message::left_button_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        handle device_context = get_device_context(window_handle);

        select_object(device_context, get_standard_object(standard_pen::white));
        draw_bezier(device_context, data->point_array);

        data->point_array[1](0) = low_part(parameter2);
        data->point_array[1](1) = high_part(parameter2);

        select_object(device_context, get_standard_object(standard_pen::black));
        draw_bezier(device_context, data->point_array);
        release_device_context(window_handle, device_context);
    }
    break;

    case message::right_button_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        handle device_context = get_device_context(window_handle);

        select_object(device_context, get_standard_object(standard_pen::white));
        draw_bezier(device_context, data->point_array);

        data->point_array[2](0) = low_part(parameter2);
        data->point_array[2](1) = high_part(parameter2);

        select_object(device_context, get_standard_object(standard_pen::black));
        draw_bezier(device_context, data->point_array);
        release_device_context(window_handle, device_context);
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);
        draw_bezier(device_context, data->point_array);
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

void draw_bezier(handle device_context, const ipoint* point_array)
{
    draw_splines(device_context, (const ipoint*)point_array, 4);

    move_to(device_context, point_array[0](0), point_array[0](1));
    draw_line_to(device_context, point_array[1](0), point_array[1](1));

    move_to(device_context, point_array[2](0), point_array[2](1));
    draw_line_to(device_context, point_array[3](0), point_array[3](1));
}


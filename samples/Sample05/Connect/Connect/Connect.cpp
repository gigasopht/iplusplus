// Win+ -- Connect.cpp -- Connect-the-Dots Mouse Demonstration Program

import iplusplus;
using namespace iplusplus;

result __stdcall client(handle, unsigned, parameter, parameter);

int __stdcall WinMain(handle _module,
    handle previous,
    character* command,
    int show_command)
{
    window_class<character> wclass;

    wclass.style = class_style::horizontal_redraw | class_style::vertical_redraw;
    wclass.procedure = client;
    wclass.extra = 0;
    wclass.window = sizeof(void*);
    wclass.module = _module;
    wclass.icon = load_icon(0, (const character*)icon_identity::application);
    wclass.cursor = load_cursor(0, (const character*)cursor_identity::arrow);
    wclass.brush = (handle)get_standard_object(standard_brush::white);
    wclass.name = L"Mouse";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Mouse Demonstration - Connect the Dots");

    show_window(window, show_command);

    iplusplus::queue queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

enum { maximum_points = 1000 };

struct window_data
{
    ipoint point_array[maximum_points];
    int count;
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

    case message::left_button_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        data->count = 0;
        invalidate_rectangle(window_handle, (const irectangle*)null, true);
    }
    break;

    case message::mouse_move:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        if ((int)parameter1 & mouse_state::left_button && data->count < maximum_points)
        {
            data->point_array[data->count](0) = low_part(parameter2);
            data->point_array[data->count++](1) = high_part(parameter2);

            handle device_context = get_device_context(window_handle);
            set_pixel(device_context, low_part(parameter2), high_part(parameter2), 0);
            release_device_context(window_handle, device_context);
        }
    }
    break;

    case message::left_button_up:
        invalidate_rectangle(window_handle, (const irectangle*)null, false);
        break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        set_cursor(load_cursor((handle)null, (const character*)cursor_identity::wait));

        for (int i = 0; i < data->count - 1; i++)
            for (int j = i + 1; j < data->count; j++)
            {
                move_to(device_context, data->point_array[i](0), data->point_array[i](1));
                draw_line_to(device_context, data->point_array[j](0), data->point_array[j](1));
            }

        set_cursor(load_cursor((handle)null, (const character*)cursor_identity::arrow));

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

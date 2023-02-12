// win+ -- SineWave.cpp -- Sine wave using: draw_lines

import std.core;
using namespace std;

import iplusplus;
using namespace core;

enum { number_of_points = 1000 };

#define two_pi (2 * 3.14159)

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
    wclass.name = L"SineWave";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Sine Wave Demonstration");

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
    int width_of_client,
        height_of_client;

    ipoint point_array[number_of_points];
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

        for (int i = 0; i < number_of_points; i++)
        {
            data->point_array[i](0) = i * data->width_of_client / number_of_points;
            data->point_array[i](1) = (int)(data->height_of_client / 2 * (1 - sin(two_pi * i / number_of_points)));
        }
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        move_to(device_context, 0, data->height_of_client / 2);
        draw_line_to(device_context, data->width_of_client, data->height_of_client / 2);

        draw_lines(device_context, data->point_array, number_of_points);
        end_paint(device_context, &paint_structure);
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

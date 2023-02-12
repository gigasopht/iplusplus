// Win+ -- Beeper1.cpp  -- Timer Demonstration Program Number 1

import iplusplus;
using namespace core;

enum { identity_of_timer = 1 };

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
    wclass.name = L"Beeper1";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Beeper1");

    set_timer(window, identity_of_timer, 1000);

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
    int alternate;

    window_data()
    {
        alternate = false;
    }
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
        cancel_timer(window_handle, identity_of_timer);
    }

    case message::timer:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        message_beep(message_box_style::ok);
        data->alternate = !data->alternate;
        invalidate_rectangle(window_handle, (const irectangle*)null, false);
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        irectangle client;
        get_client_rectangle(window_handle, &client);

        handle brush_handle = create_solid_brush(data->alternate ? red_green_blue(255, 0, 0)
            : red_green_blue(0, 0, 255));

        fill_rectangle(device_context, &client, brush_handle);
        end_paint(window_handle, &paint_structure);
        delete_object(brush_handle);
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

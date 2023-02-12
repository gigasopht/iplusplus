// win+ -- Metafile1.cpp -- Enhanced Metafile Demonstration #1

import iplusplus;
using namespace core;

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
    wclass.name = L"Metafile1";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Metafile Demonstration");

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
    handle metafile;
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

        handle device_context = create_metafile<character>();

        draw_rectangle(device_context, 100, 100, 200, 200);

        move_to(device_context, 100, 100);
        draw_line_to(device_context, 200, 200);

        move_to(device_context, 200, 100);
        draw_line_to(device_context, 100, 200);

        data->metafile = close_metafile(device_context);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete_metafile(data->metafile);
        delete data;
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        irectangle rectangle_client;
        get_client_rectangle(window_handle, &rectangle_client);

        rectangle_client[0](0) = rectangle_client[1](0) / 4;
        rectangle_client[1](0) = 3 * rectangle_client[1](0) / 4;
        rectangle_client[0](1) = rectangle_client[1](1) / 4;
        rectangle_client[1](1) = 3 * rectangle_client[1](1) / 4;

        play_metafile(device_context, data->metafile, &rectangle_client);

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

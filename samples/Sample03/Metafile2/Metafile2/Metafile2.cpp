// win+ -- Metafile2.cpp -- Enhanced Metafile Demonstration #2

import iplusplus;
using namespace core;

const character metafile_name[] = L"Metafile2.emf";
const character metafile_title[] = L"Metafile2\0Metafile Demonstration #2";

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
    wclass.name = L"Metafile2";

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

result __stdcall client(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (identity)
    {
    case message::create:
    {
        handle device_context = create_metafile((handle)null,
            metafile_name,
            (const irectangle*)null,
            metafile_title);

        draw_rectangle(device_context, 100, 100, 200, 200);

        move_to(device_context, 100, 100);
        draw_line_to(device_context, 200, 200);

        move_to(device_context, 200, 100);
        draw_line_to(device_context, 100, 200);

        handle metafile = close_metafile(device_context);
        delete_metafile(metafile);
    }
    break;

    case message::paint:
    {
        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        irectangle rectangle_client;
        get_client_rectangle(window_handle, &rectangle_client);

        rectangle_client[0](0) = rectangle_client[1](0) / 4;
        rectangle_client[1](0) = 3 * rectangle_client[1](0) / 4;
        rectangle_client[0](1) = rectangle_client[1](1) / 4;
        rectangle_client[1](1) = 3 * rectangle_client[1](1) / 4;

        handle metafile = get_metafile(metafile_name);

        play_metafile(device_context, metafile, &rectangle_client);

        delete_metafile(metafile);

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

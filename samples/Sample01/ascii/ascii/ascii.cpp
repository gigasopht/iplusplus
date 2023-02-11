// win+ -- ascii  --- this is how to create a single byte ascii application.

import iplusplus;
using namespace iplusplus;

result __stdcall client(handle, unsigned, parameter, parameter);

int __stdcall WinMain(handle module_handle,
    handle previous,
    character* command,
    int show_command)
{
    window_class<char> wclass;

    wclass.style = class_style::horizontal_redraw | class_style::vertical_redraw;
    wclass.procedure = client;
    wclass.extra = 0;
    wclass.window = 0;
    wclass.module = module_handle;
    wclass.icon = load_icon(0, (const character*)icon_identity::application);
    wclass.cursor = load_cursor(0, (const character*)cursor_identity::arrow);
    wclass.brush = (handle)get_standard_object(standard_brush::light_gray);
    wclass.name = "example";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, "Example");

    show_window(window, show_command);

    queue queue_message;
    while (get_message_a(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message_a(&queue_message);
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
    case message::close:
        if (message_box(window_handle,
            "Exit?",
            "Windows",
            message_box_style::ok_cancel | message_box_style::icon_question) == item_identity::ok)
            post_quit_message(0);
        break;

    case message::paint:
    {
        irectangle bounds;
        get_client_rectangle(window_handle, &bounds);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        draw_text(device_context,
            "Hello, world++ !!!",
            -1,
            &bounds,
            draw_text_format::single_line | draw_text_format::center | draw_text_format::vertical_center);

        end_paint(window_handle, &paint_structure);
    }
    break;

    default:
        return default_window_procedure_a(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

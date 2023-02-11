// Win# -- About3.cpp -- About Box Demonstration Program no. 3

import iplusplus;
using namespace iplusplus;

#include "About3.h"

result __stdcall client(handle, unsigned, parameter, parameter);
result __stdcall about(handle, unsigned, parameter, parameter);
result __stdcall ellipse_procedure(handle, unsigned, parameter, parameter);

enum { class_ellipse = 2 };

int __stdcall WinMain(handle module_handle,
    handle reserved,
    character* command_line,
    int show_command)
{
    window_class<character> ellipse_class;

    ellipse_class.style = class_style::horizontal_redraw | class_style::vertical_redraw;
    ellipse_class.procedure = ellipse_procedure;
    ellipse_class.extra = 0;
    ellipse_class.window = 8;
    ellipse_class.module = module_handle;
    ellipse_class.icon = load_icon(module_handle, (const character*)FrameIdentity);
    ellipse_class.cursor = load_cursor((handle)null, (const character*)cursor_identity::arrow);
    ellipse_class.brush = (handle)get_standard_object(standard_brush::white);
    ellipse_class.name = (const character*)class_ellipse;
    atom atom_ellipse = register_class(&ellipse_class);

    window_class<character> wclass;

    wclass.style = 0;
    wclass.procedure = client;
    wclass.extra = 0;
    wclass.window = 8;
    wclass.module = module_handle;
    wclass.icon = load_icon(module_handle, (const character*)FrameIdentity);
    wclass.cursor = load_cursor((handle)null, (const character*)cursor_identity::arrow);
    wclass.brush = (handle)get_standard_object(standard_brush::white);
    wclass.name = (const character*)L"About3";
    atom atom_window = register_class(&wclass);

    character aszTitle[40];
    load_string(module_handle, FrameIdentity, aszTitle, 40);

    handle window_handle = create_window(atom_window,
        aszTitle,
        style::standard,
        use_default,
        use_default,
        use_default,
        use_default,
        (handle)null,
        load_menu(module_handle, (const character*)FrameIdentity));

    show_window(window_handle, show_command);

    iplusplus::queue queue_message;
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
    case message::command:
        switch (low_part(parameter1))
        {
        case MenuItemAbout:
            dialog_box(get_module_handle<character>(),
                (const character*)DialogIdentity,
                window_handle,
                about);
            break;
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

result __stdcall about(handle dialog_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (identity)
    {
    case message::initialize_dialog:
        return (result)true;

    case message::command:
        switch (low_part(parameter1))
        {
        case item_identity::ok:
            end_dialog(dialog_handle, 0);
            return (result)true;
        }
        break;
    }

    return false;
}

result __stdcall ellipse_procedure(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (identity)
    {
    case message::create:
        set_class_pointer(window_handle, class_offset::background_brush, (handle)(system_color::button_face + 1));
        break;

    case message::paint:
    {
        irectangle client_rectangle;
        get_client_rectangle(window_handle, &client_rectangle);

        character text[40];
        get_window_text(window_handle, text, sizeof(text));

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        handle brush_handle = create_solid_brush(get_system_color(system_color::window));
        brush_handle = select_object(device_context, brush_handle);
        set_background_color(device_context, get_system_color(system_color::window));
        set_text_color(device_context, get_system_color(system_color::window_text));

        draw_ellipse(device_context,
            client_rectangle[0](0),
            client_rectangle[0](1),
            client_rectangle[1](0),
            client_rectangle[1](1));

        draw_text(device_context,
            text,
            -1,
            &client_rectangle,
            draw_text_format::single_line | draw_text_format::center | draw_text_format::vertical_center);

        delete_object(select_object(device_context, brush_handle));

        end_paint(window_handle, &paint_structure);
    }
    break;

    case message::key_up:
        if ((int)parameter1 != virtual_key::space) break;
    case message::left_button_up:
        send_message(get_parent(window_handle),
            message::command,
            (parameter)get_window_integer(window_handle, offset::identity),
            (parameter)window_handle);
        break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

// Win+ -- About1.cpp -- About Box Demonstration Program Number 1

import iplusplus;
using namespace core;

#include "About1.h"

result __stdcall client(handle, unsigned, parameter, parameter);
result __stdcall about(handle, unsigned, parameter, parameter);

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
    wclass.name = L"About1";

    atom atom_name = register_class(&wclass);

    character aszFrame[80]; // buffer for application title

    load_string(module_handle,
        FrameIdentity,
        aszFrame,
        80);

    //handle window = create_window(atom_name, aszFrame);

    resource_string rs(FrameIdentity);

    handle window_handle = create_window(atom_name,
        (const character*)rs,
        style::standard,
        use_default,
        use_default,
        use_default,
        use_default,
        (handle)null,
        load_menu(module_handle, (const character*)FrameIdentity));

    show_window(window_handle, show_command);

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
        return 0;

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

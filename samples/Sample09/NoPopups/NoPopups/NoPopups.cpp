// Win+ -- NoPopups.cpp -- Demonstrates A no-Popup Nested Menu Scheme

import iplusplus;
using namespace iplusplus;

#include "NoPopups.h"

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
    wclass.name = L"NoPopups2";

    atom atom_name = register_class(&wclass);

    character aszFrame[80]; // buffer for application title

    load_string(module_handle,
        FrameIdentity,
        aszFrame,
        80);

    handle window = create_window(atom_name, aszFrame);

    show_window(window, show_command);

    iplusplus::queue queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

struct window_data
{
    handle main_menu, edit_menu, file_menu;
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

        set_class_pointer(window_handle, class_offset::background_brush, get_standard_object(standard_brush::white));
        set_class_pointer(window_handle, class_offset::cursor, load_cursor((handle)null, (const character*)cursor_identity::arrow));

        handle module_handle = get_module_handle<character>();

        data->main_menu = load_menu(module_handle, (const character*)MenuMain);
        data->file_menu = load_menu(module_handle, (const character*)MenuFile);
        data->edit_menu = load_menu(module_handle, (const character*)MenuEdit);

        set_menu(window_handle, data->main_menu);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        set_menu(window_handle, data->main_menu);
        destroy_menu(data->file_menu);
        destroy_menu(data->edit_menu);
        delete data;
    }
    break;


    case message::command:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        switch (low_part(parameter1))
        {
        case MenuMain:
            set_menu(window_handle, data->main_menu);
            break;

        case MenuFile:
            set_menu(window_handle, data->file_menu);
            break;

        case MenuEdit:
            set_menu(window_handle, data->edit_menu);
            break;

        case MenuItemNew:
        case MenuItemOpen:
        case MenuItemSave:
        case MenuItemSaveAs:
        case MenuItemUndo:
        case MenuItemCut:
        case MenuItemCopy:
        case MenuItemPaste:
        case MenuItemDelete:
            message_beep(message_box_style::ok);
            break;
        }
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

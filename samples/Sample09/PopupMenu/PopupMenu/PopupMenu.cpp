// Win+ -- PopupMenu.cpp -- Popup Menu Demonstration

import iplusplus;
using namespace core;

#include "PopupMenu.h"

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
    wclass.name = L"PopupMenu";

    atom atom_name = register_class(&wclass);

    character aszFrame[80]; // buffer for application title

    load_string(module_handle,
        FrameIdentity,
        aszFrame,
        80);

    handle window = create_window(atom_name, aszFrame);

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
    handle menu_handle;
    int selection;
    int brush_array[5];

    window_data()
    {
        selection = MenuItemWhite;
        brush_array[0] = standard_brush::white;
        brush_array[1] = standard_brush::light_gray;
        brush_array[2] = standard_brush::gray;
        brush_array[3] = standard_brush::dark_gray;
        brush_array[4] = standard_brush::black;
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
        data->menu_handle = load_menu(get_module_handle<character>(), (const character*)MenuIdentity);
        data->menu_handle = get_submenu(data->menu_handle, 0);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete data;
    }
    break;

    case message::right_button_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        ipoint track(low_part(parameter2), high_part(parameter2));
        client_to_screen(window_handle, &track);
        track_popup_menu(data->menu_handle, 0, track(0), track(1), 0, window_handle, (const irectangle*)null);
    }
    break;

    case message::command:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        switch (low_part(parameter1))
        {
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

        case MenuItemWhite:
        case MenuItemLightGray:
        case MenuItemGray:
        case MenuItemDarkGray:
        case MenuItemBlack:
        {
            check_menu_item(data->menu_handle, data->selection, menu_item_flag::unchecked);
            data->selection = low_part(parameter1);
            check_menu_item(data->menu_handle, data->selection, menu_item_flag::checked);

            handle brush_handle = get_standard_object(data->brush_array[low_part(parameter1) - MenuItemWhite]);
            set_class_pointer(window_handle, class_offset::background_brush, brush_handle);
            invalidate_rectangle(window_handle, (const irectangle*)null, true);
        }
        break;

        case MenuItemAbout:
        {
            character about[50];
            character frame[50];
            load_string(0, StringAbout, about, 50);
            load_string(0, FrameIdentity, frame, 50);
            message_box(window_handle,
                about,
                frame,
                message_box_style::icon_information | message_box_style::ok);
        }
        break;

        case MenuItemExit:
            send_message(window_handle, message::close, 0, 0);
            break;

        case MenuItemHelp:
        {
            character help[50];
            character frame[50];
            load_string(0, StringHelp, help, 50);
            load_string(0, FrameIdentity, frame, 50);
            message_box(window_handle,
                help,
                frame,
                message_box_style::icon_exclamation | message_box_style::ok);
        }
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

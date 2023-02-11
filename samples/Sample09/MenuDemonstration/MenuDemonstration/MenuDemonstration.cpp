// Win+-- menuDemonstration.cpp -- menu demonstration

import iplusplus;
using namespace iplusplus;

#include "MenuDemonstration.h"

result __stdcall client(handle, unsigned, parameter, parameter);

int __stdcall WinMain(handle module_handle,
    handle reserved,
    character* command_line,
    int show_command)
{
    handle window_handle = create_window(register_window_class(L"Demo",client,class_style::horizontal_redraw | class_style::vertical_redraw),
        (const character*)standard::resource_string(FrameIdentity),
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

struct window_data
{
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
    unsigned Identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (Identity)
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

    case message::command:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        handle menu = get_menu(window_handle);

        switch (low_part(parameter1))
        {
        case MenuItemNew:
        case MenuItemOpen:
        case MenuItemSave:
        case MenuItemSaveAs:
            message_beep(message_box_style::ok);
            break;

        case MenuItemExit:
            send_message(window_handle, message::close);
            break;

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
            check_menu_item(menu, data->selection, menu_item_flag::unchecked);
            data->selection = low_part(parameter1);
            check_menu_item(menu, data->selection, menu_item_flag::checked);
            set_class_pointer(window_handle, class_offset::background_brush, get_standard_object(data->brush_array[low_part(parameter1) - MenuItemWhite]));
            invalidate_rectangle(window_handle, (const irectangle*)null, true);
        }
        break;

        case MenuItemStart:
            if (set_timer(window_handle, 1, 1000, (timer_procedure)null))
            {
                enable_menu_item(menu, MenuItemStart, menu_item_flag::grayed);
                enable_menu_item(menu, MenuItemStop, menu_item_flag::enabled);
            }
            break;

        case MenuItemStop:
            cancel_timer(window_handle, 1);
            enable_menu_item(menu, MenuItemStart, menu_item_flag::enabled);
            enable_menu_item(menu, MenuItemStop, menu_item_flag::grayed);
            break;

        case MenuItemHelp:
        {
            message_box(window_handle,
                (const character*)standard::resource_string(StringHelp),
                (const character*)standard::resource_string(FrameIdentity),
                message_box_style::icon_exclamation | message_box_style::ok);
        }
        break;

        case MenuItemAbout:
        {
            message_box(window_handle,
                (const character*)standard::resource_string(StringAbout),
                (const character*)standard::resource_string(FrameIdentity),
                message_box_style::icon_information | message_box_style::ok);
        }
        break;
        }
    }
    break;

    case message::timer:
        message_beep(message_box_style::icon_exclamation);
        break;

    case message::close:
    {
        if (message_box(window_handle,
            (const character*)standard::resource_string(StringExit),
            (const character*)standard::resource_string(StringApplication),
            message_box_style::yes_no) == item_identity::yes)
            post_quit_message();
    }
    break;

    default:
        return default_window_procedure(window_handle, Identity, parameter1, parameter2);
    }
    return 0;
}

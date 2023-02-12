// Win+ -- SystemMenu.cpp -- Changing the System Menu

import iplusplus;
using namespace core;

struct system_item
{
    enum
    {
        about = 1,
        help = 2,
        remove = 3
    };
};

result __stdcall client(handle, unsigned, parameter, parameter);

int __stdcall WinMain(handle module_handle,
    handle previous,
    character* command,
    int show_command)
{
    show_window(create_window(register_window_class(L"System Menu",client,class_style::horizontal_redraw | class_style::vertical_redraw), L"System Menu"), show_command);
    return loop();
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
        handle menu_handle = get_system_menu(window_handle, false);
        append_menu(menu_handle, menu_item_flag::separator, 0, (const character*)null);
        append_menu(menu_handle, menu_item_flag::string, (void*)system_item::about, L"About...");
        append_menu(menu_handle, menu_item_flag::string, (void*)system_item::help, L"Help...");
        append_menu(menu_handle, menu_item_flag::string, (void*)system_item::remove, L"Remove Additions");
    }
    break;

    case message::system_command:
        switch (low_part(parameter1))
        {
        case system_item::about:
            message_box(window_handle,
                L"About System Menus",
                L"System Menu Manipulation",
                message_box_style::ok | message_box_style::icon_information);
            break;

        case system_item::help:
            message_box(window_handle,
                L"Help is yet to be implemented!",
                L"System Menu Manipulation",
                message_box_style::ok | message_box_style::icon_exclamation);
            break;

        case system_item::remove:
            get_system_menu(window_handle, true);
            break;

        default:
            return default_window_procedure(window_handle, identity, parameter1, parameter2);
        }
        break;

    case message::close:
        post_quit_message(0);
        break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

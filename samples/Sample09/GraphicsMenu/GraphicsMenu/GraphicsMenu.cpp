// Win+ -- GraphicsMenu.cpp - Example of Bitmaps in Menus

import iplusplus;
using namespace iplusplus;

#include "GraphicsMenu.h"

result __stdcall client(handle, unsigned, parameter, parameter);
handle stretch_the_bitmap(handle);
handle get_font_bitmap(int);

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
    wclass.name = L"GraphicsMenu";

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
    handle bitmap_help;
    handle bitmap_edit;
    handle bitmap_file;
    handle bitmap_font;
    handle bitmap_array[3];

    int current_font;

    window_data()
    {
        current_font = MenuItemCourier;
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

        handle menu = create_menu();

        handle module_handle = get_module_handle<character>();

        handle file_menu = load_menu(module_handle, (const character*)MenuFile);

        data->bitmap_file = stretch_the_bitmap(load_bitmap(module_handle, (const character*)BitmapIdentityFile));

        append_menu(menu,
            menu_item_flag::bitmap | menu_item_flag::submenu,
            file_menu,
            (character*)data->bitmap_file);

        handle edit_menu = load_menu(module_handle, (const character*)MenuEdit);

        data->bitmap_edit = stretch_the_bitmap(load_bitmap(module_handle, (const character*)BitmapIdentityEdit));

        append_menu(menu,
            menu_item_flag::bitmap | menu_item_flag::submenu,
            edit_menu,
            (character*)data->bitmap_edit);

        handle font_menu = create_menu();

        for (int i = 0; i < 3; i++)
        {
            data->bitmap_array[i] = get_font_bitmap(i);

            append_menu(font_menu,
                menu_item_flag::bitmap,
                (void*)(MenuItemCourier + i),
                (character*)data->bitmap_array[i]);
        }

        data->bitmap_font = stretch_the_bitmap(load_bitmap(module_handle, (const character*)BitmapIdentityFont));

        append_menu(menu,
            menu_item_flag::bitmap | menu_item_flag::submenu,
            (void*)font_menu,
            (character*)data->bitmap_font);

        set_menu(window_handle, menu);

        handle system_menu = get_system_menu(window_handle, false);
        data->bitmap_help = stretch_the_bitmap(load_bitmap(module_handle, (const character*)BitmapIdentityHelp));
        append_menu(system_menu, menu_item_flag::separator, (handle)null, (const character*)null);
        append_menu(system_menu, menu_item_flag::bitmap, (void*)MenuItemHelp, (const character*)data->bitmap_help);

        check_menu_item(get_menu(window_handle), data->current_font, menu_item_flag::checked);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        delete_object(data->bitmap_help);
        delete_object(data->bitmap_edit);
        delete_object(data->bitmap_file);
        delete_object(data->bitmap_font);

        for (int j = 0; j < 3; j++)
            delete_object(data->bitmap_array[j]);

        delete data;
    }
    break;

    case message::system_command:
        switch (low_part(parameter1))
        {
        case MenuItemHelp:
            character help[50];
            character title[50];
            load_string(0, StringHelp, help, 50);
            load_string(0, FrameIdentity, title, 50);
            message_box(window_handle,
                help,
                title,
                message_box_style::ok | message_box_style::icon_exclamation);
            break;

        default:
            return default_window_procedure(window_handle, identity, parameter1, parameter2);
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

        case MenuItemCourier:
        case MenuItemArial:
        case MenuItemTimes:
        {
            handle menu = get_menu(window_handle);
            check_menu_item(menu, data->current_font, menu_item_flag::unchecked);
            data->current_font = low_part(parameter1);
            check_menu_item(menu, data->current_font, menu_item_flag::checked);
        }
        break;
        }
    }
    break;

    case message::close:
        post_quit_message();
        break;

    case message::erase_background:
    {
        irectangle bounds;
        get_update_rectangle(window_handle, &bounds);
        fill_rectangle((handle)parameter1, &bounds, get_standard_object(standard_brush::white));
    }
    return (result)true;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

handle stretch_the_bitmap(handle bitmap1)
{
    handle device_context = create_informational_device_context(L"DISPLAY", (const character*)null, (const character*)null, (const device_mode<character>*)null);

    text_metrics<character> text_metrics_get;
    get_text_metrics(device_context, &text_metrics_get);

    handle memory_device1 = create_memory_device_context(device_context);
    handle memory_device2 = create_memory_device_context(device_context);

    delete_device_context(device_context);

    bitmap_definition  bitmap_definition1;
    get_object(bitmap1, sizeof(bitmap_definition), (character*)&bitmap_definition1);

    bitmap_definition bitmap_definition2 = bitmap_definition1;

    bitmap_definition2.width = (text_metrics_get.average_character_width * bitmap_definition2.width) / 4;
    bitmap_definition2.height = (text_metrics_get.height * bitmap_definition2.height) / 8;
    bitmap_definition2.bytes = ((bitmap_definition2.width + 15) / 16) * 2;

    handle bitmap2 = create_bitmap_indirect(&bitmap_definition2);

    select_object(memory_device1, bitmap1);
    select_object(memory_device2, bitmap2);

    stretch_bit_block_transfer(memory_device2,
        0,
        0,
        bitmap_definition2.width,
        bitmap_definition2.height,
        memory_device1,
        0,
        0,
        bitmap_definition1.width,
        bitmap_definition1.height,
        raster_operation::source_copy);

    delete_device_context(memory_device1);
    delete_device_context(memory_device2);
    delete_object(bitmap1);

    return bitmap2;
}

handle get_font_bitmap(int i)
{
    character courier[50];
    character arial[50];
    character times[50];

    load_string(0, StringCourier, courier, 50);
    load_string(0, StringArial, arial, 50);
    load_string(0, StringTimes, times, 50);

    character* face_names[3] = { courier,arial,times };

    handle device_context = create_informational_device_context(L"DISPLAY", (const character*)null, (const character*)null, (const device_mode<character>*)null);

    text_metrics<character> text_metrics_get;
    get_text_metrics(device_context, &text_metrics_get);

    logical_font<character> logical_font_create;
    logical_font_create.height = 2 * text_metrics_get.height;
    copy_string((character*)logical_font_create.face_name, face_names[i]);

    handle memory_device = create_memory_device_context(device_context);
    handle font = (handle)select_object(memory_device, create_font_indirect(&logical_font_create));

    idimensions text;
    get_text_extent(memory_device, face_names[i], string_length(face_names[i]), &text);

    handle bitmap = create_bitmap(text(0), text(1), 1, 1, (handle)null);
    select_object(memory_device, bitmap);

    text_out(memory_device, 0, 0, face_names[i], string_length(face_names[i]));

    delete_object(select_object(memory_device, font));
    delete_device_context(memory_device);
    delete_device_context(device_context);

    return bitmap;
}

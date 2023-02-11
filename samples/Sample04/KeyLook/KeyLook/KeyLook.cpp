// Win+ -- KeyLook.cpp -- Displays Keyboard and character Messages

import iplusplus;
using namespace iplusplus;

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
    wclass.name = L"KeyLook";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Message Display Program is the window?");

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
    irectangle rectangle_of_client;

    int width_of_character,
        height_of_character;

    standard::string top;
    standard::string underline;

    window_data()
        : top(L"Message                  Key Char Repeat Scan Ext ALT Prev Tran"),
        underline(L"_______                  ___ ____ ______ ____ ___ ___ ____ ____") {}
};

void show_key(handle, int, const character*, parameter, parameter, window_data*);

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

        handle device_context = get_device_context(window_handle);

        select_object(device_context, get_standard_object(standard_font::fixed_system));

        text_metrics<character> text_metrics_get;
        get_text_metrics(device_context, &text_metrics_get);

        data->width_of_character = text_metrics_get.average_character_width;
        data->height_of_character = text_metrics_get.height;

        release_device_context(window_handle, device_context);

        data->rectangle_of_client[0](1) = 3 * data->height_of_character / 2;
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete data;
    }
    break;

    case message::size:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        data->rectangle_of_client[1](0) = low_part(parameter2);
        data->rectangle_of_client[1](1) = high_part(parameter2);
        update_window(window_handle);
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        invalidate_rectangle(window_handle, (const irectangle*)null, true);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        select_object(device_context, get_standard_object(standard_font::fixed_system));

        set_background_mode(device_context, background::transparent);

        text_out(device_context,
            data->width_of_character,
            data->height_of_character / 2,
            (const character*)data->top,
            string_length((const character*)data->top));

        text_out(device_context,
            data->width_of_character,
            data->height_of_character / 2,
            (const character*)data->underline,
            string_length((const character*)data->underline));

        end_paint(window_handle, &paint_structure);
    }
    break;

    case message::key_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        show_key(window_handle, 0, L"message::key_down", parameter1, parameter2, data);
    }
    break;

    case message::key_up:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        show_key(window_handle, 0, L"message::key_up", parameter1, parameter2, data);
    }
    break;

    case message::character:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        show_key(window_handle, 1, L"message::character", parameter1, parameter2, data);
    }
    break;

    case message::accent_character:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        show_key(window_handle, 1, L"message::accent_character", parameter1, parameter2, data);
    }
    break;

    case message::system_key_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        show_key(window_handle, 0, L"message::system_key_down", parameter1, parameter2, data);
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }

    case message::system_key_up:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        show_key(window_handle, 0, L"message::system_key_up", parameter1, parameter2, data);
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }

    case message::system_character:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        show_key(window_handle, 1, L"message::system_character", parameter1, parameter2, data);
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }

    case message::system_accent_character:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        show_key(window_handle, 1, L"message::system_accent_character", parameter1, parameter2, data);
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }

    case message::close:
        post_quit_message();
        break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

void show_key(handle window_handle,
    int type,
    const character* message,
    parameter parameter1,
    parameter parameter2,
    window_data* data)
{
    const character* format_array[2] = { L"%-24s %3d    %c %6u %4d %3s %3s %4s %4s",
                                         L"%-24s    %3d %c %6u %4d %3s %3s %4s %4s" };

    scroll_window(window_handle, 0, -data->height_of_character, &data->rectangle_of_client, &data->rectangle_of_client);

    handle device_context = get_device_context(window_handle);

    select_object(device_context, get_standard_object(standard_font::fixed_system));

    character buffer[128];

    text_out(device_context,
        data->width_of_character,
        data->rectangle_of_client[1](1) - data->height_of_character,
        buffer,
        print_string(buffer,
            format_array[type],
            message,
            parameter1,
            (unsigned char)(type ? (unsigned char)parameter1 : ' '),
            low_part(parameter2),
            high_part(parameter2) & 0xff,
            (character*)(0x01000000 & (unsigned)parameter2 ? L"yes" : L"no"),
            (character*)(0x20000000 & (unsigned)parameter2 ? L"yes" : L"no"),
            (character*)(0x40000000 & (unsigned)parameter2 ? L"down" : L"up"),
            (character*)(0x80000000 & (unsigned)parameter2 ? L"up" : L"down")));

    release_device_context(window_handle, device_context);
    validate_rectangle(window_handle);
}


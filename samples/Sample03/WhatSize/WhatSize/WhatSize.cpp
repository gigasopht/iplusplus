// win+ -- WhatSize.cpp -- What Size is the Window?

import iplusplus;
using namespace iplusplus;

result __stdcall client(handle, unsigned, parameter, parameter);
void show_size(handle, handle, int, int, int, const character*);

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
    wclass.name = L"WhatSize";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"What size is the window?");

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
    standard::string heading;
    standard::string underline;

    int width_of_character,
        height_of_character;

    window_data()
        : heading(L"Mapping Mode                Right     Bottom"),
        underline(L"------------                -----     ------") {}

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

        handle device_context = get_device_context(window_handle);
        select_object(device_context, get_standard_object(standard_font::fixed_system));

        text_metrics<character> text_metrics_get;
        get_text_metrics(device_context, &text_metrics_get);

        data->width_of_character = text_metrics_get.average_character_width;
        data->height_of_character = text_metrics_get.height + text_metrics_get.external_leading;

        release_device_context(window_handle, device_context);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete data;
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        select_object(device_context, get_standard_object(standard_font::fixed_system));

        set_mapping_mode(device_context, unit::anisotropic);
        set_window_extent(device_context, 1, 1);
        set_viewport_extent(device_context, data->width_of_character, data->height_of_character);

        text_out(device_context, 1, 1, (const character*)data->heading, string_length((const character*)data->heading));
        text_out(device_context, 1, 2, (const character*)data->underline, string_length((const character*)data->underline));

        show_size(window_handle, device_context, 1, 3, unit::pixel, L"Pixels                  ");
        show_size(window_handle, device_context, 1, 4, unit::low_metric, L"Low Metric (.1mm)       ");
        show_size(window_handle, device_context, 1, 5, unit::high_metric, L"High Metric (.01mm)     ");
        show_size(window_handle, device_context, 1, 6, unit::low_english, L"Low English (.01 inch)  ");
        show_size(window_handle, device_context, 1, 7, unit::high_english, L"High English (.001 inch)");
        show_size(window_handle, device_context, 1, 8, unit::twips, L"TWIPS (1/1440 inch)     ");

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

void show_size(handle window_handle,
    handle device_context,
    int x_text,
    int y_text,
    int map_mode,
    const character* map_mode_string)
{
    character buffer[60];

    save_device_context(device_context);

    set_mapping_mode(device_context, map_mode);

    irectangle client;
    get_client_rectangle(window_handle, &client);
    device_points_to_logical_points(device_context, (ipoint*)&client, 2);

    restore_device_context(device_context, -1);

    text_out(device_context,
        x_text,
        y_text,
        buffer,
        print_string(buffer, L"%-20s %8d %10d",
            map_mode_string,
            client[1](0),
            client[1](1)));
}


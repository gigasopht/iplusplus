// win# -- Devicecapabilities.cpp -- Device capabilities Display Program

import iplusplus;
using namespace iplusplus;

#include "DeviceCapabilities.hpp"

enum { column1 = 30, column2 = 40 };

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
    wclass.name = L"Capabilities";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Device Capabilities");

    show_window(window, show_command);

    queue queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

struct window_data
{
    int width_of_character,
        width_of_capitals,
        height_of_character;
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

        text_metrics<character> text_metrics_device;
        get_text_metrics(device_context, &text_metrics_device);

        data->width_of_character = text_metrics_device.average_character_width;
        data->width_of_capitals = (text_metrics_device.pitch_and_family & 1 ? 3 : 2) * data->width_of_character / 2;
        data->height_of_character = text_metrics_device.height + text_metrics_device.external_leading;

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

        paint paint;

        handle device_context = begin_paint(window_handle, &paint);

        for (int i = 0; i < lines; i++)
        {
            text_out(device_context,
                data->width_of_character,
                data->height_of_character * (i + 1),
                capabilities[i].label,
                string_length(capabilities[i].label));

            text_out(device_context,
                data->width_of_character + column1 * data->width_of_capitals,
                data->height_of_character * (i + 1),
                capabilities[i].description,
                string_length(capabilities[i].description));

            set_text_alignment(device_context, text_alignment_flag::right | text_alignment_flag::top);

            character buffer[10];

            text_out(device_context,
                data->width_of_character + column1 * data->width_of_capitals + column2 * data->width_of_character,
                data->height_of_character * (i + 1),
                buffer,
                print_string(buffer, L"%5d",
                    get_device_capabilities(device_context, capabilities[i].index)));

            set_text_alignment(device_context, text_alignment_flag::left | text_alignment_flag::top);
        }
        end_paint(window_handle, &paint);
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

// win+ -- MetricsA.cpp -- System Metrics A

import iplusplus;
using namespace core;

#include "metrics.hpp"

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
    wclass.name = L"metrics";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Metrics C");

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
    int width_of_character,
        width_of_capitals,
        height_of_character,
        width_of_client,
        height_of_client,
        maximum_width,
        position_of_vertical_scroll,
        maximum_of_vertical_scroll,
        position_of_horizontal_scroll,
        maximum_of_horizontal_scroll;

    int increment_of_vertical_scroll,
        increment_of_horizontal_scroll;

    window_data()
    {
        position_of_vertical_scroll = 0;
        position_of_horizontal_scroll = 0;
    }
};

result __stdcall client(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    enum { column1 = 40, column2 = 50 };

    switch (identity)
    {
    case message::create:
    {
        window_data* data = new window_data();
        set_window_pointer(window_handle, 0, (void*)data);

        handle device_context = get_device_context(window_handle);

        text_metrics<character> text_metrics_get;

        get_text_metrics(device_context, &text_metrics_get);

        data->width_of_character = text_metrics_get.average_character_width;

        data->width_of_capitals = (text_metrics_get.pitch_and_family & 1 ? 3 : 2) * data->width_of_character / 2;

        data->height_of_character = text_metrics_get.height + text_metrics_get.external_leading;

        release_device_context(window_handle, device_context);

        data->maximum_width = column2 * data->width_of_character + column1 * data->width_of_capitals;
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

        data->width_of_client = low_part(parameter2);
        data->height_of_client = high_part(parameter2);

        data->maximum_of_vertical_scroll = maximum(0, (int)lines + 2 - data->height_of_client / data->height_of_character);
        data->position_of_vertical_scroll = minimum(data->position_of_vertical_scroll, data->maximum_of_vertical_scroll);

        set_scroll_range(window_handle, scrollbar_identity::vertical, 0, data->maximum_of_vertical_scroll, false);
        set_scroll_position(window_handle, scrollbar_identity::vertical, data->position_of_vertical_scroll, true);

        data->maximum_of_horizontal_scroll = maximum(0, 2 + (data->maximum_width - data->width_of_client) / data->width_of_character);
        data->position_of_horizontal_scroll = minimum(data->position_of_horizontal_scroll, data->maximum_of_horizontal_scroll);

        set_scroll_range(window_handle, scrollbar_identity::horizontal, 0, data->maximum_of_horizontal_scroll, false);
        set_scroll_position(window_handle, scrollbar_identity::horizontal, data->position_of_horizontal_scroll, true);
    }
    break;

    case message::vertical_scroll:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        switch (low_part(parameter1))
        {
        case scrollbar_notify::top:
            data->increment_of_vertical_scroll = -data->position_of_vertical_scroll;
            break;

        case scrollbar_notify::bottom:
            data->increment_of_vertical_scroll = data->maximum_of_vertical_scroll - data->position_of_vertical_scroll;
            break;

        case scrollbar_notify::line_up:
            data->increment_of_vertical_scroll = -1;
            break;

        case scrollbar_notify::line_down:
            data->increment_of_vertical_scroll = 1;
            break;

        case scrollbar_notify::page_up:
            data->increment_of_vertical_scroll = minimum(-1, -data->height_of_client / data->height_of_character);
            break;

        case scrollbar_notify::page_down:
            data->increment_of_vertical_scroll = maximum(1, data->height_of_client / data->height_of_character);
            break;

        case scrollbar_notify::slider_track:
            data->increment_of_vertical_scroll = high_part(parameter1) - data->position_of_vertical_scroll;
            break;

        default:
            data->increment_of_vertical_scroll = 0;
            break;
        }

        data->increment_of_vertical_scroll = maximum(-data->position_of_vertical_scroll,
            minimum(data->increment_of_vertical_scroll, data->maximum_of_vertical_scroll - data->position_of_vertical_scroll));

        if (data->increment_of_vertical_scroll != 0)
        {
            data->position_of_vertical_scroll += data->increment_of_vertical_scroll;
            scroll_window(window_handle, 0, -data->height_of_character * data->increment_of_vertical_scroll, (const irectangle*)null, (const irectangle*)null);
            set_scroll_position(window_handle, scrollbar_identity::vertical, data->position_of_vertical_scroll, true);
            update_window(window_handle);
        }

    }
    break;

    case message::horizontal_scroll:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        switch (low_part(parameter1))
        {
        case scrollbar_notify::line_up:
            data->increment_of_horizontal_scroll = -1;
            break;

        case scrollbar_notify::line_down:
            data->increment_of_horizontal_scroll = 1;
            break;

        case scrollbar_notify::page_up:
            data->increment_of_horizontal_scroll = -8;
            break;

        case scrollbar_notify::page_down:
            data->increment_of_horizontal_scroll = 8;
            break;

        case scrollbar_notify::slider_position:
            data->increment_of_horizontal_scroll = high_part(parameter1) - data->position_of_horizontal_scroll;
            break;

        case scrollbar_notify::slider_track:
            data->increment_of_horizontal_scroll = high_part(parameter1) - data->position_of_horizontal_scroll;
            break;

        default:
            data->increment_of_horizontal_scroll = 0;
        }

        data->increment_of_horizontal_scroll = maximum(-data->position_of_horizontal_scroll,
            minimum(data->increment_of_horizontal_scroll, data->maximum_of_horizontal_scroll - data->position_of_horizontal_scroll));

        if (data->increment_of_horizontal_scroll != 0)
        {
            data->position_of_horizontal_scroll += data->increment_of_horizontal_scroll;
            scroll_window(window_handle, -data->width_of_character * data->increment_of_horizontal_scroll, 0, (const irectangle*)null, (const irectangle*)null);
            set_scroll_position(window_handle, scrollbar_identity::horizontal, data->position_of_horizontal_scroll, true);
        }
    }
    break;

    case message::close:
        post_quit_message();
        break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        int paint_begin = maximum(0, data->position_of_vertical_scroll + paint_structure.bounds[0](1) / data->height_of_character - 1);
        int paint_end = minimum((int)lines, data->position_of_vertical_scroll + paint_structure.bounds[1](1) / data->height_of_character);

        for (int i = paint_begin; i < paint_end; i++)
        {
            int x = data->width_of_character * (1 - data->position_of_horizontal_scroll);
            int y = data->height_of_character * (1 - data->position_of_vertical_scroll + i);

            text_out(device_context,
                x,
                y,
                metrics[i].title,
                string_length(metrics[i].title));

            text_out(device_context,
                x + column1 * data->width_of_capitals,
                y,
                metrics[i].description,
                string_length(metrics[i].description));

            set_text_alignment(device_context, text_alignment_flag::right | text_alignment_flag::top);

            character buffer[32];

            text_out(device_context,
                x + column1 * data->width_of_capitals + column2 * data->width_of_character,
                y,
                buffer,
                print_string_w(buffer, L"%5d",
                    get_system_metrics(metrics[i].index)));

            set_text_alignment(device_context, text_alignment_flag::left | text_alignment_flag::top);
        }

        end_paint(window_handle, &paint_structure);
    }
    break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}
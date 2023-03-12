// win+ -- MetricsB.cpp -- System Metrics B

import iplusplus;
using namespace core;

struct metric_entry
{
    int index;
    const character* title;
    const character* description;
};

metric_entry metrics[] =
{
 system_metric::screen_width,                        L"system_metric::screen_width",                     L"Screen width in pixels",
 system_metric::screen_height,                       L"system_metric::screen_height",                    L"Screen height in pixels",
 system_metric::vertical_scroll_width,               L"system_metric::vertical_scroll_width",            L"Vertical scroll arrow width",
 system_metric::horizontal_scroll_height,            L"system_metric::horizontal_scroll_height",         L"Horizontal scroll arrow height",
 system_metric::caption_height,                      L"system_metric::caption_height",                   L"Caption bar height",
 system_metric::border_width,                        L"system_metric::border_width",                     L"Window border width",
 system_metric::border_height,                       L"system_metric::border_height",                    L"Window border height",
 system_metric::fixed_frame_width,                   L"system_metric::fixed_frame_width",                L"Dialog window frame width",
 system_metric::fixed_frame_height,                  L"system_metric::fixed_frame_height",               L"Dialog window frame height",
 system_metric::vertical_slider_height,              L"system_metric::vertical_slider_height",           L"Vertical scroll thumb height",
 system_metric::horizontal_slider_width,             L"system_metric::horizontal_slider_width",          L"Horizontal scroll thumb width",
 system_metric::icon_width,                          L"system_metric::icon_width",                       L"Icon width",
 system_metric::icon_height,                         L"system_metric::icon_height",                      L"Icon height",
 system_metric::cursor_width,                        L"system_metric::cursor_width",                     L"Cursor width",
 system_metric::cursor_height,                       L"system_metric::cursor_height",                    L"Cursor height",
 system_metric::menu_height,                         L"system_metric::menu_height",                      L"Menu bar height",
 system_metric::full_screen_width,                   L"system_metric::full_screen_width",                L"Full screen client area width",
 system_metric::full_screen_height,                  L"system_metric::full_screen_height",               L"Full screen client area height",
 system_metric::kanji_window_height,                 L"system_metric::kanji_window_height",              L"Kanji window height",
 system_metric::mouse_present,                       L"system_metric::mouse_present",                    L"Mouse present flag",
 system_metric::vertical_scroll_arrow_height,        L"system_metric::vertical_scroll_arrow_height",     L"Vertical scroll arrow height",
 system_metric::horizontal_scroll_arrow_width,       L"system_metric::horizontal_scroll_arrow_width",    L"Horizontal scroll arrow width",
 system_metric::debug,                               L"system_metric::debug",                            L"Debug version flag",
 system_metric::swap_button,                         L"system_metric::swap_button",                      L"Mouse buttons swapped flag",
 system_metric::reserved1,                           L"system_metric::reserved1",                        L"Reserved",
 system_metric::reserved2,                           L"system_metric::reserved2",                        L"Reserved",
 system_metric::reserved3,                           L"system_metric::reserved3",                        L"Reserved",
 system_metric::reserved4,                           L"system_metric::reserved4",                        L"Reserved",
 system_metric::minimum_width,                       L"system_metric::minimum_width",                    L"Minimum window width",
 system_metric::minimum_height,                      L"system_metric::minimum_height",                   L"Minimum window height",
 system_metric::button_width,                        L"system_metric::button_width",                     L"Minimize/Maximize icon width",
 system_metric::button_height,                       L"system_metric::button_height",                    L"Minimize/Maximize icon height",
 system_metric::size_frame_width,                    L"system_metric::size_frame_width",                 L"Window frame width",
 system_metric::size_frame_height,                   L"system_metric::size_frame_height",                L"Window frame height",
 system_metric::minimum_track_width,                 L"system_metric::minimum_track_width",              L"Minimum window tracking width",
 system_metric::minimum_track_height,                L"system_metric::minimum_track_height",             L"Minimum window tracking height",
 system_metric::double_click_width,                  L"system_metric::double_click_width",               L"Double click x tolerance",
 system_metric::double_click_height,                 L"system_metric::double_click_height",              L"Double click y tolerance",
 system_metric::icon_spacing_width,                  L"system_metric::icon_spacing_width",               L"Horizontal icon spacing",
 system_metric::icon_spacing_height,                 L"system_metric::icon_spacing_height",              L"Vertical icon spacing",
 system_metric::menu_drop_alignment,                 L"system_metric::menu_drop_alignment",              L"Left or right menu drop",
 system_metric::pen_windows,                         L"system_metric::pen_windows",                      L"Pen extensions installed",
 system_metric::double_byte_enabled,                 L"system_metric::double_byte_enabled",              L"Double-Byte Char set enabled",
 system_metric::number_mouse_buttons,                L"system_metric::number_mouse_buttons",             L"Number of mouse buttons",
 system_metric::sounds_show,                         L"system_metric::sounds_show",                      L"Present sounds visually",
};

enum { lines = sizeof(metrics) / sizeof(metrics[0]) };

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
    wclass.brush = get_standard_object(standard_brush::white);
    wclass.name = L"metrics";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Metrics B");

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
        height_of_character,
        width_of_capitals,
        position_of_vertical_scroll,
        height_of_client;

    window_data()
    {
        position_of_vertical_scroll = 0;
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

        handle device_context = get_device_context(window_handle);

        text_metrics<character> text_metrics_get;

        get_text_metrics(device_context, &text_metrics_get);

        data->width_of_character = text_metrics_get.average_character_width;

        data->width_of_capitals = (text_metrics_get.pitch_and_family & 1 ? 3 : 2) * data->width_of_character / 2;

        data->height_of_character = text_metrics_get.height + text_metrics_get.external_leading;

        release_device_context(window_handle, device_context);

        set_scroll_range(window_handle, scrollbar_identity::vertical, 0, lines, false);
        set_scroll_position(window_handle, scrollbar_identity::vertical, data->position_of_vertical_scroll, true);

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
        data->height_of_client = high_part(parameter2);
    }
    break;

    case message::vertical_scroll:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        switch (low_part(parameter1))
        {
        case scrollbar_notify::line_up:
            data->position_of_vertical_scroll -= 1;
            break;

        case scrollbar_notify::line_down:
            data->position_of_vertical_scroll += 1;
            break;

        case scrollbar_notify::page_up:
            data->position_of_vertical_scroll -= data->height_of_client / data->height_of_character;
            break;

        case scrollbar_notify::page_down:
            data->position_of_vertical_scroll += data->height_of_client / data->height_of_character;
            break;

        case scrollbar_notify::slider_position:
        case scrollbar_notify::slider_track:
            data->position_of_vertical_scroll = high_part(parameter1);
            break;
        }

        data->position_of_vertical_scroll = maximum(0, minimum(data->position_of_vertical_scroll, (int)lines));

        if (data->position_of_vertical_scroll != get_scroll_position(window_handle, scrollbar_identity::vertical))
        {
            set_scroll_position(window_handle, scrollbar_identity::vertical, data->position_of_vertical_scroll, true);
            invalidate_rectangle(window_handle, (const irectangle*)null, true);
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

        enum { column1 = 40, column2 = 50 };

        for (int i = 0; i < lines; i++)
        {
            int y = data->height_of_character * (1 - data->position_of_vertical_scroll + i);

            text_out(device_context,
                data->width_of_character,
                y,
                metrics[i].title,
                string_length(metrics[i].title));

            text_out(device_context,
                data->width_of_character + column1 * data->width_of_capitals,
                y,
                metrics[i].description,
                string_length(metrics[i].description));

            set_text_alignment(device_context, text_alignment_flag::right | text_alignment_flag::top);

            character buffer[32];

            text_out(device_context,
                data->width_of_character + column1 * data->width_of_capitals + column2 * data->width_of_character,
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

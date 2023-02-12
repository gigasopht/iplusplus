// Win+-- Digital.cpp -- Digital Clock

import iplusplus;
using namespace core;

result __stdcall client(handle, unsigned, parameter, parameter);

enum { identity_of_timer = 1, wait_period = 1000 };

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
    wclass.name = L"Digital";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Clock");

    set_timer(window, identity_of_timer, wait_period);

    show_window(window, show_command);

    queue_message queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

void format_date_time(character* Buffer)
{
    character date[30];
    character time[30];

    get_date_format(locale_user_default, 0, (const system_time*)null, L"dddd MMMM d  ", date, sizeof(date));
    get_time_format(locale_user_default, 0, (const system_time*)null, (const character*)null, time, sizeof(time));

    copy_string(Buffer, date);
    concatenate_strings(Buffer, time);
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
        handle device_context = create_informational_device_context(L"DISPLAY", (const character*)null, (const character*)null, (const device_mode<character>*)null);

        character date_time_string[60];
        format_date_time(date_time_string);

        idimensions extent;
        get_text_extent(device_context, date_time_string, string_length(date_time_string), &extent);

        delete_device_context(device_context);

        extent = (extent * 110) / 100;

        int width = extent(0) + 2 * get_system_metrics(system_metric::fixed_frame_width);

        int height = extent(1) + get_system_metrics(system_metric::caption_height)
            + 2 * get_system_metrics(system_metric::fixed_frame_height);

        height = (height * 150) / 100;

        int x = get_system_metrics(system_metric::screen_width) - width;

        set_window_position(window_handle,
            0,
            x,
            0,
            width,
            height,
            place::no_zorder | place::no_redraw);
    }
    break;

    case message::timer:
        invalidate_rectangle(window_handle);
        break;

    case message::paint:
    {
        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        irectangle client_rectangle;
        get_client_rectangle(window_handle, &client_rectangle);

        character date_time_string[60];
        format_date_time(date_time_string);

        draw_text(device_context,
            date_time_string,
            -1,
            &client_rectangle,
            draw_text_format::single_line | draw_text_format::center | draw_text_format::vertical_center);

        end_paint(window_handle, &paint_structure);
    }
    break;

    case message::destroy:
        cancel_timer(window_handle, identity_of_timer);
        break;

    case message::close:
        post_quit_message();
        break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

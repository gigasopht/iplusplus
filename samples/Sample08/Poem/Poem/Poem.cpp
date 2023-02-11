// Win+ -- Poem.cpp -- Demonstrates User-Defined Resources

import iplusplus;
using namespace iplusplus;

#include "Poem.h"

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
    wclass.name = L"Poem";

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
    handle resource_handle;
    handle scroll_handle;

    int scroll_amount,
        width_of_character,
        height_of_character,
        height_of_client,
        number_of_lines,
        x_scroll;
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
        data->height_of_character = text_metrics_get.height + text_metrics_get.external_leading;

        release_device_context(window_handle, device_context);

        data->x_scroll = get_system_metrics(system_metric::vertical_scroll_width);

        data->scroll_handle = create_window(L"scrollbar",
            L"",
            style::child | style::visible | scrollbar_style::vertical,
            use_default,
            use_default,
            use_default,
            use_default,
            window_handle,
            (handle)1);

        handle module_handle = get_module_handle<character>();

        data->resource_handle = load_resource(module_handle,
            find_resource(module_handle,
                (const character*)PoemIdentity,
                (const character*)PoePoem));

        char* text = (char*)lock_resource(data->resource_handle);

        data->number_of_lines = 0;

        while (*text != '\\' && *text != '\0')
        {
            if (*text == '\n') data->number_of_lines++; text++;
        }

        set_scroll_range(data->scroll_handle, scrollbar_identity::control, 0, data->number_of_lines, false);
        set_scroll_position(data->scroll_handle, scrollbar_identity::control, 0, false);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        free_resource(data->resource_handle);
        delete data;
    }
    break;

    case message::size:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        data->height_of_client = high_part(parameter2);

        move_window(data->scroll_handle,
            low_part(parameter2) - data->x_scroll,
            0,
            data->x_scroll,
            data->height_of_client,
            true);
        set_focus(window_handle);
    }
    break;

    case message::set_focus:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        set_focus(data->scroll_handle);
    }
    break;

    case message::vertical_scroll:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        switch ((short)parameter1)
        {
        case scrollbar_notify::top:       data->scroll_amount = 0; break;
        case scrollbar_notify::bottom:    data->scroll_amount = data->number_of_lines; break;
        case scrollbar_notify::line_up:    data->scroll_amount -= 1;  break;
        case scrollbar_notify::line_down:  data->scroll_amount += 1;  break;

        case scrollbar_notify::page_up:
            data->scroll_amount -= data->height_of_client / data->height_of_character;
            break;

        case scrollbar_notify::page_down:
            data->scroll_amount += data->height_of_client / data->height_of_character;
            break;

        case scrollbar_notify::slider_position:
        case scrollbar_notify::slider_track:
            data->scroll_amount = high_part(parameter1);
            break;
        }

        data->scroll_amount = maximum(0, minimum(data->scroll_amount, data->number_of_lines));

        if (data->scroll_amount != get_scroll_position(data->scroll_handle, scrollbar_identity::control))
        {
            set_scroll_position(data->scroll_handle, scrollbar_identity::control, data->scroll_amount, true);
            invalidate_rectangle(window_handle, (const irectangle*)null, true);
        }

    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        char* text = (char*)lock_resource(data->resource_handle);

        irectangle bounds;
        get_client_rectangle(window_handle, &bounds);

        bounds[0](0) += data->width_of_character;
        bounds[0](1) += data->height_of_character * (1 - data->scroll_amount);

        draw_text(device_context,
            text,
            -1,
            &bounds,
            draw_text_format::external_leading);

        end_paint(window_handle, &paint_structure);
    }
    break;


    case message::close:
    {
        character exit[30];
        character application[30];
        load_string(0, StringExit, exit, 30);
        load_string(0, StringApplication, application, 30);
        if (message_box(window_handle,
            exit,
            application,
            message_box_style::yes_no) == item_identity::yes)
            post_quit_message();
    }
    break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }

    return 0;
}

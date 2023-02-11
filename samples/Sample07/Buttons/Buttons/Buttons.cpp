// Win+ -- Buttons.cpp -- Button Viewing Program

import iplusplus;
using namespace iplusplus;

#include "Buttons.hpp"

const character title[] = L"Buttons";
const character name[] = L"Buttons";

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
    wclass.name = L"Buttons";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Buttons");

    show_window(window, show_command);

    queue queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

result _stdcall client(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (identity)
    {
    case message::create:
    {
        handle device_context = get_device_context(window_handle);
        select_object(device_context, get_standard_object(standard_font::fixed_system));

        text_metrics<character> text_metrics_get;
        get_text_metrics(device_context, &text_metrics_get);

        int width_of_character = text_metrics_get.average_character_width;
        int height_of_character = text_metrics_get.height + text_metrics_get.external_leading;

        release_device_context(window_handle, device_context);

        handle button_handles[number_of_buttons];

        for (int i = 0; i < number_of_buttons; i++)
            button_handles[i] = create_window(L"Button",
                button_array[i].text,
                style::child | style::visible | button_array[i].style,
                width_of_character,
                height_of_character * (1 + 2 * i),
                button_width * width_of_character,
                7 * height_of_character / 4,
                window_handle,
                (handle)i);

        set_window_position(window_handle, 0, 0, 0,
            (button_width + 3) * width_of_character,
            height_of_character * (4 + 2 * number_of_buttons),
            place::no_move | place::no_zorder);

    }
    break;

    case message::command:
        message_box(window_handle, L"Button Selected", L"Buttons", message_box_style::ok);
        break;

    case message::draw_item:
    {
        draw_item* item = (draw_item*)parameter2;

        if (((item->action) & owner_draw_action::select) &&
            ((item->state) & owner_draw_state::selected))
            fill_rectangle(item->device,
                &(item->bounds),
                get_standard_object(standard_brush::light_gray));
        else
            fill_rectangle(item->device,
                &(item->bounds),
                get_standard_object(standard_brush::white));

        frame_rectangle(item->device,
            &(item->bounds),
            get_standard_object(standard_brush::black));

        draw_text(item->device,
            L"Owner Draw Button",
            -1,
            &(item->bounds),
            draw_text_format::single_line | draw_text_format::center | draw_text_format::vertical_center);
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

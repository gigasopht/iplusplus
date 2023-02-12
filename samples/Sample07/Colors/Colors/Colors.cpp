// Win# -- colors.cpp -- Colors Using Scroll Bars

import iplusplus;
using namespace core;

import std.core;
using namespace std;

result __stdcall client(handle, unsigned, parameter, parameter);
result __stdcall scroll_procedure(handle, unsigned, parameter, parameter);

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
    wclass.name = L"Colors";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Colors");

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
    icolor primary_colors[3];
    handle brush_array[3], display_brush;
    int height_of_character;
    irectangle color_rectangle;

    procedure scroll_procedures[3];

    handle scroll_array[3],
        label_array[3],
        value_array[3],
        window_rectangle;

    int color_array[3], focus_index;

    window_data()
    {
        primary_colors[0] = red_green_blue(255, 0, 0);
        primary_colors[1] = red_green_blue(0, 255, 0);
        primary_colors[2] = red_green_blue(0, 0, 255);
        focus_index = 0;
        color_array[0] = 0;
        color_array[1] = 0;
        color_array[2] = 0;
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

        data->window_rectangle = create_window(L"Static",
            L"",
            style::child | style::visible | display_style::rectangle_white,
            use_default,
            use_default,
            use_default,
            use_default,
            window_handle,
            (handle)9);

        character* color_labels[] = { (character*)L"red", (character*)L"green", (character*)L"blue" };

        for (int i = 0; i < 3; i++)
        {
            data->scroll_array[i] = create_window(L"ScrollBar",
                L"",
                style::child | style::visible | style::tabstop | scrollbar_style::vertical,
                use_default,
                use_default,
                use_default,
                use_default,
                window_handle,
                (handle)i);

            data->label_array[i] = create_window(L"Static",
                L"",
                style::child | style::visible | display_style::center,
                use_default,
                use_default,
                use_default,
                use_default,
                window_handle,
                (handle)(i + 3));

            set_window_text(data->label_array[i], color_labels[i]);

            data->value_array[i] = create_window(L"Static",
                L"",
                style::child | style::visible | display_style::center,
                use_default,
                use_default,
                use_default,
                use_default,
                window_handle,
                (handle)(i + 6));

            set_window_text(data->value_array[i], L"0");

            data->scroll_procedures[i] = (procedure)set_window_pointer(data->scroll_array[i],
                offset::window_procedure,
                scroll_procedure);

            set_scroll_range(data->scroll_array[i], scrollbar_identity::control, 0, 255, false);
            set_scroll_position(data->scroll_array[i], scrollbar_identity::control, 0, false);
        }

        for (int i = 0; i < 3; i++)
            data->brush_array[i] = create_solid_brush(data->primary_colors[i]);

        data->display_brush = create_solid_brush(get_system_color(system_color::button_highlight));

        data->height_of_character = high_part(get_dialog_base_units());
    
        delete_object((handle)set_class_pointer(window_handle,
            class_offset::background_brush,
            create_solid_brush(red_green_blue(data->color_array[0],
                data->color_array[1],
                data->color_array[2]))));
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        delete_object(set_class_pointer(window_handle,
            class_offset::background_brush,
            get_standard_object(standard_brush::white)));

        for (int i = 0; i < 3; delete_object(data->brush_array[i++]));

        delete_object(data->display_brush);

        delete data;
    }
    break;

    case message::size:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        int width_of_client = low_part(parameter2);
        int height_of_client = high_part(parameter2);

        data->color_rectangle = irectangle(width_of_client / 2,
            0,
            width_of_client,
            height_of_client);

        move_window(data->window_rectangle,
            0,
            0,
            width_of_client / 2,
            height_of_client,
            true);

        for (int i = 0; i < 3; i++)
        {
            move_window(data->scroll_array[i],
                (2 * i + 1) * width_of_client / 14,
                2 * data->height_of_character,
                width_of_client / 14,
                height_of_client - 4 * data->height_of_character,
                true);

            move_window(data->label_array[i],
                (4 * i + 1) * width_of_client / 28,
                data->height_of_character / 2,
                width_of_client / 7,
                data->height_of_character,
                true);

            move_window(data->value_array[i],
                (4 * i + 1) * width_of_client / 28,
                height_of_client - 3 * data->height_of_character / 2,
                width_of_client / 7,
                data->height_of_character,
                true);
        }
        set_focus(window_handle);
    }
    break;

    case message::set_focus:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        set_focus(data->scroll_array[data->focus_index]);
    }
    break;

    case message::vertical_scroll:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        int i = get_window_integer((handle)parameter2, offset::identity);

        switch (low_part(parameter1))
        {
        case scrollbar_notify::page_down:
            data->color_array[i] += 15;
            // fall through
        case scrollbar_notify::line_down:
            data->color_array[i] = minimum(255, data->color_array[i] + 1);
            break;

        case scrollbar_notify::page_up:
            data->color_array[i] -= 15;
            // fall through
        case scrollbar_notify::line_up:
            data->color_array[i] = maximum(0, data->color_array[i] - 1);
            break;

        case scrollbar_notify::top:
            data->color_array[i] = 0;
            break;

        case scrollbar_notify::bottom:
            data->color_array[i] = 255;
            break;

        case scrollbar_notify::slider_position:
        case scrollbar_notify::slider_track:
            data->color_array[i] = high_part(parameter1);
            break;

        default: break;
        }

        set_scroll_position(data->scroll_array[i],
            scrollbar_identity::control,
            data->color_array[i],
            true);

        character number_string[20];
        integer_to_string(data->color_array[i], number_string);

        set_window_text(data->value_array[i], number_string);

        delete_object((handle)set_class_pointer(window_handle,
            class_offset::background_brush,
            create_solid_brush(red_green_blue(data->color_array[0],
                data->color_array[1],
                data->color_array[2]))));

        invalidate_rectangle(window_handle, &data->color_rectangle, true);
    }
    break;

    case message::color_scrollbar:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        int i = get_window_integer((handle)parameter2, offset::identity);
        return (result)data->brush_array[i];
    }

    case message::color_display:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        int i = get_window_integer((handle)parameter2, offset::identity);

        if (i >= 3 && i <= 8)    // static text controls
        {
            set_text_color((handle)parameter1, data->primary_colors[i % 3]);
            set_background_color((handle)parameter1, get_system_color(system_color::button_highlight));
            return (result)data->display_brush;
        }
    }
    break;

    case message::system_color_change:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete_object(data->display_brush);
        data->display_brush = create_solid_brush(get_system_color(system_color::button_highlight));
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

result __stdcall scroll_procedure(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    int i = get_window_integer(window_handle, offset::identity);

    window_data* data = (window_data*)get_window_pointer(get_parent(window_handle), 0);

    switch (identity)
    {
    case message::key_down:
        if ((int)parameter1 == virtual_key::tab)
            set_focus(data->scroll_array[(i + (get_key_state(virtual_key::shift) < 0 ? 2 : 1)) % 3]);
        break;

    case message::set_focus:
        data->focus_index = i;
        break;

    default: break;
    }

    return call_window_procedure(data->scroll_procedures[i],
        window_handle,
        identity,
        parameter1,
        parameter2);
}

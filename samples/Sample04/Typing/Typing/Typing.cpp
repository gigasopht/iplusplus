// Win# -- Typing.cpp -- Typing Program

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
    wclass.name = L"Typing";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Typing");

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
    character* character_buffer;

    int width_of_character,
        height_of_character,
        width_of_client,
        height_of_client,
        width_ou_buffer,
        height_of_buffer,
        x_caret,
        y_caret;

    window_data()
    {
        character_buffer = (character*)null;
    }
};

#define buffer(x,y) *(data->character_buffer + y * data->width_ou_buffer + x)

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

        data->width_ou_buffer = maximum(1, data->width_of_client / data->width_of_character);
        data->height_of_buffer = maximum(1, data->height_of_client / data->height_of_character);

        if (data->character_buffer)
            delete[] data->character_buffer;

        data->character_buffer = new character[data->width_ou_buffer * data->height_of_buffer];

        for (int y = 0; y < data->height_of_buffer; y++)
            for (int x = 0; x < data->width_ou_buffer; x++)
                buffer(x, y) = ' ';

        data->x_caret = 0;
        data->y_caret = 0;

        if (window_handle == get_focus())
            set_caret_position(data->x_caret * data->width_of_character,
                data->y_caret * data->height_of_character);
    }
    break;

    case message::set_focus:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        create_caret(window_handle,
            (handle)null,
            data->width_of_character,
            data->height_of_character);

        set_caret_position(data->x_caret * data->width_of_character,
            data->y_caret * data->height_of_character);

        show_caret(window_handle);
        return 0;
    }

    case message::remove_focus:
        hide_caret(window_handle);
        destroy_caret();
        return 0;

    case message::key_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        switch ((int)parameter1)
        {
        case virtual_key::home:
            data->x_caret = 0;
            break;

        case virtual_key::end:
            data->x_caret = data->width_ou_buffer - 1;
            break;

        case virtual_key::prior:
            data->y_caret = 0;
            break;

        case virtual_key::next:
            data->y_caret = data->height_of_buffer - 1;
            break;

        case virtual_key::left:
            data->x_caret = maximum(data->x_caret - 1, 0);
            break;

        case virtual_key::right:
            data->x_caret = minimum(data->x_caret + 1, data->width_ou_buffer - 1);
            break;

        case virtual_key::up:
            data->y_caret = maximum(data->y_caret - 1, 0);
            break;

        case virtual_key::down:
            data->y_caret = minimum(data->y_caret + 1, data->height_of_buffer - 1);
            break;

        case virtual_key::_delete:
        {
            for (int x = data->x_caret; x < data->width_ou_buffer - 1; x++)
                buffer(x, data->y_caret) = buffer(x + 1, data->y_caret);

            buffer(data->width_ou_buffer - 1, data->y_caret) = ' ';

            hide_caret(window_handle);

            handle device_context = get_device_context(window_handle);

            select_object(device_context, get_standard_object(standard_font::fixed_system));

            text_out(device_context,
                data->x_caret * data->width_of_character,
                data->y_caret * data->height_of_character,
                &buffer(data->x_caret, data->y_caret),
                data->width_ou_buffer - data->x_caret);

            show_caret(window_handle);
            release_device_context(window_handle, device_context);
        }
        }

        set_caret_position(data->x_caret * data->width_of_character,
            data->y_caret * data->height_of_character);
    }
    break;

    case message::character:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        for (int i = 0; i < low_part(parameter2); i++)
        {
            switch ((int)parameter1)
            {
            case '\b': // backspace
                if (data->x_caret > 0)
                {
                    data->x_caret--;
                    send_message(window_handle, message::key_down, (parameter)virtual_key::_delete, (parameter)1l);
                }
                break;

            case '\t': // tab
                do
                {
                    send_message(window_handle, message::character, (parameter)' ', (parameter)1l);
                } while (data->x_caret % 8 != 0);
                break;

            case '\n':  // Line feed
                if (++data->y_caret == data->height_of_buffer)
                    data->y_caret = 0;
                break;

            case '\r':   // carriage return
                data->x_caret = 0;
                if (++data->y_caret == data->height_of_buffer) data->y_caret = 0;
                break;

            case '\x1b': // Escape
            {
                for (int y = 0; y < data->height_of_buffer; y++)
                    for (int x = 0; x < data->width_ou_buffer; x++)
                        buffer(x, y) = ' ';

                data->x_caret = 0; data->y_caret = 0;

                invalidate_rectangle(window_handle, (const irectangle*)null, false);
            }
            break;

            default: // Character codes
            {
                buffer(data->x_caret, data->y_caret) = (character)parameter1;

                hide_caret(window_handle)
                    ;
                handle device_context = get_device_context(window_handle);

                select_object(device_context, get_standard_object(standard_font::fixed_system));

                text_out(device_context,
                    data->x_caret * data->width_of_character,
                    data->y_caret * data->height_of_character,
                    &buffer(data->x_caret, data->y_caret), 1);

                show_caret(window_handle);
                release_device_context(window_handle, device_context);

                if (++data->x_caret == data->width_ou_buffer)
                {
                    data->x_caret = 0;
                    if (++data->y_caret == data->height_of_buffer) data->y_caret = 0;
                }
            }
            break;
            }
        }

        set_caret_position(data->x_caret * data->width_of_character,
            data->y_caret * data->height_of_character);
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;

        handle device_context = begin_paint(window_handle, &paint_structure);

        select_object(device_context, get_standard_object(standard_font::fixed_system));

        for (int y = 0; y < data->height_of_buffer; y++)
            text_out(device_context,
                0,
                y * data->height_of_character,
                &buffer(0, y),
                data->width_ou_buffer);

        end_paint(window_handle, &paint_structure);
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

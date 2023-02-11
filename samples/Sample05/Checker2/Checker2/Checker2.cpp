// Win+ -- Checker2.cpp -- Mouse Correlation Demonstration Program #2

import iplusplus;
using namespace iplusplus;

result __stdcall client(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2);

enum { divisions = 5 };

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
    wclass.name = L"Mouse";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Mouse Correlation - Keyboard Interface");

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
    int state_array[divisions][divisions];
    int width_of_block, height_of_block;
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
        data->width_of_block = low_part(parameter2) / divisions;
        data->height_of_block = high_part(parameter2) / divisions;
    }
    break;

    case message::set_focus:
        show_cursor(true);
        break;

    case message::remove_focus:
        show_cursor(false);
        break;

    case message::key_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        ipoint cursor_position;
        get_cursor_position(&cursor_position);
        screen_to_client(window_handle, &cursor_position);

        int x = maximum(0, minimum((int)(divisions - 1), cursor_position(0) / data->width_of_block));
        int y = maximum(0, minimum((int)(divisions - 1), cursor_position(1) / data->height_of_block));

        switch ((int)parameter1)
        {
        case virtual_key::up:     y--;                   break;
        case virtual_key::down:   y++;                   break;
        case virtual_key::left:   x--;                   break;
        case virtual_key::right:  x++;                   break;
        case virtual_key::home:   x = y = 0;             break;
        case virtual_key::end:    x = y = divisions - 1;   break;

        case virtual_key::_return:
        case virtual_key::space:
            send_message(window_handle,
                message::left_button_down,
                (parameter)mouse_state::left_button,
                (parameter)make_integer(x * data->width_of_block, y * data->height_of_block));
            break;
        }

        x = (x + divisions) % divisions;
        y = (y + divisions) % divisions;

        cursor_position(0) = x * data->width_of_block + data->width_of_block / 2;
        cursor_position(1) = y * data->height_of_block + data->height_of_block / 2;

        client_to_screen(window_handle, &cursor_position);
        set_cursor_position(cursor_position(0), cursor_position(1));
    }
    break;

    case message::left_button_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        int x = low_part(parameter2) / data->width_of_block;
        int y = high_part(parameter2) / data->height_of_block;

        if (x < divisions && y < divisions)
        {
            data->state_array[x][y] ^= 1;

            irectangle rectangle(x * data->width_of_block,
                y * data->height_of_block,
                (x + 1) * data->width_of_block,
                (y + 1) * data->height_of_block);

            invalidate_rectangle(window_handle, &rectangle, false);
        }
        else
            message_beep(message_box_style::ok);
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        for (int x = 0; x < divisions; x++)
            for (int y = 0; y < divisions; y++)
            {
                draw_rectangle(device_context,
                    x * data->width_of_block,
                    y * data->height_of_block,
                    (x + 1) * data->width_of_block,
                    (y + 1) * data->height_of_block);

                if (data->state_array[x][y])
                {
                    move_to(device_context, x * data->width_of_block, y * data->height_of_block);
                    draw_line_to(device_context, (x + 1) * data->width_of_block, (y + 1) * data->height_of_block);
                    move_to(device_context, x * data->width_of_block, (y + 1) * data->height_of_block);
                    draw_line_to(device_context, (x + 1) * data->width_of_block, y * data->height_of_block);
                }
            }

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

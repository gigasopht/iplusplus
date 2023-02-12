// Win# -- Checker3.cpp -- Mouse Correlation Demonstration Program No. 3

import iplusplus;
using namespace core;

enum { divisions = 5 };

character child_class[] = L"Child Class";

result __stdcall client(handle, unsigned, parameter, parameter);
result __stdcall child(handle, unsigned, parameter, parameter);

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

    window_class<character> wclass_child;

    wclass_child.style = class_style::horizontal_redraw | class_style::vertical_redraw;
    wclass_child.procedure = child;
    wclass_child.extra = 0;
    wclass_child.window = sizeof(void*);
    wclass_child.module = module_handle;
    wclass_child.icon = load_icon(0, (const character*)icon_identity::application);
    wclass_child.cursor = load_cursor(0, (const character*)cursor_identity::arrow);
    wclass_child.brush = (handle)get_standard_object(standard_brush::white);
    wclass_child.name = child_class;

    atom atom_name_child = register_class(&wclass_child);

    handle window = create_window(atom_name, L"Mouse Correlation - Child Windows");

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
    handle child_array[divisions][divisions];
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

        for (int x = 0; x < divisions; x++)
            for (int y = 0; y < divisions; y++)
                data->child_array[x][y] = create_window(child_class,
                    (const character*)"Child",
                    (unsigned)(style::child | style::visible),
                    use_default,
                    use_default,
                    use_default,
                    use_default,
                    window_handle,
                    (handle)(y << 8 | x));

        return (result)true;
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

        int width_of_block = low_part(parameter2) / divisions;
        int height_of_block = high_part(parameter2) / divisions;

        for (int x = 0; x < divisions; x++)
            for (int y = 0; y < divisions; y++)
                move_window(data->child_array[x][y],
                    x * width_of_block,
                    y * height_of_block,
                    width_of_block,
                    height_of_block,
                    true);
    }
    break;

    case message::left_button_down:
        message_beep(message_box_style::ok);
        break;

    case message::close:
        post_quit_message();
        break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }

    return 0;
}

result __stdcall child(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (identity)
    {
    case message::create:
        set_window_part(window_handle, 0, 0); // on/off flag
        break;

    case message::left_button_down:
        set_window_part(window_handle, 0, 1 ^ get_window_part(window_handle, 0));
        invalidate_rectangle(window_handle, (const irectangle*)null, false);
        break;

    case message::paint:
    {
        paint paint_struct;
        handle device_context = begin_paint(window_handle, &paint_struct);

        irectangle client;
        get_client_rectangle(window_handle, &client);

        draw_rectangle(device_context, 0, 0, client[1](0), client[1](1));

        if (get_window_part(window_handle, 0))
        {
            move_to(device_context, 0, 0);
            draw_line_to(device_context, client[1](0), client[1](1));
            move_to(device_context, 0, client[1](1));
            draw_line_to(device_context, client[1](0), 0);
        }

        end_paint(window_handle, &paint_struct);
    }
    break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

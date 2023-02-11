// Win+ -- BlockOut1.cpp -- Mouse Button Demonstration Program - No Capture

import iplusplus;
using namespace iplusplus;

result __stdcall client(handle, unsigned, parameter, parameter);
void draw_box_outline(handle, ipoint, ipoint);

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

    handle window = create_window(atom_name, L"Mouse Button Demonstration");

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
    bool blocking, valid_box;
    ipoint start, end, box_start, box_end;
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

    case message::left_button_down:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        data->start(0) = data->end(0) = low_part(parameter2);
        data->start(1) = data->end(1) = high_part(parameter2);

        draw_box_outline(window_handle, data->start, data->end);

        set_cursor(load_cursor((handle)null, (const character*)cursor_identity::cross));

        data->blocking = true;
    }
    break;

    case message::mouse_move:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        if (data->blocking)
        {
            set_cursor(load_cursor((handle)null, (const character*)cursor_identity::cross));

            draw_box_outline(window_handle, data->start, data->end);

            data->end(0) = low_part(parameter2);
            data->end(1) = high_part(parameter2);

            draw_box_outline(window_handle, data->start, data->end);
        }
    }
    break;

    case message::left_button_up:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        if (data->blocking)
        {
            draw_box_outline(window_handle, data->start, data->end);

            data->box_start = data->start;
            data->box_end(0) = low_part(parameter2);
            data->box_end(1) = high_part(parameter2);

            set_cursor(load_cursor((handle)null, (const character*)cursor_identity::arrow));

            data->blocking = false;
            data->valid_box = true;

            invalidate_rectangle(window_handle, (const irectangle*)null, true);
        }
    }
    break;

    case message::character:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        if ((unsigned)data->blocking & (unsigned)parameter1 == '\x1b')       // Escape
        {
            draw_box_outline(window_handle, data->start, data->end);
            set_cursor(load_cursor((handle)null, (const character*)cursor_identity::arrow));
            data->blocking = false;
        }
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        if (data->valid_box)
        {
            select_object(device_context, get_standard_object(standard_brush::black));
            draw_rectangle(device_context, data->box_start(0), data->box_start(1), data->box_end(0), data->box_end(1));
        }

        if (data->blocking)
        {
            set_foreground_mix(device_context, mix::_not);
            select_object(device_context, get_standard_object(standard_brush::null));
            draw_rectangle(device_context, data->start(0), data->start(1), data->end(0), data->end(1));
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

void draw_box_outline(handle window_handle, ipoint start, ipoint end)
{
    handle device_context = get_device_context(window_handle);
    set_foreground_mix(device_context, mix::_not);
    select_object(device_context, get_standard_object(standard_brush::null));
    draw_rectangle(device_context, start(0), start(1), end(0), end(1));
    release_device_context(window_handle, device_context);
}

// Win# -- Colors.cpp -- Modeless Dialog Box

import iplusplus;
using namespace iplusplus;

#include "Colors.h"

result __stdcall client(handle, unsigned, parameter, parameter);
result __stdcall color_procedure(handle, unsigned, parameter, parameter);

int __stdcall WinMain(handle module_handle,
    handle reserved,
    character* command_line,
    int show_command)
{
    window_class<character> wclass;

    wclass.style = 0;
    wclass.procedure = client;
    wclass.extra = 0;
    wclass.window = 8;
    wclass.module = module_handle;
    wclass.icon = load_icon(module_handle, (const character*)FrameIdentity);
    wclass.cursor = load_cursor((handle)null, (const character*)cursor_identity::arrow);
    wclass.brush = (handle)get_standard_object(standard_brush::black);
    wclass.name = (const character*)L"Colors";
    atom atom_window = register_class(&wclass);

    character aszTitle[40];
    load_string(module_handle, FrameIdentity, aszTitle, 40);

    handle window_handle = create_window(atom_window,
        aszTitle,
        style::standard,
        use_default,
        use_default,
        use_default,
        use_default,
        (handle)null,
        0);

    show_window(window_handle, show_command);
    update_window(window_handle);

    handle dialog_handle = create_dialog(module_handle,
        (const character*)ColorDialog,
        window_handle,
        color_procedure);

    queue queue_message;
    while (get_message(&queue_message))
    {
        if (!is_dialog_message(dialog_handle, &queue_message))
        {
            translate_message(&queue_message);
            dispatch_message(&queue_message);
        }
    }

    return (int)queue_message.parameter1;
}

result __stdcall client(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (identity)
    {
    case message::close:
        post_quit_message();
        break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

struct dialog_data
{
    int color_array[3];

    dialog_data() { color_array[0] = 0; color_array[1] = 0; color_array[2] = 0; }
};

result __stdcall color_procedure(handle dialog_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (identity)
    {

    case message::initialize_dialog:
    {
        dialog_data* data = new dialog_data();
        set_window_pointer(dialog_handle, offset::user_data, (void*)data);

        for (int control_identity = 10; control_identity < 13; control_identity++)
        {
            handle control_handle = get_child_window(dialog_handle, control_identity);
            set_scroll_range(control_handle, scrollbar_identity::control, 0, 255, false);
            set_scroll_position(control_handle, scrollbar_identity::control, 0, false);
        }
    }
    return (result)true;

    case message::destroy:
    {
        dialog_data* data = (dialog_data*)get_window_pointer(dialog_handle, offset::user_data);
        delete data;
    }
    break;

    case message::vertical_scroll:
    {
        dialog_data* data = (dialog_data*)get_window_pointer(dialog_handle, offset::user_data);

        handle control_handle = (handle)parameter2;
        int control_identity = get_window_integer(control_handle, offset::identity);
        int index = control_identity - 10;

        switch (low_part(parameter1))
        {
        case scrollbar_notify::page_down:
            data->color_array[index] += 15;        // fall through
        case scrollbar_notify::line_down:
            data->color_array[index] = minimum(255, data->color_array[index] + 1);
            break;

        case scrollbar_notify::page_up:
            data->color_array[index] -= 15;        // fall through
        case scrollbar_notify::line_up:
            data->color_array[index] = maximum(0, data->color_array[index] - 1);
            break;

        case scrollbar_notify::top:
            data->color_array[index] = 0;
            break;

        case scrollbar_notify::bottom:
            data->color_array[index] = 255;
            break;

        case scrollbar_notify::slider_position:
        case scrollbar_notify::slider_track:
            data->color_array[index] = high_part(parameter1);
            break;

        default:
            return (result)false;
        }

        set_scroll_position(control_handle, scrollbar_identity::control, data->color_array[index], true);
        set_child_integer(dialog_handle, control_identity + 3, data->color_array[index], false);

        handle parent = get_parent(dialog_handle);

        delete_object((handle)set_class_pointer(parent,
            class_offset::background_brush,
            create_solid_brush(red_green_blue(data->color_array[0], data->color_array[1], data->color_array[2]))));

        invalidate_rectangle(parent, (const irectangle*)null, true);
    }
    return (result)true;

    case message::close:
        post_quit_message();
        break;
    }

    return false;
}

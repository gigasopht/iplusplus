// Win+ -- Resource2.cpp -- Icon and Cursor Demonstration Program Number 2

import iplusplus;
using namespace core;

#include "Resource2.h"

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
    wclass.icon = load_icon(module_handle, (const character*)FrameIdentity);
    wclass.cursor = load_cursor(module_handle, (const character*)FrameIdentity);
    handle bitmap = load_bitmap(module_handle, (const character*)BitmapLoad);
    wclass.brush = create_pattern_brush(bitmap);
    wclass.name = L"Resource2";
    delete_object(bitmap);
    atom atom_name = register_class(&wclass);

    character aszFrame[80]; // buffer for application title

    load_string(module_handle,
        FrameIdentity,
        aszFrame,
        80);

    handle window = create_window(atom_name, aszFrame);

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
    int width_of_icon,
        height_of_icon,
        width_of_client,
        height_of_client;
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
        data->width_of_icon = get_system_metrics(system_metric::icon_width);
        data->height_of_icon = get_system_metrics(system_metric::icon_height);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete_object(set_class_pointer(window_handle, class_offset::background_brush,(handle)null));
        delete data;
    }
    break;


    case message::size:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        data->width_of_client = low_part(parameter2);
        data->height_of_client = high_part(parameter2);
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        handle icon_handle = get_class_pointer(window_handle, class_offset::icon);

        for (int y = data->height_of_icon; y < data->height_of_client; y += 2 * data->height_of_icon)
            for (int x = data->width_of_icon; x < data->width_of_client; x += 2 * data->width_of_icon)
                draw_icon(device_context, x, y, icon_handle);

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


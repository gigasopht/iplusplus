// Win+ -- Bounce.cpp -- Bouncing Ball

import iplusplus;
using namespace core;

enum { identity_of_timer = 1 };

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
    wclass.name = L"Bounce";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Animation");

    set_timer(window, identity_of_timer, 10);

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
    handle bitmap;

    int width_of_client,
        height_of_client,
        x_center, y_center,
        x_total, y_total,
        x_radius, y_radius,
        x_move, y_move,
        x_pixel, y_pixel;


    window_data()
    {
        bitmap = 0;
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
        handle device_context = get_device_context(window_handle);
        data->x_pixel = get_device_capabilities(device_context, capability::aspect_x);
        data->y_pixel = get_device_capabilities(device_context, capability::aspect_y);
        release_device_context(window_handle, device_context);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        if (data->bitmap) delete_object(data->bitmap);
        delete data;
        cancel_timer(window_handle, identity_of_timer);
    }

    case message::size:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        data->x_center = (data->width_of_client = low_part(parameter2)) / 2;
        data->y_center = (data->height_of_client = high_part(parameter2)) / 2;

        int scale = minimum(data->width_of_client * data->x_pixel,
            data->height_of_client * data->y_pixel) / 16;

        data->x_radius = scale / data->x_pixel;
        data->y_radius = scale / data->y_pixel;

        data->x_move = maximum(1, data->x_radius / 8);
        data->y_move = maximum(1, data->y_radius / 8);

        data->x_total = 2 * (data->x_radius + data->x_move);
        data->y_total = 2 * (data->y_radius + data->y_move);

        if (data->bitmap) delete_object(data->bitmap);

        handle device_context = get_device_context(window_handle);
        handle memory_device = create_memory_device_context(device_context);
        data->bitmap = create_compatible_bitmap(device_context, data->x_total, data->y_total);
        release_device_context(window_handle, device_context);

        select_object(memory_device, data->bitmap);
        draw_rectangle(memory_device, -1, -1, data->x_total + 1, data->y_total + 1);

        handle brush = create_hatch_brush(hatch_style::diagonal_cross, 0);
        select_object(memory_device, brush);
        set_background_color(memory_device, red_green_blue(255, 0, 255));

        draw_ellipse(memory_device,
            data->x_move,
            data->y_move,
            data->x_total - data->x_move,
            data->y_total - data->y_move);

        delete_device_context(memory_device);
        delete_object(brush);
    }
    break;

    case message::timer:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        if (data->bitmap)
        {
            handle device_context = get_device_context(window_handle);
            handle memory_device = create_memory_device_context(device_context);
            select_object(memory_device, data->bitmap);

            bit_block_transfer(device_context,
                data->x_center - data->x_total / 2,
                data->y_center - data->y_total / 2,
                data->x_total,
                data->y_total,
                memory_device,
                0, 0, raster_operation::source_copy);

            release_device_context(window_handle, device_context);
            delete_device_context(memory_device);

            data->x_center += data->x_move;
            data->y_center += data->y_move;

            if (data->x_center + data->x_radius >= data->width_of_client || data->x_center - data->x_radius <= 0)
                data->x_move = -data->x_move;

            if (data->y_center + data->y_radius >= data->height_of_client || data->y_center - data->y_radius <= 0)
                data->y_move = -data->y_move;
        }
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

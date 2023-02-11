// Win+ -- Analog.cpp -- Analog Clock

import iplusplus;
using namespace iplusplus;

import std.core;
using namespace std;

result __stdcall client(handle, unsigned, parameter, parameter);

enum { identity_of_timer = 1 };

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
    wclass.name = L"Clock";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Analog Clock");

    set_timer(window, identity_of_timer, 1000);

    show_window(window, show_command);

    iplusplus::queue queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

#define two_pi (2 * 3.14159)

void set_isotropic(handle device_context,
    int width_of_client,
    int height_of_client)
{
    set_mapping_mode(device_context, unit::isotropic);
    set_window_extent(device_context, 1000, 1000);
    set_viewport_extent(device_context, width_of_client / 2, -height_of_client / 2);
    set_viewport_origin(device_context, width_of_client / 2, height_of_client / 2);
}

void rotate_points(ipoint point_array[],
    int count,
    int angle)
{
    double radians = two_pi * angle / 360;

    double sine = sin(radians);
    double cosine = cos(radians);

    matrix22 rotation(cosine, sine, -sine, cosine);

    for (int i = 0; i < count; i++)
        point_array[i] = rotation * point_array[i];
}

void draw_clock(handle device_context)
{
    for (int angle = 0; angle < 360; angle += 6)
    {
        ipoint dot(0, 900);
        rotate_points(&dot, 1, angle);

        int size = angle % 5 ? 33 : 100;
        ipoint box(size, size);

        ipoint lower_left = dot - box / 2;
        ipoint upper_right = lower_left + box;

        select_object(device_context, get_standard_object(standard_brush::black));

        draw_ellipse(device_context,
            lower_left(0),
            lower_left(1),
            upper_right(0),
            upper_right(1));
    }
}

void draw_hands(handle device_context,
    const system_time& time)
{
    static ipoint point_array[3][5] = { ipoint(0, -150), ipoint(100, 0), ipoint(0, 600), ipoint(-100, 0), ipoint(0, -150),
                                        ipoint(0, -200), ipoint(50, 0), ipoint(0, 800), ipoint(-50, 0), ipoint(0, -200),
                                        ipoint(0,    0), ipoint(0, 0), ipoint(0,   0), ipoint(0, 0), ipoint(0,  800) };

    int angle[3];
    ipoint temporaries[3][5];

    angle[0] = (time.hour * 30) % 360 + time.minute / 2 + time.second / 120;
    angle[1] = time.minute * 6 + (float)time.second / 10;
    angle[2] = time.second * 6;

    memcpy(temporaries, point_array, sizeof(point_array));

    for (int i = 0; i < 3; i++)
    {
        rotate_points(temporaries[i], 5, angle[i]);
        draw_lines(device_context, temporaries[i], 5);
    }
}

struct window_data
{
    int width_of_client,
        height_of_client;

    system_time previous_time;
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
        get_local_time(&data->previous_time);
        send_message(window_handle, message::timer, 0, 0);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        cancel_timer(window_handle, identity_of_timer);
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

    case message::timer:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        system_time current_time;

        get_local_time(&current_time);

        handle device_context = get_device_context(window_handle);

        set_isotropic(device_context, data->width_of_client, data->height_of_client);

        select_object(device_context, get_standard_object(standard_pen::white));
        draw_hands(device_context, data->previous_time);

        select_object(device_context, get_standard_object(standard_pen::black));
        draw_hands(device_context, current_time);

        release_device_context(window_handle, device_context);

        data->previous_time = current_time;
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;

        handle device_context = begin_paint(window_handle, &paint_structure);

        set_isotropic(device_context, data->width_of_client, data->height_of_client);

        draw_clock(device_context);
        draw_hands(device_context, data->previous_time);

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

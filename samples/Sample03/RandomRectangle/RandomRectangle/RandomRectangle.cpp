// win+ -- RandomRectangle.cpp -- Draws Random Rectangles

import std.core;
using namespace std;

import iplusplus;
using namespace iplusplus;

result __stdcall client(handle, unsigned, parameter, parameter);

void draw_random_rectangle(handle);

int width_of_client = 0, height_of_client = 0;

int __stdcall WinMain(handle module_handle,
    handle previous,
    character* command_line,
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
    wclass.name = L"RandomRectangle";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Random Rectangles");

    show_window(window, show_command);

    iplusplus::queue queue_message;
    for (;;)
    {
        if (peek_message(&queue_message, (handle)null, 0, 0, peek::remove))
        {
            if (queue_message.identity == message::quit) break;
            translate_message(&queue_message);
            dispatch_message(&queue_message);
        }
        else
            draw_random_rectangle(window);
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
    case message::size:
        width_of_client = low_part(parameter2);
        height_of_client = high_part(parameter2);
        break;

    case message::close:
        post_quit_message();
        break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

void draw_random_rectangle(handle window_handle)
{
    if (width_of_client == 0 || height_of_client == 0) return;

    irectangle draw_rectangle(rand() % width_of_client,
        rand() % height_of_client,
        rand() % width_of_client,
        rand() % height_of_client);

    handle solid_brush = create_solid_brush(red_green_blue(rand() % 256,
        rand() % 256,
        rand() % 256));

    handle device_context = get_device_context(window_handle);

    fill_rectangle(device_context, &draw_rectangle, solid_brush);

    release_device_context(window_handle, device_context);

    delete_object(solid_brush);
}

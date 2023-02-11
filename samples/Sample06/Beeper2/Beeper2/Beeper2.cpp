// Win# -- Beeper2.cpp -- Timer Demonstration Program Number 2

import iplusplus;
using namespace iplusplus;

enum { identity_of_timer = 1 };

result __stdcall client(handle, unsigned, parameter, parameter);
void __stdcall timer(handle, unsigned, ulong, unsigned);

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
    wclass.name = L"Beeper2";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Beeper2");

    set_timer(window, identity_of_timer, 1000, timer);

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
    int alternate;

    window_data()
    {
        alternate = false;
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
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete data;
        cancel_timer(window_handle, identity_of_timer);
    }

    case message::close:
        post_quit_message();
        break;

    default:
        return default_window_procedure(window_handle, identity, parameter1, parameter2);
    }
    return 0;
}

void __stdcall timer(handle window_handle,
    unsigned message,
    ulong identity,
    unsigned time)
{
    window_data* data = (window_data*)get_window_pointer(window_handle, 0);

    message_beep(message_box_style::ok);
    data->alternate = !data->alternate;

    irectangle client_rectangle;
    get_client_rectangle(window_handle, &client_rectangle);

    handle device_context = get_device_context(window_handle);

    handle brush = create_solid_brush(data->alternate ? red_green_blue(255, 0, 0)
        : red_green_blue(0, 0, 255));

    fill_rectangle(device_context, &client_rectangle, brush);
    release_device_context(window_handle, device_context);
    delete_object(brush);
}

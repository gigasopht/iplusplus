// Win+ -- Edit.cpp -- The Edit Control

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
    wclass.name = L"Editor";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Editor");

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
    handle editor_handle;

    window_data()
    {
        editor_handle = 0;
    }
};

enum { identity_editor = 1 };

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

        data->editor_handle = create_window(L"Edit",
            L"",
            style::child | style::visible | style::horizontal_scroll | style::vertical_scroll |
            style::border | edit_style::left | edit_style::multiple_line |
            edit_style::auto_scroll_horizontal | edit_style::auto_scroll_vertical,
            use_default,
            use_default,
            use_default,
            use_default,
            window_handle,
            (handle)identity_editor);
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete data;
    }
    break;

    case message::set_focus:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        set_focus(data->editor_handle);
    }
    break;

    case message::size:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        move_window(data->editor_handle, 0, 0, low_part(parameter2), high_part(parameter2), true);
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

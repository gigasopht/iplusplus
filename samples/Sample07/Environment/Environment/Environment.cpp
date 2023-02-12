// Win# -- Environment.cpp -- Environment List Box

import iplusplus;
using namespace core;

character* lstrchr(const character* string,
    character find)
{
    while (*string && *string != find) string++;
    if (*string) return (character*)string; else return 0;
}

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
    wclass.name = L"Environment";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Environment");

    show_window(window, show_command);

    queue_message queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

enum { maximum_environment = 4096 };

struct window_data
{
    handle listbox, display;
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

        text_metrics<character> text_metrics_get;
        get_text_metrics(device_context, &text_metrics_get);

        release_device_context(window_handle, device_context);

        data->listbox = create_window(L"listbox",
            L"",
            style::child | style::visible | listbox_style::standard,
            use_default,
            use_default,
            use_default,
            use_default,
            window_handle,
            (handle)1);

        move_window(data->listbox,
            text_metrics_get.average_character_width,
            text_metrics_get.height * 3,
            text_metrics_get.average_character_width * 16
            + get_system_metrics(system_metric::vertical_scroll_width),
            text_metrics_get.height * 5);

        data->display = create_window("static",
            "",
            style::child | style::visible | display_style::left,
            use_default,
            use_default,
            use_default,
            use_default,
            window_handle,
            (handle)2);

        move_window(data->display,
            text_metrics_get.average_character_width,
            text_metrics_get.height,
            text_metrics_get.average_character_width * maximum_environment,
            text_metrics_get.height);

        character* environment_save = get_environment_strings();
        character* environment = environment_save;
        while (*environment)
        {
            character* equals = lstrchr(environment, '=');
            *equals = '\0';

            if (environment != equals)
                send_message(data->listbox, listbox_message::add_string, 0, (parameter)environment);

            environment = (equals + 1) + string_length(equals + 1) + 1;
        }

        free_environment_strings(environment_save);
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
        set_focus(data->listbox);
    }
    break;

    case message::command:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        if (low_part(parameter1) == 1 && high_part(parameter1) == listbox_notify::selection_change)
        {
            int i = (int)send_message(data->listbox, listbox_message::get_selection);

            character buffer[maximum_environment + 1];

            int length = (int)send_message(data->listbox,
                listbox_message::get_text,
                (parameter)i,
                (parameter)buffer);

            get_environment_variable(buffer,
                buffer + length + 1,
                maximum_environment - (length + 1));

            *(buffer + length) = '=';

            set_window_text(data->display, buffer);
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


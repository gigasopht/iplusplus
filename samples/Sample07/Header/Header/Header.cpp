// Win+ -- Header.cpp -- Displays a Portion of a File
//                    -- Unlike the original sample that was written, this sample converts the file from single byte to double byte.

import iplusplus;
using namespace iplusplus;

result __stdcall client(handle, unsigned, parameter, parameter);

result __stdcall list_procedure(handle, unsigned, parameter, parameter);

enum { maximum_read = 8192 };

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
    wclass.name = L"Header";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Header");

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
    procedure list_procedure_subclassed;
    bool valid_file;
    unsigned char read_buffer[maximum_read];
    unsigned bytes_read;
    character buffer[maximum_read];
    character filename[path_length::maximum_component];
    handle  listbox_handle, text_handle;
    irectangle bounds;
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
        select_object(device_context, get_standard_object(standard_font::fixed_system));

        text_metrics<character> text_metrics_get;
        get_text_metrics(device_context, &text_metrics_get);
        release_device_context(window_handle, device_context);

        data->bounds[0](0) = 20 * text_metrics_get.average_character_width;
        data->bounds[0](1) = 3 * text_metrics_get.height;

        data->listbox_handle = create_window(L"listbox",
            (const character*)null,
            style::child | style::visible | listbox_style::_standard,
            text_metrics_get.average_character_width,
            text_metrics_get.height * 3,
            text_metrics_get.average_character_width * 13 + get_system_metrics(system_metric::vertical_scroll_width),
            text_metrics_get.height * 10,
            window_handle,
            (handle)1);

        data->list_procedure_subclassed = (procedure)set_window_pointer(data->listbox_handle,
            offset::window_procedure,
            (handle)list_procedure);

        send_message(data->listbox_handle, listbox_message::directory, (parameter)0x37, (parameter)L"*.*");

        character buffer[path_length::maximum_component + 1];

        get_current_directory(path_length::maximum_component, buffer);

        data->text_handle = create_window(L"static",
            buffer,
            style::child | style::visible | display_style::left,
            text_metrics_get.average_character_width,
            text_metrics_get.height,
            text_metrics_get.average_character_width * path_length::maximum_component,
            text_metrics_get.height,
            window_handle,
            (handle)2);
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

        data->bounds[1](0) = low_part(parameter2);
        data->bounds[1](1) = high_part(parameter2);
    }
    break;

    case message::set_focus:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        set_focus(data->listbox_handle);
    }
    break;

    case message::command:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        if (low_part(parameter1) == 1 && high_part(parameter1) == listbox_notify::double_click)
        {
            int index = (int)send_message(data->listbox_handle, listbox_message::get_selection);
            if (index != listbox_return::error)
            {
                character buffer[path_length::maximum_component + 1];

                send_message(data->listbox_handle,
                    listbox_message::get_text,
                    (parameter)index,
                    (parameter)buffer);

                if (!(get_file_attributes(buffer) & file_attribute::directory))
                {
                    data->valid_file = true;
                    copy_string(data->filename, buffer);
                    get_current_directory(path_length::maximum_component, buffer);
                    if (buffer[string_length(buffer) - 1] != '\\')
                        concatenate_strings(buffer, L"\\");
                    set_window_text(data->text_handle,
                        concatenate_strings(buffer, data->filename));

                    handle file = create_file(data->filename,
                        access_type::generic_read,
                        share_file::read);
                    if (file)
                    {
                       
                        read_file(file, data->read_buffer, maximum_read, &data->bytes_read);
                        close_handle(file);
                        multibyte_to_wide_character(0, 0, (const char*)data->read_buffer, data->bytes_read, data->buffer, maximum_read);
                    }
                    else
                        data->valid_file = false;
                }
                else
                {
                    data->valid_file = false;
                    buffer[string_length(buffer) - 1] = '\0';
                    set_current_directory(buffer + 1);
                    get_current_directory(path_length::maximum_component, buffer);
                    set_window_text(data->text_handle, buffer);
                    send_message(data->listbox_handle, listbox_message::reset_content);
                    send_message(data->listbox_handle, listbox_message::directory, (parameter)0x37, (parameter)L"*.*");
                }
                invalidate_rectangle(window_handle, (const irectangle*)null, true);
            }
        }
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        select_object(device_context, get_standard_object(standard_font::fixed_system));
        set_text_color(device_context, get_system_color(system_color::button_text));
        set_background_color(device_context, get_system_color(system_color::button_face));

        if (data->valid_file)
            draw_text(device_context,
                (const character*)data->buffer,
                data->bytes_read,
                &data->bounds,
                draw_text_format::word_break | draw_text_format::expand_tabs | draw_text_format::no_clip | draw_text_format::no_prefix);

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

result __stdcall list_procedure(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    if (identity == message::key_down && (int)parameter1 == virtual_key::_return)
        send_message(get_parent(window_handle),
            message::command,
            (parameter)make_integer((part)get_window_integer(window_handle, offset::identity),
                (part)listbox_notify::double_click),
            (parameter)window_handle);

    window_data* data = (window_data*)get_window_pointer(get_parent(window_handle), 0);

    return call_window_procedure(data->list_procedure_subclassed, window_handle, identity, parameter1, parameter2);
}

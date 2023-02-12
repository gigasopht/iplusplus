// Win+ -- About2.cpp -- About Box Demonstration Program no. 2

import iplusplus;
using namespace core;

#include "About2.h"

result __stdcall client(handle, unsigned, parameter, parameter);
result __stdcall about(handle, unsigned, parameter, parameter);

void paint_block(handle, int, int);
void paint_window(handle, handle, int, int);

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
    wclass.name = L"About2";

    atom atom_name = register_class(&wclass);

    character aszFrame[256];
    load_string(0, FrameIdentity, aszFrame, sizeof(aszFrame));

    handle window_handle = create_window(atom_name,
        aszFrame,
        style::standard,
        use_default,
        use_default,
        use_default,
        use_default,
        (handle)null,
        load_menu(module_handle, (const character*)FrameIdentity));

    show_window(window_handle, show_command);

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
    int current_color,
        current_figure;

    window_data()
    {
        current_color = ButtonCyan;
        current_figure = ButtonEllipse;

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
        set_class_pointer(window_handle, class_offset::icon, load_icon(get_module_handle<character>(), "About2"));
    }
    break;

    case message::destroy:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        delete data;
    }
    break;


    case message::command:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);
        switch (low_part(parameter1))
        {
        case MenuItemAbout:
            if (dialog_box(get_module_handle<character>(0),
                (const character*)DialogIdentity,
                window_handle,
                about,
                (parameter)data))
                invalidate_rectangle(window_handle, (const irectangle*)null, true);
            break;
        }
    }
    break;

    case message::paint:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        paint paint_structure;

        handle device_context = begin_paint(window_handle, &paint_structure);
        paint_window(window_handle, device_context, data->current_color, data->current_figure);
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

struct dialog_data
{
    handle control;
    int color, figure;
};

result __stdcall about(handle dialog_handle,
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

        window_data* wdata = (window_data*)parameter2;

        data->color = wdata->current_color;
        data->figure = wdata->current_figure;

        check_radio_button(dialog_handle, ButtonBlack, ButtonWhite, data->color);
        check_radio_button(dialog_handle, ButtonRectangle, ButtonEllipse, data->figure);

        data->control = get_child_window(dialog_handle, TextPaint);

        set_focus(get_child_window(dialog_handle, data->color));
    }
    break;

    case message::destroy:
    {
        dialog_data* data = (dialog_data*)get_window_pointer(dialog_handle, offset::user_data);
        delete data;
    }
    break;


    case message::command:
    {
        dialog_data* data = (dialog_data*)get_window_pointer(dialog_handle, offset::user_data);
        switch (low_part(parameter1))
        {
        case item_identity::ok:
        {
            handle parent = get_parent(dialog_handle);
            window_data* wdata = (window_data*)get_window_pointer(parent, 0);
            wdata->current_color = data->color;
            wdata->current_figure = data->figure;
            end_dialog(dialog_handle, (void*)true);
        }
        return (result)true;

        case item_identity::cancel:
            end_dialog(dialog_handle, 0);
            return (result)true;

        case ButtonBlack:
        case ButtonRed:
        case ButtonGreen:
        case ButtonYellow:
        case ButtonBlue:
        case ButtonMagenta:
        case ButtonCyan:
        case ButtonWhite:
            data->color = low_part(parameter1);
            check_radio_button(dialog_handle, ButtonBlack, ButtonWhite, low_part(parameter1));
            paint_block(data->control, data->color, data->figure);
            return (result)true;

        case ButtonRectangle:
        case ButtonEllipse:
            data->figure = low_part(parameter1);
            check_radio_button(dialog_handle, ButtonRectangle, ButtonEllipse, low_part(parameter1));
            paint_block(data->control, data->color, data->figure);
            return (result)true;
        }
    }
    break;

    case message::paint:
    {
        dialog_data* data = (dialog_data*)get_window_pointer(dialog_handle, offset::user_data);
        paint_block(data->control, data->color, data->figure);
    }
    break;

    default:
        break;
    }
    return false;
}


void paint_window(handle window_handle,
    handle device_context,
    int color_index,
    int figure)
{
    static icolor color_array[8] = { red_green_blue(0,     0, 0), red_green_blue(0,   0, 255),
                                     red_green_blue(0,   255, 0), red_green_blue(0, 255, 255),
                                     red_green_blue(255,   0, 0), red_green_blue(255,   0, 255),
                                     red_green_blue(255, 255, 0), red_green_blue(255, 255, 255) };

    //handle device_context = get_device_context(window_handle);

    irectangle client_rectangle;
    get_client_rectangle(window_handle, &client_rectangle);

    handle brush = create_solid_brush(color_array[color_index - ButtonBlack]);
    brush = (handle)select_object(device_context, brush);

    if (figure == ButtonRectangle)
        draw_rectangle(device_context,
            client_rectangle[0](0),
            client_rectangle[0](1),
            client_rectangle[1](0),
            client_rectangle[1](1));
    else
        draw_ellipse(device_context,
            client_rectangle[0](0),
            client_rectangle[0](1),
            client_rectangle[1](0),
            client_rectangle[1](1));

    delete_object(select_object(device_context, brush));
    release_device_context(window_handle, device_context);
}

void paint_block(handle window_handle,
    int color,
    int figure)
{
    invalidate_rectangle(window_handle, (const irectangle*)null, true);
    update_window(window_handle);
    handle device_context = get_device_context(window_handle);
    paint_window(window_handle, device_context, color, figure);
    release_device_context(window_handle, device_context);
}


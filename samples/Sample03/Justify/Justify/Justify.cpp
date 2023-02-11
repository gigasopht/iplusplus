// win+ -- justify.cpp -- Justified type Program

import iplusplus;
using namespace iplusplus;

#include "EasyFont.hpp"
#include "justify.hpp"

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
    wclass.name = L"Justify";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Justified Text");

    show_window(window, show_command);

    queue queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
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
    case message::paint:
    {
        paint paint_structure;
        handle device_context = begin_paint(window_handle, &paint_structure);

        irectangle client_rectangle;
        get_client_rectangle(window_handle, &client_rectangle);
        draw_ruler(device_context, &client_rectangle);

        client_rectangle[0](0) += get_device_capabilities(device_context, capability::logical_pixels_x) / 2;
        client_rectangle[0](1) += get_device_capabilities(device_context, capability::logical_pixels_y) / 2;
        client_rectangle[1](0) -= get_device_capabilities(device_context, capability::logical_pixels_x) / 4;

        select_object(device_context,
            easy_create_font(device_context, L"Times New Roman", 150, 0, 0, true));

        justify(device_context, text, &client_rectangle, text_justify::text_justified);

        delete_object(select_object(device_context, get_standard_object(standard_font::system)));
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

void draw_ruler(handle device_context,
    const irectangle* ruler_rectangle)
{
    int size_of_rule[16] = { 360, 72, 144, 72, 216, 72, 144, 72,
                              288, 72, 144, 72, 216, 72, 144, 72 };

    save_device_context(device_context);

    set_mapping_mode(device_context, unit::anisotropic);

    set_window_extent(device_context, 1440, 1440);

    set_viewport_extent(device_context, get_device_capabilities(device_context, capability::logical_pixels_x),
        get_device_capabilities(device_context, capability::logical_pixels_y));

    set_window_origin(device_context, -720, -720);

    ipoint point_client(ruler_rectangle->b);

    device_points_to_logical_points(device_context, &point_client, 1);
    point_client(0) -= 360;

    // draw the rulers

    move_to(device_context, 0, -360);
    draw_line_to(device_context, point_client(0), -360);
    move_to(device_context, -360, 0);
    draw_line_to(device_context, -360, point_client(1));

    for (int i = 0, j = 0; i <= point_client(0); i += 1440 / 16, j++)
    {
        move_to(device_context, i, -360);
        draw_line_to(device_context, i, -360 - size_of_rule[j % 16]);
    }

    for (int k = 0, l = 0; k <= point_client(1); k += 1440 / 16, l++)
    {
        move_to(device_context, -360, k);
        draw_line_to(device_context, -360 - size_of_rule[l % 16], k);
    }

    restore_device_context(device_context, -1);
}

void justify(handle device_context,
    const character* text,
    const irectangle* bounds,
    unsigned alignment)
{
    idimensions size_of_text;

    int y_start = (*bounds)(0, 1);

    do  // for each text line
    {
        int break_count = 0;
        while (*text == ' ') text++;

        const character* begin = text;
        const character* end;

        set_text_justification(device_context, 0, 0);
        do
        {
            end = text;

            while (*text != '\0' && *text++ != ' ');
            break_count++;
            if (*text == '\0') break;

            get_text_extent(device_context,
                begin,
                text - begin - 1,
                &size_of_text);
        } while (size_of_text(0) < (*bounds)(1, 0) - (*bounds)(0, 0));

        break_count--;
        while (*(end - 1) == ' ')
        {
            end--; break_count--;
        }

        if (*text == '\0' || break_count <= 0)
            end = text;

        get_text_extent(device_context,
            begin,
            end - begin,
            &size_of_text);

        int x_start;

        switch (alignment)
        {
        case text_left:
            x_start = (*bounds)(0, 0);
            break;

        case text_right:
            x_start = (*bounds)(1, 0) - size_of_text(0);
            break;

        case text_center:
            x_start = ((*bounds)(1, 0) + (*bounds)(0, 0) - size_of_text(0)) / 2;
            break;

        case text_justified:
            if (*text != '\0' && break_count > 0)
                set_text_justification(device_context,
                    (*bounds)(1, 0) - (*bounds)(0, 0) - size_of_text(0),
                    break_count);
            x_start = (*bounds)(0, 0);
            break;
        }

        text_out(device_context,
            x_start,
            y_start,
            begin,
            end - begin);

        y_start += size_of_text(1);
        text = end;
    } while (*text && y_start < (*bounds)(1, 1));
}



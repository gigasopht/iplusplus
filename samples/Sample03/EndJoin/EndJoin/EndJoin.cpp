// win+ -- EndJoin.cpp -- Ends and Joins Demonstration

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
    wclass.name = L"end_join";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Line Ends and Joins");

    show_window(window, show_command);

    queue queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

struct window_data
{
    int ends[3];
    int joins[3];
    int width_of_client,
        height_of_client;

    window_data()
    {
        ends[0] = pen_style::end_round;
        ends[1] = pen_style::end_square;
        ends[2] = pen_style::end_flat;
        joins[0] = pen_style::join_round;
        joins[1] = pen_style::join_bevel;
        joins[2] = pen_style::join_mitre;
    }

};

result __stdcall client(handle window_handle,
    unsigned Identity,
    parameter parameter1,
    parameter parameter2)
{
    switch (Identity)
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

        set_mapping_mode(device_context, unit::anisotropic);
        set_window_extent(device_context, 100, 100);
        set_viewport_extent(device_context, data->width_of_client, data->height_of_client);

        logical_brush logical_brush_select;

        logical_brush_select.style = brush_style::solid;
        logical_brush_select.color = icolor(128, 128, 128);
        logical_brush_select.hatch = 0;

        for (int i = 0; i < 3; i++)
        {
            select_object(device_context,
                extended_create_pen(pen_style::solid | pen_style::geometric |
                    data->ends[i] | data->joins[i],
                    10,
                    &logical_brush_select));

            begin_path(device_context);

            move_to(device_context, 10 + 30 * i, 25);
            draw_line_to(device_context, 20 + 30 * i, 75);
            draw_line_to(device_context, 30 + 30 * i, 25);

            end_path(device_context);

            stroke_path(device_context);

            delete_object(select_object(device_context,
                get_standard_object(standard_pen::black)));

            move_to(device_context, 10 + 30 * i, 25);
            draw_line_to(device_context, 20 + 30 * i, 75);
            draw_line_to(device_context, 30 + 30 * i, 25);
        }

        end_paint(window_handle, &paint_structure);
    }
    break;

    case message::close:
        post_quit_message(0);
        break;

    default:
        return default_window_procedure(window_handle, Identity, parameter1, parameter2);
    }
    return 0;
}

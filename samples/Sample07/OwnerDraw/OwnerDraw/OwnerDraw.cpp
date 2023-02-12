// Win+ -- OwnerDraw.cpp -- Owner-Draw Button Demonstration Program

import iplusplus;
using namespace core;

struct button_identity
{
    enum
    {
        smaller = 1,
        larger = 2
    };
};

struct button_dimensions  // Units of the width of a character
{
    enum
    {
        width = 8,
        height = 4
    };
};

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
    wclass.name = L"OwnerDraw";

    atom atom_name = register_class(&wclass);

    handle window = create_window(atom_name, L"Owner Draw");

    show_window(window, show_command);

    queue_message queue_message;
    while (get_message(&queue_message, 0, 0, 0))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

void triangle(handle device_context, ipoint points[])
{
    select_object(device_context, get_standard_object(standard_brush::black));
    draw_polygon(device_context, points, 3);
    select_object(device_context, get_standard_object(standard_brush::white));
}

struct window_data
{
    handle smaller, larger;

    int width_of_client,
        height_of_client,
        width_of_character,
        height_of_character;

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

        data->width_of_character = low_part(get_dialog_base_units());
        data->height_of_character = high_part(get_dialog_base_units());

        data->smaller = create_window(L"button",
            L"",
            style::child | style::visible | button_style::owner_draw,
            use_default,
            use_default,
            use_default,
            use_default,
            window_handle,
            (handle)button_identity::smaller);

        data->larger = create_window(L"button",
            L"",
            style::child | style::visible | button_style::owner_draw,
            use_default,
            use_default,
            use_default,
            use_default,
            window_handle,
            (handle)button_identity::larger);
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

        move_window(data->smaller,
            data->width_of_client / 2 - 3 * button_dimensions::width * data->width_of_character / 2,
            data->height_of_client / 2 - button_dimensions::height * data->height_of_character / 2,
            button_dimensions::width * data->width_of_character,
            button_dimensions::height * data->height_of_character, true);

        move_window(data->larger,
            data->width_of_client / 2 + button_dimensions::width * data->width_of_character / 2,
            data->height_of_client / 2 - button_dimensions::height * data->height_of_character / 2,
            button_dimensions::width * data->width_of_character,
            button_dimensions::height * data->height_of_character, true);
    }
    break;

    case message::command:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        irectangle rectangle_window;
        get_window_rectangle(window_handle, &rectangle_window);

        switch ((int)parameter1) // Make the rectangle 10% smaller or larger
        {
        case button_identity::smaller:
            rectangle_window[0](0) += data->width_of_client / 20;
            rectangle_window[1](0) -= data->width_of_client / 20;
            rectangle_window[0](1) += data->height_of_client / 20;
            rectangle_window[1](1) -= data->height_of_client / 20;
            break;

        case button_identity::larger:
            rectangle_window[0](0) -= data->width_of_client / 20;
            rectangle_window[1](0) += data->width_of_client / 20;
            rectangle_window[0](1) -= data->height_of_client / 20;
            rectangle_window[1](1) += data->height_of_client / 20;
            break;
        }

        move_window(window_handle,
            rectangle_window[0](0),
            rectangle_window[0](1),
            rectangle_window[1](0) - rectangle_window[0](0),
            rectangle_window[1](1) - rectangle_window[0](1), true);
    }
    break;

    case message::draw_item:
    {
        window_data* data = (window_data*)get_window_pointer(window_handle, 0);

        draw_item* item = (draw_item*)parameter2;

        // Fill area with white and Frame it black

        fill_rectangle(item->device,
            &item->bounds,
            get_standard_object(standard_brush::white));

        frame_rectangle(item->device,
            &item->bounds,
            get_standard_object(standard_brush::black));

        // draw inward and outward black triangles

        int width = item->bounds[1](0) - item->bounds[0](0);
        int height = item->bounds[1](1) - item->bounds[0](1);

        ipoint points[3];
        switch (item->control)
        {
        case button_identity::smaller:
            points[0](0) = 3 * width / 8;  points[0](1) = 1 * height / 8;
            points[1](0) = 5 * width / 8;  points[1](1) = 1 * height / 8;
            points[2](0) = 4 * width / 8;  points[2](1) = 3 * height / 8;

            triangle(item->device, points);

            points[0](0) = 7 * width / 8;  points[0](1) = 3 * height / 8;
            points[1](0) = 7 * width / 8;  points[1](1) = 5 * height / 8;
            points[2](0) = 5 * width / 8;  points[2](1) = 4 * height / 8;

            triangle(item->device, points);

            points[0](0) = 5 * width / 8;  points[0](1) = 7 * height / 8;
            points[1](0) = 3 * width / 8;  points[1](1) = 7 * height / 8;
            points[2](0) = 4 * width / 8;  points[2](1) = 5 * height / 8;

            triangle(item->device, points);

            points[0](0) = 1 * width / 8;  points[0](1) = 5 * height / 8;
            points[1](0) = 1 * width / 8;  points[1](1) = 3 * height / 8;
            points[2](0) = 3 * width / 8;  points[2](1) = 4 * height / 8;

            triangle(item->device, points);
            break;

        case button_identity::larger:
            points[0](0) = 5 * width / 8;  points[0](1) = 3 * height / 8;
            points[1](0) = 3 * width / 8;  points[1](1) = 3 * height / 8;
            points[2](0) = 4 * width / 8;  points[2](1) = 1 * height / 8;

            triangle(item->device, points);

            points[0](0) = 5 * width / 8;  points[0](1) = 5 * height / 8;
            points[1](0) = 5 * width / 8;  points[1](1) = 3 * height / 8;
            points[2](0) = 7 * width / 8;  points[2](1) = 4 * height / 8;

            triangle(item->device, points);

            points[0](0) = 3 * width / 8;  points[0](1) = 5 * height / 8;
            points[1](0) = 5 * width / 8;  points[1](1) = 5 * height / 8;
            points[2](0) = 4 * width / 8;  points[2](1) = 7 * height / 8;

            triangle(item->device, points);

            points[0](0) = 3 * width / 8;  points[0](1) = 3 * height / 8;
            points[1](0) = 3 * width / 8;  points[1](1) = 5 * height / 8;
            points[2](0) = 1 * width / 8;  points[2](1) = 4 * height / 8;

            triangle(item->device, points);
            break;
        }

        // Invert the Rectangle if the button is selected

        if (item->state & owner_draw_state::selected)
            invert_rectangle(item->device, &item->bounds);

        // draw a Focus Rectangle if the button has the Focus

        if (item->state & owner_draw_state::focus)
        {
            item->bounds[0](0) += width / 16;
            item->bounds[0](1) += height / 16;
            item->bounds[1](0) -= width / 16;
            item->bounds[1](1) -= height / 16;

            draw_focus_rectangle(item->device, &item->bounds);
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

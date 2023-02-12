// win+ -- easy_font.cpp -- Easy Font Creation

import std.core;
using namespace std;

import iplusplus;
using namespace core;

#include "EasyFont.hpp"

handle easy_create_font(handle device_context,
    const character* face_name,
    int height,
    int width,
    int attributes,
    bool logical_resolution)
{
    save_device_context(device_context);

    set_graphics_mode(device_context, graphics_mode::advanced);
    modify_world_transform(device_context, (const xform*)0, modify_transform_flag::identity);
    set_viewport_origin(device_context, 0, 0);
    set_window_origin(device_context, 0, 0);

    double horizontal_resolution, vertical_resolution;
    if (logical_resolution)
    {
        horizontal_resolution = get_device_capabilities(device_context, capability::logical_pixels_x);
        vertical_resolution = get_device_capabilities(device_context, capability::logical_pixels_y);
    }
    else
    {
        horizontal_resolution = 25.4 * get_device_capabilities(device_context, capability::horizontal_resolution) /
            get_device_capabilities(device_context, capability::horizontal_size);

        vertical_resolution = 25.4 * get_device_capabilities(device_context, capability::vertical_resolution) /
            get_device_capabilities(device_context, capability::vertical_size);
    }

    ipoint point_font(width * horizontal_resolution / 72,
        height * vertical_resolution / 72);

    device_points_to_logical_points(device_context, &point_font, 1);

    logical_font<wchar_t> font_information;

    font_information.height = -(int)(fabs((double)point_font(1)) / 10.0 + 0.5);
    font_information.weight = attributes & easy_attribute::bold ? 700 : 0;
    font_information.italic = attributes & easy_attribute::italic ? 1 : 0;
    font_information.underline = attributes & easy_attribute::underline ? 1 : 0;
    font_information.strikeout = attributes & easy_attribute::strikeout ? 1 : 0;

    copy_string(font_information.face_name, face_name);

    handle font_handle = create_font_indirect(&font_information);

    if (width != 0)
    {
        font_handle = select_object(device_context, font_handle);

        text_metrics<wchar_t> text_metrics_font;

        get_text_metrics<wchar_t>(device_context, &text_metrics_font);

        delete_object(select_object(device_context, font_handle));

        font_information.width = (int)(text_metrics_font.average_character_width *
            fabs((double)point_font(0)) / fabs((double)point_font(1)) + 0.5);

        font_handle = create_font_indirect(&font_information);
    }

    restore_device_context(device_context, -1);

    return font_handle;
}

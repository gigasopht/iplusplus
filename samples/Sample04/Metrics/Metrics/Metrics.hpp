// win+ - System Metrics - Data Table Containing Metric Names and descriptions

struct entry
{
    int index;
    const character* title;
    const character* description;
};

entry metrics[] =
{
 system_metric::screen_width,                        L"system_metric::screen_width",                     L"Screen width in pixels",
 system_metric::screen_height,                       L"system_metric::screen_height",                    L"Screen height in pixels",
 system_metric::vertical_scroll_width,               L"system_metric::vertical_scroll_width",            L"Vertical scroll arrow width",
 system_metric::horizontal_scroll_height,            L"system_metric::horizontal_scroll_height",         L"Horizontal scroll arrow height",
 system_metric::caption_height,                      L"system_metric::caption_height",                   L"Caption bar height",
 system_metric::border_width,                        L"system_metric::border_width",                     L"Window border width",
 system_metric::border_height,                       L"system_metric::border_height",                    L"Window border height",
 system_metric::fixed_frame_width,                   L"system_metric::fixed_frame_width",                L"Dialog window frame width",
 system_metric::fixed_frame_height,                  L"system_metric::fixed_frame_height",               L"Dialog window frame height",
 system_metric::vertical_slider_height,              L"system_metric::vertical_slider_height",           L"Vertical scroll thumb height",
 system_metric::horizontal_slider_width,             L"system_metric::horizontal_slider_width",          L"Horizontal scroll thumb width",
 system_metric::icon_width,                          L"system_metric::icon_width",                       L"Icon width",
 system_metric::icon_height,                         L"system_metric::icon_height",                      L"Icon height",
 system_metric::cursor_width,                        L"system_metric::cursor_width",                     L"Cursor width",
 system_metric::cursor_height,                       L"system_metric::cursor_height",                    L"Cursor height",
 system_metric::menu_height,                         L"system_metric::menu_height",                      L"Menu bar height",
 system_metric::full_screen_width,                   L"system_metric::full_screen_width",                L"Full screen client area width",
 system_metric::full_screen_height,                  L"system_metric::full_screen_height",               L"Full screen client area height",
 system_metric::kanji_window_height,                 L"system_metric::kanji_window_height",              L"Kanji window height",
 system_metric::mouse_present,                       L"system_metric::mouse_present",                    L"Mouse present flag",
 system_metric::vertical_scroll_arrow_height,        L"system_metric::vertical_scroll_arrow_height",     L"Vertical scroll arrow height",
 system_metric::horizontal_scroll_arrow_width,       L"system_metric::horizontal_scroll_arrow_width",    L"Horizontal scroll arrow width",
 system_metric::debug,                               L"system_metric::debug",                            L"Debug version flag",
 system_metric::swap_button,                         L"system_metric::swap_button",                      L"Mouse buttons swapped flag",
 system_metric::reserved1,                           L"system_metric::reserved1",                        L"Reserved",
 system_metric::reserved2,                           L"system_metric::reserved2",                        L"Reserved",
 system_metric::reserved3,                           L"system_metric::reserved3",                        L"Reserved",
 system_metric::reserved4,                           L"system_metric::reserved4",                        L"Reserved",
 system_metric::minimum_width,                       L"system_metric::minimum_width",                    L"Minimum window width",
 system_metric::minimum_height,                      L"system_metric::minimum_height",                   L"Minimum window height",
 system_metric::button_width,                        L"system_metric::button_width",                     L"Minimize/Maximize icon width",
 system_metric::button_height,                       L"system_metric::button_height",                    L"Minimize/Maximize icon height",
 system_metric::size_frame_width,                    L"system_metric::size_frame_width",                 L"Window frame width",
 system_metric::size_frame_height,                   L"system_metric::size_frame_height",                L"Window frame height",
 system_metric::minimum_track_width,                 L"system_metric::minimum_track_width",              L"Minimum window tracking width",
 system_metric::minimum_track_height,                L"system_metric::minimum_track_height",             L"Minimum window tracking height",
 system_metric::double_click_width,                  L"system_metric::double_click_width",               L"Double click x tolerance",
 system_metric::double_click_height,                 L"system_metric::double_click_height",              L"Double click y tolerance",
 system_metric::icon_spacing_width,                  L"system_metric::icon_spacing_width",               L"Horizontal icon spacing",
 system_metric::icon_spacing_height,                 L"system_metric::icon_spacing_height",              L"Vertical icon spacing",
 system_metric::menu_drop_alignment,                 L"system_metric::menu_drop_alignment",              L"Left or right menu drop",
 system_metric::pen_windows,                         L"system_metric::pen_windows",                      L"Pen extensions installed",
 system_metric::double_byte_enabled,                 L"system_metric::double_byte_enabled",              L"Double-Byte Char set enabled",
 system_metric::number_mouse_buttons,                L"system_metric::number_mouse_buttons",             L"Number of mouse buttons",
 system_metric::sounds_show,                         L"system_metric::sounds_show",                      L"Present sounds visually"
};

enum { lines = sizeof(metrics) / sizeof(metrics[0]) };

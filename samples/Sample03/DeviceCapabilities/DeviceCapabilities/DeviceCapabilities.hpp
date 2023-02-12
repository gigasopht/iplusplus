// win+ -- device capabilities display program

struct capability_entry
{
	int index;
	wchar_t* label;
	wchar_t* description;
};

capability_entry capabilities[] =
{
  capability::horizontal_size,       (wchar_t*)L"capability::horizontal_size",        (wchar_t*)L"Width in millimeters:",
  capability::vertical_size,         (wchar_t*)L"capability::vertical_size",          (wchar_t*)L"Height in millimeters:",
  capability::horizontal_resolution, (wchar_t*)L"capability::horizontal_resolution",  (wchar_t*)L"Width in pixels:",
  capability::vertical_resolution,   (wchar_t*)L"capability::vertical_resolution",    (wchar_t*)L"Height in raster lines:",
  capability::bits_pixel,            (wchar_t*)L"capability::bits_pixel",             (wchar_t*)L"Color bits per pixel:",
  capability::planes,                (wchar_t*)L"capability::planes",                 (wchar_t*)L"Number of color planes:",
  capability::brushes,               (wchar_t*)L"capability::brushes",                (wchar_t*)L"Number of device brushes:",
  capability::pens,                  (wchar_t*)L"capability::pens",                   (wchar_t*)L"Number of device pens:",
  capability::markers,               (wchar_t*)L"capability::markers",                (wchar_t*)L"Number of device markers:",
  capability::fonts,                 (wchar_t*)L"capability::fonts",                  (wchar_t*)L"Number of device fonts:",
  capability::colors,                (wchar_t*)L"capability::colors",                 (wchar_t*)L"Number of device colors:",
  capability::physical_size,         (wchar_t*)L"capability::physical_size",          (wchar_t*)L"Size of device structure:",
  capability::aspect_x,              (wchar_t*)L"capability::aspect_x",               (wchar_t*)L"Relative width of pixel:",
  capability::aspect_y,              (wchar_t*)L"capability::aspect_y",               (wchar_t*)L"Relative height of pixel:",
  capability::aspect_xy,             (wchar_t*)L"capability::aspect_xy",              (wchar_t*)L"Relative diagonal of pixel:",
  capability::logical_pixels_x,      (wchar_t*)L"capability::logical_pixels_x",       (wchar_t*)L"Horizontal dots per inch:",
  capability::logical_pixels_y,      (wchar_t*)L"capability::logical_pixels_y",       (wchar_t*)L"Vertical dots per inch:",
  capability::palette_size,          (wchar_t*)L"capability::palette_size",           (wchar_t*)L"Number of palette entries:",
  capability::palette_reserved,      (wchar_t*)L"capability::palette_reserved",       (wchar_t*)L"Reserved palette entries:",
  capability::color_resolution,      (wchar_t*)L"capability::color_resolution",       (wchar_t*)L"Actual color resolution:"
};

enum { lines = sizeof(capabilities) / sizeof(capabilities[0]) };


// EasyFont.hpp

handle easy_create_font(handle device_context,
    const character* face,
    int height,
    int width,
    int attributes,
    bool resolution);

struct easy_attribute
{
    enum
    {
        bold = 1,
        italic = 2,
        underline = 4,
        strikeout = 8
    };
};

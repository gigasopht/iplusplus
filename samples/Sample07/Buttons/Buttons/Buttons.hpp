// Win+ -- buttons.hpp -- Button Viewing Program

class button_information
{
public:
	int style;
	character* text;
};

button_information button_array[] =
{
 button_style::push_button,          (character*)L"Push Button",
 button_style::push_button_default,  (character*)L"Default Push Button",
 button_style::check_box,            (character*)L"Check Box",
 button_style::auto_check_box,       (character*)L"Automatic Check Box",
 button_style::radio_button,         (character*)L"Radio Button",
 button_style::three_state,          (character*)L"3State",
 button_style::auto_three_state,     (character*)L"Automatic 3State",
 button_style::group_box,            (character*)L"Group Box",
 button_style::auto_radio_button,    (character*)L"Automatic Radio Button",
 button_style::owner_draw,           (character*)L"Owner Draw"
};

enum { number_of_buttons = sizeof(button_array) / sizeof(button_array[0]) };

enum { button_width = 25 };

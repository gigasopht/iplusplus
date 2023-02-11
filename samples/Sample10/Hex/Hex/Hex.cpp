// Win+ -- Hex.cpp -- Hexadecimal Calculator - Strictly Ascii

import iplusplus;
using namespace iplusplus;

import std.core;
using namespace std;

#include "Hex.h"

result __stdcall client(handle, unsigned, parameter, parameter);

bool is_digit(character character_to_test)
{
    if (character_to_test >= '0' && character_to_test <= '9')
        return true;
    else
        return false;
}

bool is_hexadecimal_digit(character character_to_test)
{
    if ((character_to_test >= 'a' && character_to_test <= 'f') ||
        (character_to_test >= 'A' && character_to_test <= 'F') ||
        (character_to_test >= '0' && character_to_test <= '9'))
        return true;
    else
        return false;
}


int __stdcall WinMain(handle module_handle,
    handle reserved,
    character* command_line,
    int show_command)
{
    enum { class_name = 100 };

    window_class<character> wclass;

    wclass.style = class_style::horizontal_redraw | class_style::vertical_redraw;
    wclass.procedure = client;
    wclass.extra = 0;
    wclass.window = dialog_window_extra;
    wclass.module = module_handle;
    wclass.icon = load_icon(module_handle, (const character*)IdentityIcon);
    wclass.cursor = load_cursor((handle)null, (const character*)cursor_identity::arrow);
    wclass.brush = (handle)get_standard_object(standard_brush::white);
    wclass.name = (const character*)class_name;
    atom atom_window = register_class(&wclass);

    handle dialog_handle = create_dialog(module_handle,
        (const character*)Dialogidentity,
        0,
        (dialog_procedure)null);

    show_window(dialog_handle, show_command);

    iplusplus::queue queue_message;
    while (get_message(&queue_message))
    {
        translate_message(&queue_message);
        dispatch_message(&queue_message);
    }

    return (int)queue_message.parameter1;
}

void show_number(handle window_handle,
    unsigned number)
{
    character number_string[30];
    standard::integer_to_ascii(number, number_string, 16);
    set_child_text(window_handle,
        virtual_key::escape,
        number_string);
}

unsigned calculate(unsigned first,
    int operation,
    unsigned number)
{
    switch (operation)
    {
    case '=': return number;
    case '+': return first + number;
    case '-': return first - number;
    case '*': return first * number;
    case '&': return first & number;
    case '|': return first | number;
    case '^': return first ^ number;
    case '<': return first << number;
    case '>': return first >> number;
    case '/': return number ? first / number : 0xffffffff;
    case '%': return number ? first % number : 0xffffffff;
    default: return 0;
    }
}

inline char to_upper(char c) { if (c >= 'a' && c <= 'z') return c - 32; else return c; }

struct window_data
{
    bool decide_new;
    int operation;
    unsigned number, first;

    window_data()
    {
        decide_new = true;
        operation = '=';
    }
};

result __stdcall client(handle window_handle,
    unsigned identity,
    parameter parameter1,
    parameter parameter2)
{
    window_data* data = (window_data*)get_window_pointer(window_handle, offset::user_data);

    switch (identity)
    {
    case message::create:
    {
        window_data* data = new window_data();
        set_window_pointer(window_handle, offset::user_data, (void*)data);
    }
    break;

    case message::destroy:
        delete data;
        break;

    case message::key_down:                   // left arrow --> backspace
        if ((int)parameter1 != virtual_key::left)
            return default_window_procedure(window_handle, identity, parameter1, parameter2);
        parameter1 = (parameter)virtual_key::back;
        // fall through
    case message::character:
    {
        if ((int)(parameter1 = (parameter)to_upper((character)(int)parameter1)) == virtual_key::_return)
            parameter1 = (parameter)'=';

        handle button = get_child_window(window_handle, (int)parameter1);

        if (button != (handle)null)
        {
            send_message(button, button_message::set_state, (parameter)1, (parameter)0);
            send_message(button, button_message::set_state, (parameter)0, (parameter)0);
        }
        else
        {
            message_beep(message_box_style::icon_hand);
            return default_window_procedure(window_handle, identity, parameter1, parameter2);
        }
    }                                                    // fall through
    case message::command:
        set_focus(window_handle);

        if (low_part(parameter1) == virtual_key::back)         // backspace
            show_number(window_handle, data->number /= 16);

        else if (low_part(parameter1) == virtual_key::escape)  // Escape
            show_number(window_handle, data->number = 0);

        else if (is_hexadecimal_digit(low_part(parameter1)))    // hex digit
        {
            if (data->decide_new)
            {
                data->first = data->number;
                data->number = 0;
            }

            data->decide_new = false;

            if (data->number <= (0xffffffff >> 4))
            {
                data->number = 16 * data->number + (int)parameter1 - (is_digit((character)parameter1) ? '0' : 'A' - 10);
                show_number(window_handle, data->number);
            }
            else
                message_beep(message_box_style::icon_hand);
        }

        else  // operation
        {
            if (!data->decide_new)
            {
                data->number = calculate(data->first, data->operation, data->number);
                show_number(window_handle, data->number);
                data->decide_new = true;
                data->operation = low_part(parameter1);
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


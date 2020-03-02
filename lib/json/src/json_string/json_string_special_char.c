/*
** EPITECH PROJECT, 2020
** JSON_STRING_SPECIAL_CHAR
** File description:
** Json_string_special_char function
*/

#include <stddef.h>
#include "private_json.h"

int js_is_escape_char(char c)
{
    for (int k = 0; ESCAPE_CHARS[k]; k++)
        if (c == ESCAPE_CHARS[k])
            return (1);
    return (0);
}

char js_to_escape_char(char c)
{
    for (int k = 0; UNESCAPE_CHARS[k]; k++)
        if (c == UNESCAPE_CHARS[k])
            return (ESCAPE_CHARS[k]);
    return ('\0');
}

int js_is_unescape_char(char c)
{
    for (int k = 0; UNESCAPE_CHARS[k]; k++)
        if (c == UNESCAPE_CHARS[k])
            return (1);
    return (0);
}

char js_to_unescape_char(char c)
{
    for (int k = 0; ESCAPE_CHARS[k]; k++)
        if (c == ESCAPE_CHARS[k])
            return (UNESCAPE_CHARS[k]);
    return ('\0');
}

int js_count_special_chars(char *str)
{
    int count = 0;

    for (int k = 0; str && str[k]; k++)
        if (js_is_escape_char(str[k]))
            count++;
    return (count);
}
/*
** EPITECH PROJECT, 2020
** GET_STRING_TO_JSON_FORMAT
** File description:
** Get_string_to_json_format function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

char *get_string_to_json_format(char *str)
{
    char *parsed = NULL;
    size_t size = j_strlen(str) + js_count_special_chars(str) + 1;
    int i = 0;

    if (!str)
        return (NULL);
    parsed = malloc(sizeof(char) * (size));
    if (!parsed)
        return (NULL);
    for (int k = 0; str[k]; k++) {
        if (js_is_escape_char(str[k])) {
            parsed[i++] = '\\';
            parsed[i++] = js_to_unescape_char(str[k]);
        }
        else
            parsed[i++] = str[k];
    }
    parsed[i] = '\0';
    return (parsed);
}
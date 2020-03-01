/*
** EPITECH PROJECT, 2020
** GET_STRING_FROM_JSON_FORMAT
** File description:
** Get_string_from_json_format function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"

char *get_string_from_json_format(char *str)
{
    char *parsed = NULL;
    size_t size = j_strlen(str) + 1;
    int i = 0;

    if (!str)
        return (NULL);
    parsed = malloc(sizeof(char) * (size));
    if (!parsed)
        return (NULL);
    for (int k = 0; str[k]; k++) {
        if (str[k] == '\\' && js_is_unescape_char(str[k + 1])) {
            parsed[i++] = js_to_escape_char(str[k + 1]);
            k++;
        }
        else
            parsed[i++] = str[k];
    }
    return (parsed);
}
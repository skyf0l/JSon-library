/*
** EPITECH PROJECT, 2020
** JSON_PARSER_GET_STRING
** File description:
** Json_parser_get_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"

int jp_get_string_size(char *str)
{
    int len = 0;

    for (int k = 0; str[k]; k++) {
        if (str[k] == '\\' && js_is_unescape_char(str[k + 1])) {
            len++;
            k++;
            continue;
        }
        else if (str[k] == '\\' && !js_is_unescape_char(str[k + 1]))
            return (-1);
        if (str[k] == '"')
            return (len);
        if (str[k] != '\\' && js_is_escape_char(str[k]))
            return (-1);
        len++;
    }
    return (-1);
}

char *json_parser_get_string(char **str)
{
    int size;
    char *string = NULL;

    if (!str || !*str || *(*str)++ != '"')
        return (NULL);
    size = jp_get_string_size(*str);
    if (size == -1)
        return (NULL);
    string = malloc(sizeof(char) * (size + 1));
    for (int k = 0, i = 0; k < size; k++) {
        if (**str == '\\' && js_is_unescape_char(**str)) {
            string[i++] = js_to_escape_char(*(++*str));
            ++*str;
            continue;
        }
        string[i++] = *(*str)++;
    }
    string[size] = '\0';
    ++*str;
    return (string);
}
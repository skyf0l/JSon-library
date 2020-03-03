/*
** EPITECH PROJECT, 2020
** JSON_PARSER_GET_VALUE_STRING
** File description:
** Json_parser_get_value_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"

int jp_get_value_string_size(char *str)
{
    int len = 0;

    if (*str == '"')
        len = jp_get_string_size(&str[1]) + 2;
    for (; str && str[len] && str[len] != ',' && str[len] != '}' && str[len] != ']'; len++);
    if (!str[len])
        return (-1);
    while (len > 0 && sp_is_white_space(str[len - 1]))
        len--;
    return (len);
}

char *json_parser_get_value_string(char **str)
{
    int size;
    char *value_str = NULL;

    if (!str || !*str)
        return (NULL);
    size = jp_get_value_string_size(*str);
    value_str = malloc(sizeof(char) * (size + 1));
    if (size == -1)
        return (NULL);
    for (int k = 0; k < size; k++) {
        value_str[k] = *(*str)++;
    }
    value_str[size] = '\0';
    json_parser_skip_white_spaces(str);
    return (value_str);
}
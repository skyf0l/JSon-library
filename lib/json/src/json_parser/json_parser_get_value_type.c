/*
** EPITECH PROJECT, 2020
** JSON_PARSER_GET_VALUE_TYPE
** File description:
** Json_parser_get_value_type function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

enum json_type json_parser_get_value_type(char *str)
{
    if (!str || !*str)
        return (j_unexist);
    if (j_strcmp(str, "null") == 0)
        return (j_null);
    if (j_strcmp(str, "false") == 0 || j_strcmp(str, "true") == 0)
        return (j_bool);
    if (j_str_isint(str))
        return (j_int);
    if (str[0] == '"' && jp_get_string_size(&str[1]) != -1)
        return (j_string);
    return (j_unexist);
}
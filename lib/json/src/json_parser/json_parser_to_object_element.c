/*
** EPITECH PROJECT, 2020
** JSON_PARSER_TO_OBJECT_ELEMENT
** File description:
** Json_parser_to_object_element function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

char *jp_to_object_element_get_key(char **str)
{
    char *key = json_parser_get_string(str);

    if (!key)
        return (NULL);
    json_parser_skip_white_spaces(str);
    if (**str != ':') {
        free(key);
        return (NULL);
    }
    ++*str;
    json_parser_skip_white_spaces(str);
    return (key);
}

json_element_t *json_parser_to_object_element(char **str)
{
    char *key;
    char *value_string;
    json_element_t *je = NULL;
    enum json_type type;

    if (!str || !*str || !**str)
        return (NULL);
    key = jp_to_object_element_get_key(str);
    if (!key)
        return (NULL);
    if (**str == '[')
        return (json_parser_to_element_array(key, str));
    if (**str == '{')
        return (json_parser_to_element_object(key, str));
    value_string = json_parser_get_value_string(str);
    if (!value_string) {
        free(key);
        return (NULL);
    }
    type = json_parser_get_value_type(value_string);
    if (type == j_unexist) {
        free(key);
        free(value_string);
        return (NULL);
    }
    je = json_parser_to_element(type, key, value_string);
    free(key);
    free(value_string);
    return (je);
}
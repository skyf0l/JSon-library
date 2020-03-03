/*
** EPITECH PROJECT, 2020
** JSON_PARSER_TO_ARRAY_ELEMENT
** File description:
** Json_parser_to_array_element function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

json_element_t *json_parser_to_array_element(char **str)
{
    char *value_string = NULL;
    json_element_t *je = NULL;
    enum json_type type;

    if (!str || !*str || !**str)
        return (NULL);
    if (**str == '[')
        return (json_parser_to_element_array(NULL, str));
    if (**str == '{')
        return (json_parser_to_element_object(NULL, str));
    value_string = json_parser_get_value_string(str);
    type = json_parser_get_value_type(value_string);
    if (type == j_unexist) {
        if (value_string)
            free(value_string);
        return (NULL);
    }
    je = json_parser_to_element(type, NULL, value_string);
    free(value_string);
    return (je);
}
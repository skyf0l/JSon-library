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
    value_string = json_parser_get_value_string(str);
    if (!value_string)
        return (NULL);
    type = json_parser_get_value_type(value_string);
    if (type == j_unexist) {
        return (NULL);
        free(value_string);
    }
    je = json_element_create(NULL);
    free(value_string);
    return (je);
}
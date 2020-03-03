/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_CREATE_FROM_STRING
** File description:
** Json_object_create_from_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int jo_parse_string(json_object_t *jo, char **str)
{
    json_element_t *je = NULL;

    json_parser_skip_white_spaces(str);
    if (*(*str)++ != '{')
        return (EXIT_FAILURE);
    json_parser_skip_white_spaces(str);
    while (**str && **str != '}') {
        if (jo->elements_count)
            ++*str;
        json_parser_skip_white_spaces(str);
        je = json_parser_to_object_element(str);
        if (!je)
            return (EXIT_FAILURE);
        list_add(jo->elements, je);
        jo->elements_count++;
        json_parser_skip_white_spaces(str);
    }
    if (*(*str)++ != '}')
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

json_object_t *jo_create_from_string(char **str)
{
    json_object_t *jo;

    if (!str || !*str)
        return (NULL);
    jo = json_object_create();
    if (!jo)
        return (NULL);
    if (jo_parse_string(jo, str))
        return (json_object_destroy(jo));
    json_parser_skip_white_spaces(str);
    return (jo);
}

json_object_t *json_object_create_from_string(char *str)
{
    json_object_t *jo;

    if (!str)
        return (NULL);
    jo = json_object_create();
    if (!jo)
        return (NULL);
    if (jo_parse_string(jo, &str))
        return (json_object_destroy(jo));
    json_parser_skip_white_spaces(&str);
    if (*str)
        return (json_object_destroy(jo));
    return (jo);
}
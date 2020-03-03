/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_CREATE_FROM_STRING
** File description:
** Json_array_create_from_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "list.h"
#include "json.h"

int ja_parse_string(json_array_t *ja, char **str)
{
    json_element_t *je = NULL;

    json_parser_skip_white_spaces(str);
    if (*(*str)++ != '[')
        return (EXIT_FAILURE);
    json_parser_skip_white_spaces(str);
    while (**str && **str != ']') {
        if (ja->elements_count)
            ++*str;
        json_parser_skip_white_spaces(str);
        je = json_parser_to_array_element(str);
        if (!je)
            return (EXIT_FAILURE);
        list_add(ja->elements, je);
        ja->elements_count++;
        json_parser_skip_white_spaces(str);
    }
    if (*(*str)++ != ']')
        return (EXIT_FAILURE);
    json_parser_skip_white_spaces(str);
    return (EXIT_SUCCESS);
}

json_array_t *ja_create_from_string(char **str)
{
    json_array_t *ja;

    if (!str || !*str)
        return (NULL);
    ja = json_array_create();
    if (!ja)
        return (NULL);
    if (ja_parse_string(ja, str))
        return (json_array_destroy(ja));
    return (ja);
}

json_array_t *json_array_create_from_string(char *str)
{
    json_array_t *ja;

    if (!str)
        return (NULL);
    ja = json_array_create();
    if (!ja)
        return (NULL);
    if (ja_parse_string(ja, &str))
        return (json_array_destroy(ja));
    if (*str)
        return (json_array_destroy(ja));
    return (ja);
}
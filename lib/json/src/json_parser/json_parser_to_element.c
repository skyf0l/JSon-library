/*
** EPITECH PROJECT, 2020
** JSON_PARSER_TO_ELEMENT
** File description:
** Json_parser_to_element function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

json_element_t *json_parser_to_element(enum json_type type,
    char *key, char *value)
{
    char *tmp;

    if (type == j_null)
        return (json_element_create(key));
    if (type == j_bool)
        return (json_element_create_bool(key, j_strcmp(value, "true") == 0));
    if (type == j_string) {
        tmp = json_parser_get_string(&value);
        if (!tmp)
            return (NULL);
        return (json_element_create_string(key, tmp));
        free(tmp);
    }
    return (NULL);
}
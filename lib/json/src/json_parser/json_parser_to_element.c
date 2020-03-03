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

json_element_t *json_parser_to_element_array(char *key, char **str)
{
    json_element_t *je;
    json_array_t *ja;

    if (!str || !*str) {
        free(key);
        return (NULL);
    }
    ja = ja_create_from_string(str);
    if (!ja) {
        free(key);
        return (NULL);
    }
    je = json_element_create_json_array(key, ja);
    free(key);
    return (je);
}

json_element_t *json_parser_to_element_object(char *key, char **str)
{
    json_element_t *je;
    json_object_t *jo;

    if (!str || !*str) {
        free(key);
        return (NULL);
    }
    jo = jo_create_from_string(str);
    if (!jo) {
        free(key);
        return (NULL);
    }
    je = json_element_create_json_object(key, jo);
    free(key);
    return (je);
}

json_element_t *json_parser_to_element(enum json_type type,
    char *key, char *value)
{
    json_element_t *je = NULL;
    char *tmp;

    if (type == j_null)
        return (json_element_create(key));
    if (type == j_bool)
        return (json_element_create_bool(key, j_strcmp(value, "true") == 0));
    if (type == j_int)
        return (json_element_create_int(key, j_atoi(value)));
    if (type == j_string) {
        tmp = json_parser_get_string(&value);
        if (!tmp)
            return (NULL);
        je = json_element_create_string(key, tmp);
        free(tmp);
        return (je);
    }
    return (NULL);
}
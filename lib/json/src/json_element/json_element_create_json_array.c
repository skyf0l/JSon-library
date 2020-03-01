/*
** EPITECH PROJECT, 2020
** JSON_ELEMENT_CREATE_JSON_ARRAY
** File description:
** Json_element_create_json_array function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

json_element_t *json_element_create_json_array(char *key, json_array_t *value)
{
    json_element_t *je = json_element_create(key);

    if (!je)
        return (NULL);
    if (!value)
        return (je);
    je->type = j_array;
    je->json_array = value;
    return (je);
}
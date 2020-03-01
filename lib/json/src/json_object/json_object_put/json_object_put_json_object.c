/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_PUT_JSON_OBJECT
** File description:
** Json_object_put_json_object function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "json.h"

int json_object_put_json_object(json_object_t *jo, char *key,
    json_object_t *value)
{
    json_element_t *je = NULL;

    if (!jo || !key)
        return (EXIT_FAILURE);
    if (json_object_remove(jo, key))
        return (EXIT_FAILURE);
    je = json_element_create_json_object(key, value);
    if (!je)
        return (EXIT_FAILURE);
    if (list_add(jo->elements, je))
        return (EXIT_FAILURE);
    jo->elements_count++;
    return (EXIT_SUCCESS);
}
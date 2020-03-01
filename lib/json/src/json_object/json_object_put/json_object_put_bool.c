/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_PUT_BOOL
** File description:
** Json_object_put_bool function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int json_object_put_bool(json_object_t *jo, char *key, int value)
{
    json_element_t *je = NULL;

    if (!jo || !key)
        return (EXIT_FAILURE);
    if (json_object_remove(jo, key))
        return (EXIT_FAILURE);
    je = json_element_create_bool(key, value);
    if (!je)
        return (EXIT_FAILURE);
    if (list_add(jo->elements, je))
        return (EXIT_FAILURE);
    jo->elements_count++;
    return (EXIT_SUCCESS);
}
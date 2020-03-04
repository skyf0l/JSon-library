/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_PUT_ARRAY
** File description:
** Json_object_put_array function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int json_object_put_array(json_object_t *jo, char *key,
    json_array_t *value)
{
    json_element_t *je = NULL;

    if (!jo || !key)
        return (EXIT_FAILURE);
    if (json_object_remove(jo, key))
        return (EXIT_FAILURE);
    je = json_element_create_array(key, value);
    if (!je)
        return (EXIT_FAILURE);
    if (list_add(jo->elements, je)) {
        json_element_destroy(je);
        return (EXIT_FAILURE);
    }
    jo->elements_count++;
    return (EXIT_SUCCESS);
}
/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_IS_NULL
** File description:
** Json_object_is_null function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

int json_object_is_null(json_object_t *jo, char *key)
{
    json_element_t *je = json_object_get_element(jo, key);

    if (!je || je->type == j_null)
        return (1);
    return (0);
}
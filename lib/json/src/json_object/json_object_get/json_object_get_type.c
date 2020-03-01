/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_GET_TYPE
** File description:
** Json_object_get_type function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

enum json_type json_object_get_type(json_object_t *jo, char *key)
{
    json_element_t *je = json_object_get_element(jo, key);

    if (je)
        return (je->type);
    return (j_null);
}
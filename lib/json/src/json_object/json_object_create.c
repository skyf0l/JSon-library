/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_CREATE
** File description:
** Json_object_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "json.h"

json_object_t *json_object_create(void)
{
    json_object_t *jo = malloc(sizeof(json_object_t));

    if (!jo)
        return (NULL);
    jo->elements_count = 0;
    jo->elements = list_create((void (*)(void *))&json_element_destroy_no_rtn);
    if (!jo->elements)
        return (json_object_destroy(jo));
    return (jo);
}
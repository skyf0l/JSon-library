/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_CLONE
** File description:
** Json_object_clone function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

json_object_t *jo_clone_add_data(json_object_t *jo_clone, json_object_t *jo)
{
    simple_list_t *elements;
    json_element_t *je;
    json_element_t *je_clone;

    elements = jo->elements->list;
    while (elements) {
        je = (json_element_t *)elements->data;
        je_clone = json_element_clone(je);
        if (!je_clone)
            return (json_object_destroy(jo_clone));
        list_add(jo_clone->elements, je_clone);
        jo_clone->elements_count++;
        elements = elements->next;
    }
    return (jo_clone);
}

json_object_t *json_object_clone(json_object_t *jo)
{
    json_object_t *jo_clone = NULL;

    if (!jo)
        return (NULL);
    jo_clone = json_object_create();
    if (!jo_clone)
        return (NULL);
    return (jo_clone_add_data(jo_clone, jo));
}
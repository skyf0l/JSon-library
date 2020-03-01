/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_GET_ELEMENT
** File description:
** Json_object_get_element function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

json_element_t *json_object_get_element(json_object_t *jo, char *key)
{
    simple_list_t *elements;
    json_element_t *je;

    if (!jo || !key)
        return (NULL);
    elements = jo->elements->list;
    while (elements) {
        je = (json_element_t *)elements->data;
        if (j_strcmp(je->key, key) == 0)
            return (je);
        elements = elements->next;
    }
    return (NULL);
}
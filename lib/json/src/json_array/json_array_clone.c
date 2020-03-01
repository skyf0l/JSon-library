/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_CLONE
** File description:
** Json_array_clone function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

json_array_t *ja_clone_add_data(json_array_t *ja_clone, json_array_t *ja)
{
    simple_list_t *elements;
    json_element_t *je;
    json_element_t *je_clone;

    elements = ja->elements->list;
    while (elements) {
        je = (json_element_t *)elements->data;
        je_clone = json_element_clone(je);
        if (!je_clone)
            return (json_array_destroy(ja_clone));
        list_add(ja_clone->elements, je_clone);
        ja_clone->elements_count++;
        elements = elements->next;
    }
    return (ja_clone);
}

json_array_t *json_array_clone(json_array_t *ja)
{
    json_array_t *ja_clone = NULL;

    if (!ja)
        return (NULL);
    ja_clone = json_array_create();
    if (!ja_clone)
        return (NULL);
    return (ja_clone_add_data(ja_clone, ja));
}
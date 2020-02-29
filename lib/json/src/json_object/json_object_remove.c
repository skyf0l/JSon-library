/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_REMOVE
** File description:
** Json_object_remove function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "json.h"

int json_object_remove(json_object_t *jo, char *key)
{
    simple_list_t *elements;
    json_element_t *je;
    int id = 0;

    if (!jo || !key)
        return (EXIT_FAILURE);
    elements = jo->elements->list;
    while (elements) {
        je = (json_element_t *)elements->data;
        if (j_strcmp(je->key, key) == 0) {
            list_remove(jo->elements, id);
            jo->elements_count--;
            return (EXIT_SUCCESS);
        }
        elements = elements->next;
        id++;
    }
    return (EXIT_SUCCESS);
}
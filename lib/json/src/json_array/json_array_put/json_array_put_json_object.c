/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_PUT_JSON_OBJECT
** File description:
** Json_array_put_json_object function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int json_array_put_json_object(json_array_t *ja, json_object_t *value)
{
    return (json_array_put_json_object_at(ja, value, ja->elements_count));
}

int json_array_put_json_object_at(json_array_t *ja, json_object_t *value,
    int id)
{
    json_element_t *je = NULL;

    if (!ja || id < 0 || id > ja->elements_count)
        return (EXIT_FAILURE);
    je = json_element_create_json_object(NULL, value);
    if (!je)
        return (EXIT_FAILURE);
    if (id == ja->elements_count) {
        if (list_add(ja->elements, je)) {
            json_element_destroy(je);
            return (EXIT_FAILURE);
        }
    }
    else if (list_add_at(ja->elements, je, id)) {
        json_element_destroy(je);
        return (EXIT_FAILURE);
    }
    ja->elements_count++;
    return (EXIT_SUCCESS);
}
/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_GET_ELEMENT
** File description:
** Json_array_get_element function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

json_element_t *json_array_get_element(json_array_t *ja, int id)
{
    json_element_t *je = NULL;

    if (!ja || id < 0 || id >= ja->elements_count)
        return (NULL);
    je = (json_element_t *)list_get(ja->elements, id);
    return (je);
}
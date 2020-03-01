/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_REMOVE
** File description:
** Json_array_remove function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int json_array_remove(json_array_t *ja, int id)
{
    if (!ja || id < 0 || id >= ja->elements_count)
        return (EXIT_FAILURE);
    if (list_remove(ja->elements, id))
        return (EXIT_FAILURE);
    ja->elements_count--;
    return (EXIT_SUCCESS);
}
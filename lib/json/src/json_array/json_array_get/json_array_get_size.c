/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_GET_SIZE
** File description:
** Json_array_get_size function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "json.h"

int json_array_get_size(json_array_t *ja)
{
    if (!ja)
        return (0);
    return (ja->elements_count);
}
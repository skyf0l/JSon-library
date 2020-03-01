/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_GET_SIZE
** File description:
** Json_object_get_size function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

int json_object_get_size(json_object_t *jo)
{
    if (!jo)
        return (0);
    return (jo->elements_count);
}
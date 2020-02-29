/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_DESTROY
** File description:
** Json_object_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

void *json_object_destroy(json_object_t *jo)
{
    if (!jo)
        return (NULL);
    free(jo);
    return (NULL);
}
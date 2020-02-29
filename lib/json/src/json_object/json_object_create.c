/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_CREATE
** File description:
** Json_object_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

json_object_t *json_object_create(void)
{
    json_object_t *jo = malloc(sizeof(json_object_t));

    if (!jo)
        return (NULL);
    return (jo);
}
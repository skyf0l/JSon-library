/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_CREATE_FROM_STRING
** File description:
** Json_object_create_from_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

json_object_t *json_object_create_from_string(char *str)
{
    json_object_t *jo;

    if (!str)
        return (NULL);
    jo = json_object_create();
    if (!jo)
        return (NULL);
    return (jo);
}
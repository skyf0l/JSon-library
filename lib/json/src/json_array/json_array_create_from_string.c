/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_CREATE_FROM_STRING
** File description:
** Json_array_create_from_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

json_array_t *json_array_create_from_string(char *str)
{
    json_array_t *ja;

    if (!str)
        return (NULL);
    ja = json_array_create();
    if (!ja)
        return (NULL);
    return (ja);
}
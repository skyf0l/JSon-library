/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_TO_STRING
** File description:
** Json_object_to_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "json.h"

char *json_object_to_string(json_object_t *jo)
{
    char *str = NULL;

    if (!jo)
        return (NULL);
    if (json_to_string_append(&str, "{"))
        return (NULL);
    if (json_to_string_append(&str, "}"))
        return (NULL);
    return (str);
}
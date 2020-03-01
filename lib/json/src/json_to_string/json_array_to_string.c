/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_TO_STRING
** File description:
** Json_array_to_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

char *json_array_to_string(json_array_t *ja)
{
    char *str = NULL;

    if (!ja)
        return (NULL);
    if (json_to_string_append(&str, "["))
        return (NULL);
    if (json_to_string_append(&str, "]"))
        return (NULL);
    return (str);
}
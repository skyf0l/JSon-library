/*
** EPITECH PROJECT, 2020
** JSON_KEY_TO_STRING
** File description:
** Json_key_to_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

char *json_key_to_string(char *key)
{
    char *str = NULL;

    if (!key)
        return (NULL);
    if (json_to_string_append(&str, "\""))
        return (NULL);
    if (json_to_string_append(&str, key))
        return (NULL);
    if (json_to_string_append(&str, "\""))
        return (NULL);
    return (str);
}
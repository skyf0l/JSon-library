/*
** EPITECH PROJECT, 2020
** JSON_KEY_TO_STRING
** File description:
** Json_key_to_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

char *json_key_to_string(char *key)
{
    char *str = NULL;
    char *tmp;

    if (!key)
        return (NULL);
    if (json_to_string_append(&str, "\""))
        return (NULL);
    tmp = get_string_to_json_format(key);
    if (!tmp) {
        free(str);
        return (NULL);
    }
    if (json_to_string_append(&str, tmp)) {
        free(tmp);
        return (NULL);
    }
    free(tmp);
    if (json_to_string_append(&str, "\""))
        return (NULL);
    return (str);
}
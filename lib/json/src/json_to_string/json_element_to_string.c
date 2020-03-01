/*
** EPITECH PROJECT, 2020
** JSON_ELEMENT_TO_STRING
** File description:
** Json_element_to_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

char *je_parse_string(char *str)
{
    char *parsed = NULL;
    char *tmp = get_string_to_json_format(str);

    if (!tmp)
        return (NULL);
    if (json_to_string_append(&parsed, "\"")) {
        free(tmp);
        return (NULL);
    }
    if (json_to_string_append(&parsed, tmp)) {
        free(tmp);
        return (NULL);
    }
    free(tmp);
    if (json_to_string_append(&parsed, "\""))
        return (NULL);
    return (parsed);
}

char *je_to_string(json_element_t *je, char *str)
{
    char *tmp = NULL;

    if (je->type == j_int)
        tmp = j_itoa(je->json_int);
    if (je->type == j_string)
        tmp = je_parse_string(je->json_string);
    if (je->type == j_array)
        tmp = json_array_to_string(je->json_array);
    if (je->type == j_object)
        tmp = json_object_to_string(je->json_object);
    if (!tmp)
        return (str);
    if (json_to_string_append(&str, tmp)) {
        free(tmp);
        return (NULL);
    }
    free(tmp);
    return (str);
}

char *json_element_to_string(json_element_t *je)
{
    char *str = NULL;

    if (!je)
        return (NULL);
    if (je->key && !(str = json_key_to_string(je->key)))
        return (NULL);
    if (je->key && json_to_string_append(&str, ":"))
        return (NULL);
    if (je->type == j_null)
        if (json_to_string_append(&str, "null"))
            return (NULL);
    if (je->type == j_bool)
        if (json_to_string_append(&str, je->json_int ? "true" : "false"))
            return (NULL);
    if (je->type != j_null && je->type != j_bool)
        return (je_to_string(je, str));
    return (str);
}
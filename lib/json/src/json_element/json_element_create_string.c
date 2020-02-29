/*
** EPITECH PROJECT, 2020
** JSON_ELEMENT_CREATE_STRING
** File description:
** Json_element_create_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

json_element_t *json_element_create_string(char *key, char *value)
{
    json_element_t *je = json_element_create(key);

    if (!je)
        return (NULL);
    if (!value)
        return (je);
    je->type = j_string;
    je->json_string = j_strclone(value);
    if (!je->json_string)
        return (json_element_destroy(je));
    return (je);
}
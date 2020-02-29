/*
** EPITECH PROJECT, 2020
** JSON_ELEMENT_CREATE
** File description:
** Json_element_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

json_element_t *json_element_create(char *key)
{
    json_element_t *je;

    je = malloc(sizeof(json_element_t));
    if (!je)
        return (NULL);
    je->type = j_null;
    je->key = NULL;
    je->json_array = NULL;
    je->json_object = NULL;
    je->json_int = 0;
    je->json_string = NULL;
    if (key) {
        je->key = j_strclone(key);
        if (!je->key)
            return (json_element_destroy(je));
    }
    return (je);
}
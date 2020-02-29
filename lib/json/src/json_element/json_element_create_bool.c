/*
** EPITECH PROJECT, 2020
** JSON_ELEMENT_CREATE_BOOL
** File description:
** Json_element_create_bool function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

json_element_t *json_element_create_bool(char *key, int value)
{
    json_element_t *je = json_element_create(key);

    if (!je)
        return (NULL);
    je->type = j_bool;
    je->json_int = value ? 1 : 0;
    return (je);
}
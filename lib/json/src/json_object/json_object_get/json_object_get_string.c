/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_GET_STRING
** File description:
** Json_object_get_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

char *json_object_get_string(json_object_t *jo, char *key)
{
    json_element_t *je = json_object_get_element(jo, key);

    if (je)
        return (je->json_string);
    return (NULL);
}
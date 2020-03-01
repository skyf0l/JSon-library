/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_GET_INT
** File description:
** Json_object_get_int function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

int json_object_get_int(json_object_t *jo, char *key)
{
    json_element_t *je = json_object_get_element(jo, key);

    if (je)
        return (je->json_int);
    return (0);
}
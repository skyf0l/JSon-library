/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_GET_JSON_OBJECT
** File description:
** Json_object_get_json_object function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

json_object_t *json_object_get_json_object(json_object_t *jo, char *key)
{
    json_element_t *je = json_object_get_element(jo, key);

    if (je)
        return (je->json_object);
    return (NULL);
}
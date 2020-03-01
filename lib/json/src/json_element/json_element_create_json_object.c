/*
** EPITECH PROJECT, 2020
** JSON_ELEMENT_CREATE_JSON_OBJECT
** File description:
** Json_element_create_json_object function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

json_element_t *json_element_create_json_object(char *key,
    json_object_t *value)
{
    json_element_t *je = json_element_create(key);

    if (!je)
        return (NULL);
    if (!value)
        return (je);
    je->type = j_object;
    je->json_object = value;
    return (je);
}
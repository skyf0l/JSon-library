/*
** EPITECH PROJECT, 2020
** JSON_ELEMENT_CLONE
** File description:
** Json_element_clone function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

json_element_t *je_clone_json_array(json_element_t *je)
{
    json_array_t *ja_clone = json_array_clone(je->json_array);

    if (!ja_clone)
        return (NULL);
    json_element_t *je_clone = json_element_create_json_array(je->key,
        ja_clone);
    return (je_clone);
}

json_element_t *je_clone_json_object(json_element_t *je)
{
    json_object_t *jo_clone = json_object_clone(je->json_object);

    if (!jo_clone)
        return (NULL);
    json_element_t *je_clone = json_element_create_json_object(je->key,
        jo_clone);
    return (je_clone);
}

json_element_t *json_element_clone(json_element_t *je)
{
    json_element_t *je_clone = NULL;

    if (!je)
        return (NULL);
    if (je->type == j_null)
        je_clone = json_element_create(je->key);
    if (je->type == j_bool)
        je_clone = json_element_create_bool(je->key, je->json_int);
    if (je->type == j_int)
        je_clone = json_element_create_int(je->key, je->json_int);
    if (je->type == j_string)
        je_clone = json_element_create_string(je->key, je->json_string);
    if (je->type == j_array)
        return (je_clone_json_array(je));
    if (je->type == j_object)
        return (je_clone_json_object(je));
    return (je_clone);
}
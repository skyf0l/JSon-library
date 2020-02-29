/*
** EPITECH PROJECT, 2020
** JSON_ELEMENT_DESTROY
** File description:
** Json_element_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

void *json_element_destroy(json_element_t *je)
{
    if (!je)
        return (NULL);
    if (je->key)
        free(je->key);
    if (je->type == j_array && je->json_array)
        json_array_destroy(je->json_array);
    if (je->type == j_object && je->json_object)
        json_object_destroy(je->json_object);
    if (je->type == j_string && je->json_string)
        free(je->json_string);
    free(je);
    return (NULL);
}
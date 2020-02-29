/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_CREATE
** File description:
** Json_array_create function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "json.h"

json_array_t *json_array_create(void)
{
    json_array_t *ja = malloc(sizeof(json_array_t));

    if (!ja)
        return (NULL);
    ja->elements_count = 0;
    ja->elements = list_create(NULL);
    if (!ja->elements)
        return (json_array_destroy(ja));
    return (ja);
}
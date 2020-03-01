/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_CLONE
** File description:
** Json_array_clone function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "json.h"

json_array_t *json_array_clone(json_array_t *ja)
{
    json_array_t *ja_clone = NULL;

    if (!ja)
        return (NULL);
    ja_clone = json_array_create();
    if (!ja_clone)
        return (NULL);
    return (ja_clone);
}
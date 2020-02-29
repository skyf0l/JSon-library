/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_DESTROY
** File description:
** Json_array_destroy function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

void *json_array_destroy(json_array_t *ja)
{
    if (!ja)
        return (NULL);
    free(ja);
    return (NULL);
}
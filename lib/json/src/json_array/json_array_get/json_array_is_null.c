/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_IS_NULL
** File description:
** Json_array_is_null function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

int json_array_is_null(json_array_t *ja, int id)
{
    json_element_t *je = json_array_get_element(ja, id);

    if (!je || je->type == j_null)
        return (1);
    return (0);
}
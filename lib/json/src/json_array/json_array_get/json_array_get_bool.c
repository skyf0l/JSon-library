/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_GET_BOOL
** File description:
** Json_array_get_bool function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

int json_array_get_bool(json_array_t *ja, int id)
{
    json_element_t *je = json_array_get_element(ja, id);

    if (je)
        return (je->json_int);
    return (0);
}
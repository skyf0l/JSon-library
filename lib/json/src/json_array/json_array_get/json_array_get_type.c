/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_GET_TYPE
** File description:
** Json_array_get_type function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

enum json_type json_array_get_type(json_array_t *ja, int id)
{
    json_element_t *je = json_array_get_element(ja, id);

    if (je)
        return (je->type);
    return (j_null);
}
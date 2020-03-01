/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_GET_JSON_ARRAY
** File description:
** Json_array_get_json_array function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

json_array_t *json_array_get_json_array(json_array_t *ja, int id)
{
    json_element_t *je = json_array_get_element(ja, id);

    if (je)
        return (je->json_array);
    return (NULL);
}
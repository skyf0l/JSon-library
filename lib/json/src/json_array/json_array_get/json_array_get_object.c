/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_GET_OBJECT
** File description:
** Json_array_get_object function
*/

#include <stddef.h>
#include <stdlib.h>
#include "private_json.h"
#include "json.h"

json_object_t *json_array_get_object(json_array_t *ja, int id)
{
    json_element_t *je = json_array_get_element(ja, id);

    if (je)
        return (je->json_object);
    return (NULL);
}
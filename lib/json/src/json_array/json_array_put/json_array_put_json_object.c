/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_PUT_JSON_OBJECT
** File description:
** Json_array_put_json_object function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int json_array_put_json_object(json_array_t *ja, json_object_t *value)
{
    return (json_array_put_json_object_at(ja, value, ja->elements_count));
}

int json_array_put_json_object_at(json_array_t *ja, json_object_t *value,
    int id)
{
    return (EXIT_SUCCESS);
}
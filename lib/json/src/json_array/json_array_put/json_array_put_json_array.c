/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_PUT_JSON_ARRAY
** File description:
** Json_array_put_json_array function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int json_array_put_json_array(json_array_t *ja, json_array_t *value)
{
    return (json_array_put_json_array_at(ja, value, ja->elements_count));
}

int json_array_put_json_array_at(json_array_t *ja, json_array_t *value, int id)
{
    return (EXIT_SUCCESS);
}
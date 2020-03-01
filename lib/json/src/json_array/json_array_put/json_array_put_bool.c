/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_PUT_BOOL
** File description:
** Json_array_put_bool function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int json_array_put_bool(json_array_t *ja, int value)
{
    return (json_array_put_bool_at(ja, value, ja->elements_count));
}

int json_array_put_bool_at(json_array_t *ja, int value, int id)
{
    return (EXIT_SUCCESS);
}
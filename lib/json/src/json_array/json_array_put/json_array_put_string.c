/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_PUT_STRING
** File description:
** Json_array_put_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int json_array_put_string(json_array_t *ja, char *value)
{
    return (json_array_put_string_at(ja, value, ja->elements_count));
}

int json_array_put_string_at(json_array_t *ja, char *value, int id)
{
    return (EXIT_SUCCESS);
}
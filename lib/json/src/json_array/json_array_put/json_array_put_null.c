/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_PUT_NULL
** File description:
** Json_array_put_null function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

int json_array_put_null(json_array_t *ja)
{
    return (json_array_put_null_at(ja, ja->elements_count));
}

int json_array_put_null_at(json_array_t *ja, int id)
{
    return (EXIT_SUCCESS);
}
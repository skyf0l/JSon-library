/*
** EPITECH PROJECT, 2020
** JSON_ELEMENT_CREATE_INT
** File description:
** Json_element_create_int function
*/

#include <stddef.h>
#include <stdlib.h>
#include "json.h"

json_element_t *json_element_create_int(char *key, int value)
{
    json_element_t *je = json_element_create(key);

    if (!je)
        return (NULL);
    je->type = j_int;
    je->json_int = value;
    return (je);
}
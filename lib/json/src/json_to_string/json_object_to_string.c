/*
** EPITECH PROJECT, 2020
** JSON_OBJECT_TO_STRING
** File description:
** Json_object_to_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

char *jo_to_string_add_element(char *str, json_element_t *je)
{
    char *tmp = json_element_to_string(je);

    if (!tmp) {
        free(str);
        return (NULL);
    }
    if (json_to_string_append(&str, tmp)) {
        free(tmp);
        return (NULL);
    }
    free(tmp);
    return (str);
}

char *jo_to_string_add_elements(json_object_t *jo, char *str)
{
    simple_list_t *elements;
    json_element_t *je;
    int id = 0;

    elements = jo->elements->list;
    while (elements) {
        je = (json_element_t *)elements->data;
        if (id && json_to_string_append(&str, ", "))
            return (NULL);
        str = jo_to_string_add_element(str, je);
        if (!str)
            return (NULL);
        elements = elements->next;
        id++;
    }
    return (str);
}

char *json_object_to_string(json_object_t *jo)
{
    char *str = NULL;

    if (!jo)
        return (NULL);
    if (json_to_string_append(&str, "{"))
        return (NULL);
    str = jo_to_string_add_elements(jo, str);
    if (!str)
        return (NULL);
    if (json_to_string_append(&str, "}"))
        return (NULL);
    return (str);
}
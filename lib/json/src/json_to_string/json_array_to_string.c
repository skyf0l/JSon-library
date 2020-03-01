/*
** EPITECH PROJECT, 2020
** JSON_ARRAY_TO_STRING
** File description:
** Json_array_to_string function
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "private_json.h"
#include "json.h"

char *ja_to_string_add_element(char *str, json_element_t *je)
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

char *ja_to_string_add_elements(json_array_t *ja, char *str)
{
    simple_list_t *elements;
    json_element_t *je;
    int id = 0;

    elements = ja->elements->list;
    while (elements) {
        je = (json_element_t *)elements->data;
        if (id && json_to_string_append(&str, ", "))
            return (NULL);
        str = ja_to_string_add_element(str, je);
        if (!str)
            return (NULL);
        elements = elements->next;
        id++;
    }
    return (str);
}

char *json_array_to_string(json_array_t *ja)
{
    char *str = NULL;

    if (!ja)
        return (NULL);
    if (json_to_string_append(&str, "["))
        return (NULL);
    str = ja_to_string_add_elements(ja, str);
    if (!str)
        return (NULL);
    if (json_to_string_append(&str, "]"))
        return (NULL);
    return (str);
}
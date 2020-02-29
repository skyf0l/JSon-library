/*
** EPITECH PROJECT, 2020
** JSON_TO_STRING_APPEND
** File description:
** Json_to_string_append function
*/

#include <stddef.h>
#include <stdlib.h>

size_t j_strlen(char const *str);

int json_to_string_append(char **str, char *to_add)
{
    char *tmp = *str;
    size_t size = j_strlen(tmp) + j_strlen(to_add) + 1;
    size_t k = 0;

    *str = malloc(sizeof(char) * size);
    if (!*str) {
        if (tmp)
            free(tmp);
        return (EXIT_FAILURE);
    }
    for (; tmp && tmp[k]; k++)
        (*str)[k] = tmp[k];
    for (size_t i = 0; to_add && to_add[i]; k++, i++)
        (*str)[k] = to_add[i];
    (*str)[k] = '\0';
    if (tmp)
        free(tmp);
    return (EXIT_SUCCESS);
}
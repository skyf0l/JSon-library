/*
** EPITECH PROJECT, 2020
** JSON_PARSER_SKIP_WHITE_SPACES
** File description:
** Json_parser_skip_white_spaces function
*/

#include <stddef.h>
#include "private_json.h"

int sp_is_white_space(char c)
{
    for (int k = 0; WHITE_SPACES[k]; k++)
        if (c == WHITE_SPACES[k])
            return (1);
    return (0);
}

void json_parser_skip_white_spaces(char **str)
{
    if (!(*str))
        return;
    while (sp_is_white_space(**str))
        (*str)++;
}
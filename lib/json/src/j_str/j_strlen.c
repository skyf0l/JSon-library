/*
** EPITECH PROJECT, 2020
** J_STRLEN
** File description:
** J_strlen function
*/

#include <stddef.h>

size_t j_strlen(char const *str)
{
    size_t len = 0;

    for (; str && str[len]; len++);
    return (len);
}
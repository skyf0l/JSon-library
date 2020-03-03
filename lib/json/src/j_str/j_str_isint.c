/*
** EPITECH PROJECT, 2020
** J_STR_ISINT
** File description:
** J_str_isint function
*/

#include <stddef.h>

size_t j_strlen(char const *str);

int j_strcmp(char const *s1, char const *s2);

int j_str_isint(char *str)
{
    if (!str || !*str)
        return (0);
    if ((*str == '-' && j_strlen(str) > 11)
        || (*str != '-' && j_strlen(str) > 10))
        return (0);
    for (int k = (*str == '-'); str[k]; k++)
        if (str[k] < '0' || str[k] > '9')
            return (0);
    if ((*str == '-' && j_strlen(str) < 10)
        || (*str != '-' && j_strlen(str) < 9))
        return (1);
    if (*str == '-' && j_strcmp(&str[1], "2147483648") > 0)
        return (0);
    else if (*str != '-' && j_strcmp(str, "2147483647") > 0)
        return (0);
    return (1);
}
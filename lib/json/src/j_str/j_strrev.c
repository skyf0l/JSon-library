/*
** EPITECH PROJECT, 2020
** J_STRREV
** File description:
** J_strrev function
*/

#include <stddef.h>

size_t j_strlen(char const *str);

char *j_strrev(char *str)
{
    size_t size = j_strlen(str);
    int start = 0;
    int end = size -1;
    char tmp;

    while (start < end) {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
    return (str);
}
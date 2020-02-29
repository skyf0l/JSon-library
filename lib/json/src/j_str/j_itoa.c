/*
** EPITECH PROJECT, 2020
** J_ITOA
** File description:
** J_itoa function
*/

#include <stddef.h>
#include <stdlib.h>

char *j_strrev(char *str);

char *j_itoa(int n)
{
    char *str = malloc(sizeof(char) * 12);
    int is_negative = n < 0;
    int rem;
    int k = 0;

    if (n == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    while (n != 0) {
        rem = n % 10;
        str[k++] = '0' + (rem < 0 ? -rem : rem);
        n /= 10;
    }
    if (is_negative)
        str[k++] = '-';
    str[k] = '\0';
    return (j_strrev(str));
}
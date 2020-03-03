/*
** EPITECH PROJECT, 2020
** J_ATOI
** File description:
** J_atoi function
*/

int j_atoi(char *str)
{
    int number = 0;
    int is_neg = str[0] == '-';
    int i = str[0] == '-';

    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        number *= 10;
        if (is_neg)
            number -= str[i] - 48;
        else
            number += str[i] - 48;
    }
    return (number);
}
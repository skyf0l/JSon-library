/*
** EPITECH PROJECT, 2020
** TESTS_JSON_ARRAY_TO_STRING
** File description:
** Test json_array_to_string
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_array_to_string, null)
{
    json_array_t *ja = NULL;
    char *str;

    str = json_array_to_string(ja);
    cr_assert_null(str);
}

Test(json_array_to_string, empty)
{
    json_array_t *ja = json_array_create();
    char *expect = "[]";
    char *str;

    str = json_array_to_string(ja);
    cr_assert_str_eq(str, expect);
    json_array_destroy(ja);
    free(str);
}
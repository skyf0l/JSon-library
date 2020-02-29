/*
** EPITECH PROJECT, 2020
** TESTS_JSON_STRING
** File description:
** Test json_string
*/

#include <criterion/criterion.h>
#include "json.h"

Test(get_string_from_json_format, null)
{
    char *from = NULL;
    char *get = get_string_from_json_format(from);

    cr_assert_null(get);
}

Test(get_string_to_json_format, null)
{
    char *to = NULL;
    char *get = get_string_to_json_format(to);

    cr_assert_null(get);
}

Test(get_string_from_json_format, basic)
{
    char *from = "basic";
    char *expected = "basic";
    char *get = get_string_from_json_format(from);

    cr_assert_str_eq(get, expected);
    free(get);
}

Test(get_string_to_json_format, basic)
{
    char *to = "basic";
    char *expected = "basic";
    char *get = get_string_to_json_format(to);

    cr_assert_str_eq(get, expected);
    free(get);
}

Test(get_string_from_json_format, all_escape)
{
    char *from = "\\b\\f\\n\\r\\t\\\"\\\\";
    char *expected = "\b\f\n\r\t\"\\";
    char *get = get_string_from_json_format(from);

    cr_assert_str_eq(get, expected);
    free(get);
}

Test(get_string_to_json_format, all_escape)
{
    char *to = "\b\f\n\r\t\"\\";
    char *expected = "\\b\\f\\n\\r\\t\\\"\\\\";
    char *get = get_string_to_json_format(to);

    cr_assert_str_eq(get, expected);
    free(get);
}
/*
** EPITECH PROJECT, 2020
** TESTS_JSON_OBJECT_TO_STRING
** File description:
** Test json_object_to_string
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_object_to_string, null)
{
    json_object_t *jo = NULL;
    char *str;

    str = json_object_to_string(jo);
    cr_assert_null(str);
}

Test(json_object_to_string, empty)
{
    json_object_t *jo = json_object_create();
    char *expect = "{}";
    char *str;

    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}
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

Test(json_array_to_string, one_j_null)
{
    json_array_t *ja = json_array_create();
    char *expect = "[null]";
    char *str;

    json_array_put_null(ja);
    str = json_array_to_string(ja);
    cr_assert_str_eq(str, expect);
    json_array_destroy(ja);
    free(str);
}

Test(json_array_to_string, multi_1)
{
    json_array_t *ja = json_array_create();
    char *expect = "[null, 5, false]";
    char *str;

    json_array_put_null(ja);
    json_array_put_bool_at(ja, 0, 1);
    json_array_put_int_at(ja, 5, 1);
    str = json_array_to_string(ja);
    cr_assert_str_eq(str, expect);
    json_array_destroy(ja);
    free(str);
}

Test(json_array_to_string, multi_2)
{
    json_array_t *ja = json_array_create();
    char *expect = "[null, [null, 5, {}], 5, {}]";
    char *str;

    json_array_put_null(ja);
    json_array_put_json_object(ja, json_object_create());
    json_array_put_int_at(ja, 5, 1);
    json_array_put_json_array_at(ja, json_array_clone(ja), 1);
    str = json_array_to_string(ja);
    cr_assert_str_eq(str, expect);
    json_array_destroy(ja);
    free(str);
}
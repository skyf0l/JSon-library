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

Test(json_object_to_string, one_j_null)
{
    char *key = "key";
    json_object_t *jo = json_object_create();
    char *expect = "{\"key\":null}";
    char *str;

    json_object_put_null(jo, key);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, one_j_bool_0)
{
    char *key = "key";
    int value = 0;
    json_object_t *jo = json_object_create();
    char *expect = "{\"key\":false}";
    char *str;

    json_object_put_bool(jo, key, value);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, one_j_bool_1)
{
    char *key = "key";
    int value = 1;
    json_object_t *jo = json_object_create();
    char *expect = "{\"key\":true}";
    char *str;

    json_object_put_bool(jo, key, value);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, one_j_int_0)
{
    char *key = "key";
    int value = 144;
    json_object_t *jo = json_object_create();
    char *expect = "{\"key\":144}";
    char *str;

    json_object_put_int(jo, key, value);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, one_j_int_1)
{
    char *key = "key";
    int value = 2147483647;
    json_object_t *jo = json_object_create();
    char *expect = "{\"key\":2147483647}";
    char *str;

    json_object_put_int(jo, key, value);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, one_j_int_2)
{
    char *key = "key";
    int value = -2147483648;
    json_object_t *jo = json_object_create();
    char *expect = "{\"key\":-2147483648}";
    char *str;

    json_object_put_int(jo, key, value);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, one_j_string)
{
    char *key = "key";
    char *value = "a random string";
    json_object_t *jo = json_object_create();
    char *expect = "{\"key\":\"a random string\"}";
    char *str;

    json_object_put_string(jo, key, value);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, one_j_string_escape)
{
    char *key = "key";
    char *value = "\b\f\n\r\t\"\\";
    json_object_t *jo = json_object_create();
    char *expect = "{\"key\":\"\\b\\f\\n\\r\\t\\\"\\\\\"}";
    char *str;

    json_object_put_string(jo, key, value);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}
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

Test(json_object_to_string, multi_0)
{
    json_object_t *jo = json_object_create();
    char *expect = "{\"key1\":null, \"key2\":null}";
    char *str;

    json_object_put_null(jo, "key1");
    json_object_put_null(jo, "key2");
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, multi_1)
{
    json_object_t *jo = json_object_create();
    char *expect = "{\"key1\":null, \"key3\":null, \"key2\":null}";
    char *str;

    json_object_put_null(jo, "key1");
    json_object_put_null(jo, "key3");
    json_object_put_null(jo, "key2");
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, multi_2)
{
    json_object_t *jo = json_object_create();
    char *expect = "{\"key1\":null, \"key3\":true, \"key2\":144, \"4\":\"k\"}";
    char *str;

    json_object_put_null(jo, "key1");
    json_object_put_bool(jo, "key3", 1);
    json_object_put_int(jo, "key2", 144);
    json_object_put_string(jo, "4", "k");
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, multi_3)
{
    json_object_t *jo = json_object_create();
    char *expect = "{\"\\n\":null, \"\":true, \"k\":144}";
    char *str;

    json_object_put_null(jo, "\n");
    json_object_put_bool(jo, "", 1);
    json_object_put_int(jo, "k", 144);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, json_object_inside)
{
    json_object_t *jo = json_object_create();
    char *expect = "{\"jo\":{}}";
    char *str;

    json_object_put_json_object(jo, "jo", json_object_create());
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, fill_json_object_inside_before)
{
    json_object_t *jo = json_object_create();
    json_object_t *jo1 = json_object_create();
    char *expect = "{\"jo1\":{\"jo\":{}, \"bool\":true}}";
    char *str;

    json_object_put_json_object(jo1, "jo", json_object_create());
    json_object_put_bool(jo1, "bool", 1);
    json_object_put_json_object(jo, "jo1", jo1);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, fill_json_object_inside_after)
{
    json_object_t *jo = json_object_create();
    json_object_t *jo1 = json_object_create();
    char *expect = "{\"jo1\":{\"jo\":{}, \"bool\":true}}";
    char *str;

    json_object_put_json_object(jo, "jo1", jo1);
    json_object_put_json_object(jo1, "jo", json_object_create());
    json_object_put_bool(jo1, "bool", 1);
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}

Test(json_object_to_string, json_object_array_inside)
{
    json_object_t *jo = json_object_create();
    char *expect = "{\"jo\":{}, \"ja\":[]}";
    char *str;

    json_object_put_json_object(jo, "jo", json_object_create());
    json_object_put_json_array(jo, "ja", json_array_create());
    str = json_object_to_string(jo);
    cr_assert_str_eq(str, expect);
    json_object_destroy(jo);
    free(str);
}
/*
** EPITECH PROJECT, 2020
** TESTS_JSON_OBJECT_GET
** File description:
** Test json_object_get
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_object_get_size, basic)
{
    json_object_t *jo = json_object_create();

    cr_assert_eq(json_object_get_size(jo), 0);
    json_object_put_null(jo, "key1");
    cr_assert_eq(json_object_get_size(jo), 1);
    json_object_put_int(jo, "key1", 144);
    cr_assert_eq(json_object_get_size(jo), 1);
    json_object_put_string(jo, "key2", "string");
    cr_assert_eq(json_object_get_size(jo), 2);
    json_object_destroy(jo);
}

Test(json_object_get_type, null)
{
    char *key = NULL;
    json_object_t *jo = json_object_create();
    enum json_type type;

    type = json_object_get_type(jo, key);
    cr_assert_eq(type, j_null);
    json_object_destroy(jo);
}

Test(json_object_get_type, j_null)
{
    char *key = "key";
    json_object_t *jo = json_object_create();
    enum json_type type;

    json_object_put_null(jo, key);
    type = json_object_get_type(jo, key);
    cr_assert_eq(type, j_null);
    json_object_destroy(jo);
}

Test(json_object_get_type, j_bool)
{
    char *key = "key";
    int value = 0;
    json_object_t *jo = json_object_create();
    enum json_type type;

    json_object_put_bool(jo, key, value);
    type = json_object_get_type(jo, key);
    cr_assert_eq(type, j_bool);
    json_object_destroy(jo);
}

Test(json_object_get_type, j_int)
{
    char *key = "key";
    int value = 0;
    json_object_t *jo = json_object_create();
    enum json_type type;

    json_object_put_int(jo, key, value);
    type = json_object_get_type(jo, key);
    cr_assert_eq(type, j_int);
    json_object_destroy(jo);
}

Test(json_object_get_bool, j_bool_0)
{
    char *key = "key";
    int value = 0;
    json_object_t *jo = json_object_create();
    int rtn_value;

    json_object_put_bool(jo, key, value);
    rtn_value = json_object_get_bool(jo, key);
    cr_assert_eq(rtn_value, value);
    json_object_destroy(jo);
}

Test(json_object_get_bool, j_bool_1)
{
    char *key = "key";
    int value = 1;
    json_object_t *jo = json_object_create();
    int rtn_value;

    json_object_put_bool(jo, key, value);
    rtn_value = json_object_get_bool(jo, key);
    cr_assert_eq(rtn_value, value);
    json_object_destroy(jo);
}

Test(json_object_get_int, j_int_0)
{
    char *key = "key";
    int value = 144;
    json_object_t *jo = json_object_create();
    int rtn_value;

    json_object_put_int(jo, key, value);
    rtn_value = json_object_get_int(jo, key);
    cr_assert_eq(rtn_value, value);
    json_object_destroy(jo);
}

Test(json_object_get_int, j_int_1)
{
    char *key = "key";
    int value = -2147483648;
    json_object_t *jo = json_object_create();
    int rtn_value;

    json_object_put_int(jo, key, value);
    rtn_value = json_object_get_int(jo, key);
    cr_assert_eq(rtn_value, value);
    json_object_destroy(jo);
}

Test(json_object_get_string, j_string_null)
{
    char *key = "key";
    char *value = NULL;
    json_object_t *jo = json_object_create();
    char *rtn_value;

    json_object_put_string(jo, key, value);
    rtn_value = json_object_get_string(jo, key);
    cr_assert_null(rtn_value);
    json_object_destroy(jo);
}

Test(json_object_get_string, j_string)
{
    char *key = "key";
    char *value = "hello world!";
    json_object_t *jo = json_object_create();
    char *rtn_value;

    json_object_put_string(jo, key, value);
    rtn_value = json_object_get_string(jo, key);
    cr_assert_str_eq(rtn_value, value);
    json_object_destroy(jo);
}

Test(json_object_get_string, j_string_escape_chars)
{
    char *key = "key";
    char *value = "hello\n\"world\"!";
    json_object_t *jo = json_object_create();
    char *rtn_value;

    json_object_put_string(jo, key, value);
    rtn_value = json_object_get_string(jo, key);
    cr_assert_str_eq(rtn_value, value);
    json_object_destroy(jo);
}
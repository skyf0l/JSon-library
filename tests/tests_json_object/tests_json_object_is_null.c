/*
** EPITECH PROJECT, 2020
** TESTS_JSON_OBJECT_IS_NULL
** File description:
** Test json_object_is_null
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_object_is_null, null)
{
    char *key = NULL;
    json_object_t *jo = json_object_create();
    int rtn_value;

    rtn_value = json_object_is_null(jo, key);
    cr_assert_eq(rtn_value, 1);
    json_object_destroy(jo);
}

Test(json_object_is_null, not_fount)
{
    char *key = "key";
    json_object_t *jo = json_object_create();
    int rtn_value;

    rtn_value = json_object_is_null(jo, key);
    cr_assert_eq(rtn_value, 1);
    json_object_destroy(jo);
}

Test(json_object_is_null, is_null)
{
    char *key = "key";
    json_object_t *jo = json_object_create();
    int rtn_value;

    json_object_put_null(jo, key);
    rtn_value = json_object_is_null(jo, key);
    cr_assert_eq(rtn_value, 1);
    json_object_destroy(jo);
}

Test(json_object_is_null, isnt_null)
{
    char *key = "key";
    int value = 0;
    json_object_t *jo = json_object_create();
    int rtn_value;

    json_object_put_bool(jo, key, value);
    rtn_value = json_object_is_null(jo, key);
    cr_assert_eq(rtn_value, 0);
    json_object_destroy(jo);
}
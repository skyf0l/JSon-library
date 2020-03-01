/*
** EPITECH PROJECT, 2020
** TESTS_JSON_OBJECT_CREATE
** File description:
** Test json_object_create
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_object_create, just_create)
{
    json_object_t *jo = json_object_create();

    cr_assert_not_null(jo);
    cr_assert_eq(jo->elements_count, 0);
    cr_assert_not_null(jo->elements);
    json_object_destroy(jo);
}

Test(json_object_clone, null)
{
    json_object_t *clone = json_object_clone(NULL);

    cr_assert_null(clone);
}

Test(json_object_clone, just_create)
{
    json_object_t *jo = json_object_create();
    json_object_t *clone = json_object_clone(jo);

    json_object_destroy(jo);
    cr_assert_not_null(clone);
    cr_assert_eq(clone->elements_count, 0);
    cr_assert_not_null(clone->elements);
    json_object_destroy(clone);
}

Test(json_object_clone, fill_json_object_inside_before)
{
    json_object_t *jo = json_object_create();
    json_object_t *jo1 = json_object_create();
    json_object_t *clone;
    char *expect = "{\"jo1\":{\"jo\":{}, \"bool\":true}}";
    char *str;

    json_object_put_json_object(jo1, "jo", json_object_create());
    json_object_put_bool(jo1, "bool", 1);
    json_object_put_json_object(jo, "jo1", jo1);
    clone = json_object_clone(jo);
    json_object_destroy(jo);
    str = json_object_to_string(clone);
    cr_assert_str_eq(str, expect);
    cr_assert_eq(clone->elements_count, 1);
    json_object_destroy(clone);
    free(str);
}


Test(json_object_clone, json_object_array_inside)
{
    json_object_t *jo = json_object_create();
    json_object_t *clone;
    char *expect = "{\"jo\":{}, \"ja\":[]}";
    char *str;

    json_object_put_json_object(jo, "jo", json_object_create());
    json_object_put_json_array(jo, "ja", json_array_create());
    clone = json_object_clone(jo);
    json_object_destroy(jo);
    str = json_object_to_string(clone);
    cr_assert_str_eq(str, expect);
    cr_assert_eq(clone->elements_count, 2);
    json_object_destroy(clone);
    free(str);
}
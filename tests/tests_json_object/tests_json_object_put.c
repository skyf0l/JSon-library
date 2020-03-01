/*
** EPITECH PROJECT, 2020
** TESTS_JSON_OBJECT_PUT
** File description:
** Test json_object_put
*/

#include <criterion/criterion.h>
#include "list.h"
#include "json.h"

Test(json_object_put_null, null)
{
    char *key = NULL;
    json_object_t *jo = json_object_create();
    int rtn_value = json_object_put_null(jo, key);

    cr_assert_eq(rtn_value, EXIT_FAILURE);
    cr_assert_eq(jo->elements_count, 0);
    json_object_destroy(jo);
}

Test(json_object_put_null, basic)
{
    char *key = "key";
    json_object_t *jo = json_object_create();
    int rtn_value = json_object_put_null(jo, key);
    json_element_t *je = (json_element_t *)jo->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_null);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, 0);
    cr_assert_null(je->json_string);
    json_object_destroy(jo);
}

Test(json_object_put_null, two_same_key)
{
    char *key = "key";
    json_object_t *jo = json_object_create();
    int rtn_value;

    rtn_value = json_object_put_null(jo, key);
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 1);
    rtn_value = json_object_put_null(jo, key);
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 1);
    json_object_destroy(jo);
}

Test(json_object_put_null, two_not_same_key)
{
    char *key1 = "key1";
    char *key2 = "key2";
    json_object_t *jo = json_object_create();
    int rtn_value;

    rtn_value = json_object_put_null(jo, key1);
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 1);
    rtn_value = json_object_put_null(jo, key2);
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 2);
    json_object_destroy(jo);
}

Test(json_object_put_bool, null)
{
    char *key = NULL;
    json_object_t *jo = json_object_create();
    int rtn_value = json_object_put_bool(jo, key, 0);

    cr_assert_eq(rtn_value, EXIT_FAILURE);
    cr_assert_eq(jo->elements_count, 0);
    json_object_destroy(jo);
}

Test(json_object_put_bool, basic_0)
{
    char *key = "key";
    int value = 0;
    json_object_t *jo = json_object_create();
    int rtn_value = json_object_put_bool(jo, key, value);
    json_element_t *je = (json_element_t *)jo->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_bool);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, value);
    cr_assert_null(je->json_string);
    json_object_destroy(jo);
}

Test(json_object_put_bool, basic_1)
{
    char *key = "key";
    int value = 1;
    json_object_t *jo = json_object_create();
    int rtn_value = json_object_put_bool(jo, key, value);
    json_element_t *je = (json_element_t *)jo->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_bool);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, value);
    cr_assert_null(je->json_string);
    json_object_destroy(jo);
}

Test(json_object_put_bool, two_same_key)
{
    char *key = "key";
    json_object_t *jo = json_object_create();
    int rtn_value;

    rtn_value = json_object_put_bool(jo, key, 0);
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 1);
    rtn_value = json_object_put_bool(jo, key, 1);
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 1);
    json_object_destroy(jo);
}

Test(json_object_put_bool, two_not_same_key)
{
    char *key1 = "key1";
    char *key2 = "key2";
    json_object_t *jo = json_object_create();
    int rtn_value;

    rtn_value = json_object_put_bool(jo, key1, 0);
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 1);
    rtn_value = json_object_put_bool(jo, key2, 1);
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(jo->elements_count, 2);
    json_object_destroy(jo);
}
/*
** EPITECH PROJECT, 2020
** TESTS_JSON_ELEMENT_CREATE
** File description:
** Test json_element_create
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_element_create, null)
{
    json_element_t *je = json_element_create(NULL);

    cr_assert_null(je);
}

Test(json_element_create, j_null)
{
    char *key = "key";
    json_element_t *je = json_element_create(key);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_null);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, 0);
    cr_assert_null(je->json_string);
    json_element_destroy(je);
}

Test(json_element_create_bool, j_bool_0)
{
    char *key = "bool";
    int value = 0;
    json_element_t *je = json_element_create_bool(key, value);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_bool);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, value);
    cr_assert_null(je->json_string);
    json_element_destroy(je);
}

Test(json_element_create_bool, j_bool_1)
{
    char *key = "bool";
    int value = 1;
    json_element_t *je = json_element_create_bool(key, value);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_bool);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, value);
    cr_assert_null(je->json_string);
    json_element_destroy(je);
}

Test(json_element_create_bool, j_bool_2)
{
    char *key = "bool";
    int value = -551;
    json_element_t *je = json_element_create_bool(key, value);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_bool);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, 1);
    cr_assert_null(je->json_string);
    json_element_destroy(je);
}

Test(json_element_create_int, j_int_0)
{
    char *key = "int";
    int value = 0;
    json_element_t *je = json_element_create_int(key, value);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_int);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, value);
    cr_assert_null(je->json_string);
    json_element_destroy(je);
}

Test(json_element_create_int, j_int_1)
{
    char *key = "int";
    int value = 144;
    json_element_t *je = json_element_create_int(key, value);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_int);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, value);
    cr_assert_null(je->json_string);
    json_element_destroy(je);
}

Test(json_element_create_int, j_int_2)
{
    char *key = "int";
    int value = -2147483648;
    json_element_t *je = json_element_create_int(key, value);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_int);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, value);
    cr_assert_null(je->json_string);
    json_element_destroy(je);
}

Test(json_element_create_string, j_string_null)
{
    char *key = "string";
    char *value = NULL;
    json_element_t *je = json_element_create_string(key, value);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_null);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, 0);
    cr_assert_null(je->json_string);
    json_element_destroy(je);
}

Test(json_element_create_string, j_string)
{
    char *key = "string";
    char *value = "a random string";
    json_element_t *je = json_element_create_string(key, value);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_string);
    cr_assert_str_eq(je->key, key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, 0);
    cr_assert_str_eq(je->json_string, value);
    json_element_destroy(je);
}
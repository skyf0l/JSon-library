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
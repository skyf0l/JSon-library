/*
** EPITECH PROJECT, 2020
** TESTS_JSON_ARRAY_CREATE
** File description:
** Test json_array_create
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_array_create, just_create)
{
    json_array_t *ja = json_array_create();

    cr_assert_not_null(ja);
    cr_assert_eq(ja->elements_count, 0);
    cr_assert_not_null(ja->elements);
    json_array_destroy(ja);
}

Test(json_array_clone, null)
{
    json_array_t *clone = json_array_clone(NULL);

    cr_assert_null(clone);
}

Test(json_array_clone, just_create)
{
    json_array_t *ja = json_array_create();
    json_array_t *clone = json_array_clone(ja);

    json_array_destroy(ja);
    cr_assert_not_null(clone);
    cr_assert_eq(clone->elements_count, 0);
    cr_assert_not_null(clone->elements);
    json_array_destroy(clone);
}
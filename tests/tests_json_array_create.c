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
    cr_assert_eq(ja->objects_count, 0);
    json_array_destroy(ja);
}
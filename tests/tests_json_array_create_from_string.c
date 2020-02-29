/*
** EPITECH PROJECT, 2020
** TESTS_JSON_ARRAY_CREATE_FROM_STRING
** File description:
** Test json_array_create_from_string
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_array_create_from_string, null)
{
    char *str = NULL;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, just_create)
{
    char *str = "[]";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    cr_assert_eq(ja->objects_count, 0);
    json_array_destroy(ja);
}
/*
** EPITECH PROJECT, 2020
** TESTS_JSON_OBJECT_CREATE_FROM_STRING
** File description:
** Test json_object_create_from_string
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_object_create_from_string, null)
{
    char *str = NULL;
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, empty)
{
    char *str = "{}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_not_null(jo);
    json_object_destroy(jo);
}
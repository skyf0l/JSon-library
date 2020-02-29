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
    json_object_destroy(jo);
}
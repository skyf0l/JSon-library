/*
** EPITECH PROJECT, 2020
** TESTS_JSON_ARRAY_GET
** File description:
** Test json_array_get
*/

#include <criterion/criterion.h>
#include "list.h"
#include "../../lib/json/include/private/private_json.h"
#include "json.h"

Test(json_array_get_size, basic)
{
    json_array_t *ja = json_array_create();

    cr_assert_eq(json_array_get_size(ja), 0);
    json_array_put_null(ja);
    cr_assert_eq(json_array_get_size(ja), 1);
    json_array_put_string_at(ja, "string", 0);
    cr_assert_eq(json_array_get_size(ja), 2);
    cr_assert_eq(json_array_remove(ja, 1), 0);
    cr_assert_eq(json_array_get_size(ja), 1);
    cr_assert_eq(json_array_remove(ja, 1), 1);
    cr_assert_eq(json_array_get_size(ja), 1);
    cr_assert_eq(json_array_remove(ja, 0), 0);
    cr_assert_eq(json_array_get_size(ja), 0);
    json_array_destroy(ja);
}

Test(json_array_get_element, basic)
{
    json_array_t *ja = json_array_create();
    json_element_t *je;

    json_array_put_string(ja, "string1");
    json_array_put_string(ja, "string2");
    je = json_array_get_element(ja, -1);
    cr_assert_null(je);
    je = json_array_get_element(ja, 0);
    cr_assert_eq(je, ja->elements->list->data);
    je = json_array_get_element(ja, 1);
    cr_assert_eq(je, ja->elements->list->next->data);
    je = json_array_get_element(ja, 2);
    cr_assert_null(je);
    json_array_destroy(ja);
}
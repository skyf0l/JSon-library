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

Test(json_array_get_type, null)
{
    json_array_t *ja = json_array_create();
    enum json_type type;

    type = json_array_get_type(ja, 0);
    cr_assert_eq(type, j_null);
    json_array_destroy(ja);
}

Test(json_array_get_type, j_null)
{
    json_array_t *ja = json_array_create();
    enum json_type type;

    json_array_put_null(ja);
    type = json_array_get_type(ja, 0);
    cr_assert_eq(type, j_null);
    json_array_destroy(ja);
}

Test(json_array_get_type, j_bool)
{
    json_array_t *ja = json_array_create();
    enum json_type type;

    json_array_put_bool(ja, 0);
    type = json_array_get_type(ja, 0);
    cr_assert_eq(type, j_bool);
    json_array_destroy(ja);
}

Test(json_array_get_type, j_int)
{
    json_array_t *ja = json_array_create();
    enum json_type type;

    json_array_put_int(ja, 0);
    type = json_array_get_type(ja, 0);
    cr_assert_eq(type, j_int);
    json_array_destroy(ja);
}

Test(json_array_get_type, j_string)
{
    json_array_t *ja = json_array_create();
    enum json_type type;

    json_array_put_string(ja, "");
    type = json_array_get_type(ja, 0);
    cr_assert_eq(type, j_string);
    json_array_destroy(ja);
}

Test(json_array_get_type, j_array)
{
    json_array_t *ja = json_array_create();
    enum json_type type;

    json_array_put_json_array(ja, json_array_create());
    type = json_array_get_type(ja, 0);
    cr_assert_eq(type, j_array);
    json_array_destroy(ja);
}

Test(json_array_get_type, j_object)
{
    json_array_t *ja = json_array_create();
    enum json_type type;

    json_array_put_json_object(ja, json_object_create());
    type = json_array_get_type(ja, 0);
    cr_assert_eq(type, j_object);
    json_array_destroy(ja);
}

Test(json_array_get_bool, null)
{
    int value = 0;
    json_array_t *ja = json_array_create();

    cr_assert_eq(json_array_get_bool(ja, 0), value);
    json_array_destroy(ja);
}

Test(json_array_get_bool, j_bool)
{
    int value = 1;
    json_array_t *ja = json_array_create();

    json_array_put_bool(ja, value);
    cr_assert_eq(json_array_get_bool(ja, 0), value);
    json_array_destroy(ja);
}

Test(json_array_get_int, null)
{
    int value = 0;
    json_array_t *ja = json_array_create();

    cr_assert_eq(json_array_get_int(ja, 0), value);
    json_array_destroy(ja);
}

Test(json_array_get_int, j_int)
{
    int value = 144;
    json_array_t *ja = json_array_create();

    json_array_put_int(ja, value);
    cr_assert_eq(json_array_get_int(ja, 0), value);
    json_array_destroy(ja);
}

Test(json_array_get_string, null)
{
    json_array_t *ja = json_array_create();

    cr_assert_null(json_array_get_string(ja, 0));
    json_array_destroy(ja);
}

Test(json_array_get_string, j_string)
{
    char *value = "string";
    char *rtn_value;
    json_array_t *ja = json_array_create();

    json_array_put_string(ja, value);
    rtn_value = json_array_get_string(ja, 0);
    cr_assert_str_eq(rtn_value, value);
    json_array_destroy(ja);
}
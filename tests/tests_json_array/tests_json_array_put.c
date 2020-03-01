/*
** EPITECH PROJECT, 2020
** TESTS_JSON_ARRAY_PUT
** File description:
** Test json_array_put
*/

#include <criterion/criterion.h>
#include "list.h"
#include "../../lib/json/include/private/private_json.h"
#include "json.h"

Test(json_array_put_null, j_null)
{
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_null(ja);
    json_element_t *je = (json_element_t *)ja->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_null);
    cr_assert_null(je->key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, 0);
    cr_assert_null(je->json_string);
    json_array_destroy(ja);
}

Test(json_array_put_null, two_j_null)
{
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_null(ja);
    json_element_t *je = (json_element_t *)ja->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_null);
    cr_assert_null(je->key);
    rtn_value = json_array_put_null(ja);
    je = (json_element_t *)ja->elements->list->data;
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 2);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_null);
    cr_assert_null(je->key);
    json_array_destroy(ja);
}

Test(json_array_put_null_at, j_null_valid_id)
{
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_null_at(ja, 0);
    json_element_t *je = (json_element_t *)ja->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_null);
    cr_assert_null(je->key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, 0);
    cr_assert_null(je->json_string);
    json_array_destroy(ja);
}

Test(json_array_put_null_at, j_null_invalid_id_0)
{
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_null_at(ja, -1);

    cr_assert_eq(rtn_value, EXIT_FAILURE);
    cr_assert_eq(ja->elements_count, 0);
    json_array_destroy(ja);
}

Test(json_array_put_null_at, j_null_invalid_id_1)
{
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_null_at(ja, 1);

    cr_assert_eq(rtn_value, EXIT_FAILURE);
    cr_assert_eq(ja->elements_count, 0);
    json_array_destroy(ja);
}

Test(json_array_put_null_at, two_j_null)
{
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_null_at(ja, 0);
    json_element_t *je = (json_element_t *)ja->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_null);
    cr_assert_null(je->key);
    rtn_value = json_array_put_null_at(ja, 0);
    je = (json_element_t *)ja->elements->list->data;
    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 2);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_null);
    cr_assert_null(je->key);
    json_array_destroy(ja);
}

Test(json_array_put_bool, j_bool)
{
    int value = 1;
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_bool(ja, value);
    json_element_t *je = (json_element_t *)ja->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_bool);
    cr_assert_null(je->key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, value);
    cr_assert_null(je->json_string);
    json_array_destroy(ja);
}

Test(json_array_put_int, j_int)
{
    int value = 1;
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_int(ja, value);
    json_element_t *je = (json_element_t *)ja->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_int);
    cr_assert_null(je->key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, value);
    cr_assert_null(je->json_string);
    json_array_destroy(ja);
}

Test(json_array_put_string, j_string)
{
    char *value = "str";
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_string(ja, value);
    json_element_t *je = (json_element_t *)ja->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_string);
    cr_assert_null(je->key);
    cr_assert_null(je->json_array);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, 0);
    cr_assert_str_eq(je->json_string, value);
    json_array_destroy(ja);
}

Test(json_array_put_json_array, j_array)
{
    json_array_t *value = json_array_create();
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_json_array(ja, value);
    json_element_t *je = (json_element_t *)ja->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_array);
    cr_assert_null(je->key);
    cr_assert_eq(je->json_array, value);
    cr_assert_null(je->json_object);
    cr_assert_eq(je->json_int, 0);
    cr_assert_null(je->json_string);
    json_array_destroy(ja);
}

Test(json_array_put_json_object, j_object)
{
    json_object_t *value = json_object_create();
    json_array_t *ja = json_array_create();
    int rtn_value = json_array_put_json_object(ja, value);
    json_element_t *je = (json_element_t *)ja->elements->list->data;

    cr_assert_eq(rtn_value, EXIT_SUCCESS);
    cr_assert_eq(ja->elements_count, 1);
    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_object);
    cr_assert_null(je->key);
    cr_assert_null(je->json_array);
    cr_assert_eq(je->json_object, value);
    cr_assert_eq(je->json_int, 0);
    cr_assert_null(je->json_string);
    json_array_destroy(ja);
}
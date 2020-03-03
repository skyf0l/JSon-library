/*
** EPITECH PROJECT, 2020
** TESTS_JSON_ELEMENT_TO_STRING
** File description:
** Test json_element_to_string
*/

#include <criterion/criterion.h>
#include "../../lib/json/include/private/private_json.h"
#include "json.h"

Test(json_element_to_string, j_null_null_key)
{
    char *key = NULL;
    char *expected = "null";
    json_element_t *je = json_element_create(key);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_null)
{
    char *key = "key";
    char *expected = "\"key\":null";
    json_element_t *je = json_element_create(key);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_bool_null_key)
{
    char *key = NULL;
    int value = 0;
    char *expected = "false";
    json_element_t *je = json_element_create_bool(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_bool_0)
{
    char *key = "key";
    int value = 0;
    char *expected = "\"key\":false";
    json_element_t *je = json_element_create_bool(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_bool_1)
{
    char *key = "key";
    int value = 1;
    char *expected = "\"key\":true";
    json_element_t *je = json_element_create_bool(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_int_0)
{
    char *key = "key";
    int value = 0;
    char *expected = "\"key\":0";
    json_element_t *je = json_element_create_int(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_int_1)
{
    char *key = "key";
    int value = 144;
    char *expected = "\"key\":144";
    json_element_t *je = json_element_create_int(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_int_2)
{
    char *key = "key";
    int value = -144;
    char *expected = "\"key\":-144";
    json_element_t *je = json_element_create_int(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_int_3_key_null)
{
    char *key = NULL;
    int value = 2147483647;
    char *expected = "2147483647";
    json_element_t *je = json_element_create_int(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_int_3)
{
    char *key = "key";
    int value = 2147483647;
    char *expected = "\"key\":2147483647";
    json_element_t *je = json_element_create_int(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_int_4)
{
    char *key = "key";
    int value = -2147483648;
    char *expected = "\"key\":-2147483648";
    json_element_t *je = json_element_create_int(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_int_5)
{
    char *key = "key";
    int value = -26;
    char *expected = "\"key\":-26";
    json_element_t *je = json_element_create_int(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_string_null)
{
    char *key = "key";
    char *value = NULL;
    char *expected = "\"key\":null";
    json_element_t *je = json_element_create_string(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_string)
{
    char *key = "key";
    char *value = "a random string";
    char *expected = "\"key\":\"a random string\"";
    json_element_t *je = json_element_create_string(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_string_quotes_key_null)
{
    char *key = NULL;
    char *value = "a \"random\nstring\"";
    char *expected = "\"a \\\"random\\nstring\\\"\"";
    json_element_t *je = json_element_create_string(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_string_quotes)
{
    char *key = "key";
    char *value = "a \"random\nstring\"";
    char *expected = "\"key\":\"a \\\"random\\nstring\\\"\"";
    json_element_t *je = json_element_create_string(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}

Test(json_element_to_string, j_string_all_escape_char)
{
    char *key = "\b\f\n\r\t\"\\";
    char *value = "\b\f\n\r\t\"\\";
    char *expected = "\"\\b\\f\\n\\r\\t\\\"\\\\\":\"\\b\\f\\n\\r\\t\\\"\\\\\"";
    json_element_t *je = json_element_create_string(key, value);
    char *to_string = json_element_to_string(je);

    cr_assert_str_eq(to_string, expected);
    json_element_destroy(je);
    free(to_string);
}
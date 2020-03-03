/*
** EPITECH PROJECT, 2020
** TESTS_JSON_PARSER_TO_ELEMENT
** File description:
** Test json_parser_to_element
*/

#include <criterion/criterion.h>
#include "../../lib/json/include/private/private_json.h"
#include "json.h"

Test(json_parser_to_array_element, null)
{
    char *string = NULL;
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_null(je);
}

Test(json_parser_to_array_element, invalid_0)
{
    char *string = "";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_null(je);
}

Test(json_parser_to_array_element, invalid_1)
{
    char *string = "azerty";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_null(je);
}

Test(json_parser_to_array_element, invalid_2)
{
    char *string = ", azerty";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_null(je);
}

Test(json_parser_to_array_element, j_null_0)
{
    char *string = "null, azerty";
    char *expected = ", azerty";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_eq(je->type, j_null);
    cr_assert_str_eq(string, expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_null_1)
{
    char *string = "null , azerty";
    char *expected = ", azerty";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_eq(je->type, j_null);
    cr_assert_str_eq(string, expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_null_2)
{
    char *string = "null \n\t\r, azerty";
    char *expected = ", azerty";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_eq(je->type, j_null);
    cr_assert_str_eq(string, expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_null_3)
{
    char *string = "null]\n\t\r, azerty";
    char *expected = "]\n\t\r, azerty";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_eq(je->type, j_null);
    cr_assert_str_eq(string, expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_null_4)
{
    char *string = "null \n\t}\r, azerty";
    char *expected = "}\r, azerty";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_eq(je->type, j_null);
    cr_assert_str_eq(string, expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_bool_0)
{
    char *string = "false \n\t}\r, azerty";
    char *expected = "}\r, azerty";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_eq(je->type, j_bool);
    cr_assert_eq(je->json_int, 0);
    cr_assert_str_eq(string, expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_bool_1)
{
    char *string = "true \n\t}\r, azerty";
    char *expected = "}\r, azerty";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_eq(je->type, j_bool);
    cr_assert_eq(je->json_int, 1);
    cr_assert_str_eq(string, expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_string_0)
{
    char *string = "\"null\", azerty";
    char *string_expected = ", azerty";
    char *expected = "null";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_string);
    cr_assert_str_eq(je->json_string, expected);
    cr_assert_str_eq(string, string_expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_string_1)
{
    char *string = "\"null\" }";
    char *string_expected = "}";
    char *expected = "null";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_string);
    cr_assert_str_eq(je->json_string, expected);
    cr_assert_str_eq(string, string_expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_string_2)
{
    char *string = "\"\"\t\r\n, azerty";
    char *string_expected = ", azerty";
    char *expected = "";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_string);
    cr_assert_str_eq(je->json_string, expected);
    cr_assert_str_eq(string, string_expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_string_3)
{
    char *string = "\"nu\\\",\\\"ll\" ], azerty";
    char *string_expected = "], azerty";
    char *expected = "nu\",\"ll";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_string);
    cr_assert_str_eq(je->json_string, expected);
    cr_assert_str_eq(string, string_expected);
    json_element_destroy(je);
}

Test(json_parser_to_array_element, j_string_4)
{
    char *string = "\"nu\\nll\" \t}\n, azerty";
    char *string_expected = "}\n, azerty";
    char *expected = "nu\nll";
    json_element_t *je = json_parser_to_array_element(&string);

    cr_assert_not_null(je);
    cr_assert_eq(je->type, j_string);
    cr_assert_str_eq(je->json_string, expected);
    cr_assert_str_eq(string, string_expected);
    json_element_destroy(je);
}
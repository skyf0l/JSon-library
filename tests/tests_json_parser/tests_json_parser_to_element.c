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
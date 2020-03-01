/*
** EPITECH PROJECT, 2020
** TESTS_JSON_KEY_TO_STRING
** File description:
** Test json_key_to_string
*/

#include <criterion/criterion.h>
#include "../../lib/json/include/private/private_json.h"
#include "json.h"

Test(json_key_to_string, null)
{
    char *key = NULL;
    char *key_to_string = json_key_to_string(key);

    cr_assert_null(key_to_string);
}

Test(json_key_to_string, empty)
{
    char *key = "";
    char *key_to_string = json_key_to_string(key);

    cr_assert_str_eq(key_to_string, "\"\"");
    free(key_to_string);
}

Test(json_key_to_string, basic)
{
    char *key = "a random key";
    char *key_to_string = json_key_to_string(key);

    cr_assert_str_eq(key_to_string, "\"a random key\"");
    free(key_to_string);
}

Test(json_key_to_string, escape_key)
{
    char *key = "\b\f\n\r\t\"\\";
    char *key_to_string = json_key_to_string(key);

    cr_assert_str_eq(key_to_string, "\"\\b\\f\\n\\r\\t\\\"\\\\\"");
    free(key_to_string);
}
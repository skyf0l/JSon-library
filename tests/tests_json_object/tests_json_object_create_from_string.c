/*
** EPITECH PROJECT, 2020
** TESTS_JSON_OBJECT_CREATE_FROM_STRING
** File description:
** Test json_object_create_from_string
*/

#include <criterion/criterion.h>
#include "../../lib/json/include/private/private_json.h"
#include "json.h"

Test(json_object_create_from_string, null)
{
    char *str = NULL;
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_0)
{
    char *str = "{";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_1)
{
    char *str = "}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_2)
{
    char *str = "{} a random thing";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_3)
{
    char *str = "{, true}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_4)
{
    char *str = "{key}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_5)
{
    char *str = "{\"key}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_6)
{
    char *str = "{\"key\"}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_7)
{
    char *str = "{\"key\":}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(jo_create_from_string, null)
{
    char *str = NULL;
    json_object_t *jo = jo_create_from_string(&str);

    cr_assert_null(jo);
}

Test(jo_create_from_string, invalid_json_0)
{
    char *str = "{";
    json_object_t *jo = jo_create_from_string(&str);

    cr_assert_null(jo);
}

Test(jo_create_from_string, invalid_json_1)
{
    char *str = "}";
    json_object_t *jo = jo_create_from_string(&str);

    cr_assert_null(jo);
}

Test(jo_create_from_string, invalid_json_2)
{
    char *str = "{, true}";
    json_object_t *jo = jo_create_from_string(&str);

    cr_assert_null(jo);
}

Test(jo_create_from_string, invalid_json_3)
{
    char *str = "{key}";
    json_object_t *jo = jo_create_from_string(&str);

    cr_assert_null(jo);
}

Test(jo_create_from_string, invalid_json_4)
{
    char *str = "{\"key}";
    json_object_t *jo = jo_create_from_string(&str);

    cr_assert_null(jo);
}

Test(jo_create_from_string, invalid_json_5)
{
    char *str = "{\"key\"}";
    json_object_t *jo = jo_create_from_string(&str);

    cr_assert_null(jo);
}

Test(jo_create_from_string, invalid_json_6)
{
    char *str = "{\"key\":}";
    json_object_t *jo = jo_create_from_string(&str);

    cr_assert_null(jo);
}

Test(jo_create_from_string, valid_json)
{
    char *str = "{} a random thing";
    char *str_expected = " a random thing";
    char *to_string;
    char *expected = "{}";
    json_object_t *jo = jo_create_from_string(&str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, expected);
    cr_assert_str_eq(str, str_expected);
    json_object_destroy(jo);
    free(to_string);
}

Test(jo_create_from_string, just_create)
{
    char *str = "{}";
    char *str_expected = "";
    char *to_string;
    char *expected = "{}";
    json_object_t *jo = jo_create_from_string(&str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, expected);
    cr_assert_str_eq(str, str_expected);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, just_create_with_space_0)
{
    char *str = "  { }    ";
    char *expected = "{}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, expected);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, just_create_with_space_1)
{
    char *str = "\t\n\r  \t{\n\n\t}\t\n\r  \r";
    char *expected = "{}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, expected);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, j_null)
{
    char *str = "{\"key\":null}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, j_bool_0)
{
    char *str = "{\"key\":false}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, j_bool_1)
{
    char *str = "{\"key\":true}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, j_int_0)
{
    char *str = "{\"key\":144}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, j_int_1)
{
    char *str = "{\"key\":2147483647}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, j_int_2)
{
    char *str = "{\"key\":-2147483648}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, j_string)
{
    char *str = "{\"key\":\"random string\"}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, j_string_escape)
{
    char *str = "{\"\\b\\f\\n\\r\\t\\\"\\\\\":\"\\b\\f\\n\\r\\t\\\"\\\\\"}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, valid_recursif_object)
{
    char *str = "{\"\":{}, \"0\":{\"0\":[[[]]]}, \"kk\":[false]}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}
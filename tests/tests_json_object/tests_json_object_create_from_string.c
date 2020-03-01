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
/*
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
    char *str = "{,}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_3)
{
    char *str = "{\"key\"}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, invalid_json_4)
{
    char *str = "{\"key\":}";
    json_object_t *jo = json_object_create_from_string(str);

    cr_assert_null(jo);
}

Test(json_object_create_from_string, just_create)
{
    char *str = "{}";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, just_create_with_space)
{
    char *str = " { } ";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, just_create_with_tabs)
{
    char *str = "\t{\t}\t";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
    json_object_destroy(jo);
    free(to_string);
}

Test(json_object_create_from_string, just_create_with_tabs)
{
    char *str = "\n{\n}\n";
    char *to_string;
    json_object_t *jo = json_object_create_from_string(str);

    to_string = json_object_to_string(jo);
    cr_assert_str_eq(to_string, str);
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
}*/
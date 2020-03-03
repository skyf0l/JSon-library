/*
** EPITECH PROJECT, 2020
** TESTS_JSON_ARRAY_CREATE_FROM_STRING
** File description:
** Test json_array_create_from_string
*/

#include <criterion/criterion.h>
#include "json.h"

Test(json_array_create_from_string, null)
{
    char *str = NULL;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, just_create)
{
    char *str = "[]";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    cr_assert_eq(ja->elements_count, 0);
    cr_assert_not_null(ja->elements);
    json_array_destroy(ja);
}

Test(json_array_create_from_string, invalid_0)
{
    char *str = "[";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, invalid_1)
{
    char *str = "]";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, invalid_2)
{
    char *str = "[nul]";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, invalid_3)
{
    char *str = "[null";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, invalid_4)
{
    char *str = "[null,]";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, invalid_5)
{
    char *str = "[,\"null\"]";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, invalid_6)
{
    char *str = "[null, false, true,";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, valid_j_null_0)
{
    char *str = "[null]";
    char *expected = str;
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, valid_j_null_1)
{
    char *str = "[null, null]";
    char *expected = str;
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, valid_j_null_2)
{
    char *str = "[null, null, null, null, null, null, null]";
    char *expected = str;
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, valid_0)
{
    char *str = "[null, false, true]";
    char *expected = str;
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, valid_1)
{
    char *str = "[null, false, true, \"it work !\\namazing!\"]";
    char *expected = str;
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, valid_2)
{
    char *str = "   [  null  ,   false   ,   \"true\"   ]    ";
    char *expected = "[null, false, \"true\"]";
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, valid_3)
{
    char *str = "   [  null  ,   false   ,   \"true\"   , -26]    ";
    char *expected = "[null, false, \"true\", -26]";
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, invalid_recursif_array_0)
{
    char *str = "[[]";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, invalid_recursif_array_1)
{
    char *str = "[[[[[[[[[[]]]]]]]]]";
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_null(ja);
}

Test(json_array_create_from_string, valid_recursif_array_1)
{
    char *str = "[[[[[[[[[[]]]]]]]]]]";
    char *expected = str;
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, valid_recursif_array_2)
{
    char *str = "[[[[], [[], []]], []], []]";
    char *expected = str;
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, valid_recursif_array_object_0)
{
    char *str = "[{}, {}, {}]";
    char *expected = str;
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}

Test(json_array_create_from_string, valid_recursif_array_object_1)
{
    char *str = "[{\"0\":[]}, {\"0\":[{\"0\":[]}]}, {\"0\":[]}]";
    char *expected = str;
    char *to_string;
    json_array_t *ja = json_array_create_from_string(str);

    cr_assert_not_null(ja);
    to_string = json_array_to_string(ja);
    cr_assert_str_eq(to_string, expected);
}
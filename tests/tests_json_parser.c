/*
** EPITECH PROJECT, 2020
** TESTS_JSON_PARSER
** File description:
** Test json_parser
*/

#include <criterion/criterion.h>
#include "../lib/json/include/private/private_json.h"
#include "json.h"

Test(json_parser_skip_white_spaces, null)
{
    char *str = NULL;

    json_parser_skip_white_spaces(&str);
    cr_assert_null(str);
}

Test(json_parser_skip_white_spaces, empty)
{
    char *str = "";
    char *expected = "";

    json_parser_skip_white_spaces(&str);
    cr_assert_str_eq(str, expected);
}

Test(json_parser_skip_white_spaces, just_white_spaces)
{
    char *str = "    \t  \n\n \r\r\t  ";
    char *expected = "";

    json_parser_skip_white_spaces(&str);
    cr_assert_str_eq(str, expected);
}

Test(json_parser_skip_white_spaces, white_spaces_0)
{
    char *str = "    \t  \n\n \r\r\t  {";
    char *expected = "{";

    json_parser_skip_white_spaces(&str);
    cr_assert_str_eq(str, expected);
}

Test(json_parser_skip_white_spaces, white_spaces_1)
{
    char *str = "    \t  \n\n \r\r\t  }";
    char *expected = "}";

    json_parser_skip_white_spaces(&str);
    cr_assert_str_eq(str, expected);
}

Test(json_parser_skip_white_spaces, white_spaces_2)
{
    char *str = "    \t  \n\n \r\r\t  false \r   \t";
    char *expected = "false \r   \t";

    json_parser_skip_white_spaces(&str);
    cr_assert_str_eq(str, expected);
}

Test(json_parser_skip_white_spaces, white_spaces_3)
{
    char *str = "    \t  \n\n \r\r\t  \"string \r   \t";
    char *expected = "\"string \r   \t";

    json_parser_skip_white_spaces(&str);
    cr_assert_str_eq(str, expected);
}
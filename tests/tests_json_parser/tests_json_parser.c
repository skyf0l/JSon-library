/*
** EPITECH PROJECT, 2020
** TESTS_JSON_PARSER
** File description:
** Test json_parser
*/

#include <criterion/criterion.h>
#include "../../lib/json/include/private/private_json.h"
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

Test(json_parser_skip_white_spaces, white_spaces_4)
{
    char *str = "    \t  \n\n \r\r\t  n \r   \t";
    char *expected = "";

    json_parser_skip_white_spaces(&str);
    str++;
    json_parser_skip_white_spaces(&str);
    cr_assert_str_eq(str, expected);
}

Test(json_parser_get_string, invalid_0)
{
    char *str = "";
    char *string = json_parser_get_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_string, invalid_1)
{
    char *str = "\"";
    char *string = json_parser_get_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_string, invalid_2)
{
    char *str = "\"azerty";
    char *string = json_parser_get_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_string, invalid_3)
{
    char *str = " \"azerty\"";
    char *string = json_parser_get_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_string, invalid_4)
{
    char *str = "\"azerty\\\"";
    char *string = json_parser_get_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_string, invalid_5)
{
    char *str = "\"aze\\krty\"";
    char *string = json_parser_get_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_string, invalid_6)
{
    char *str = "\"azer\nty\"";
    char *string = json_parser_get_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_string, invalid_7)
{
    char *str = "\"azerty  ";
    char *string = json_parser_get_string(&str);

    cr_assert_null(string);
}


Test(json_parser_get_string, valid_0)
{
    char *str = "\"string\"";
    char *expected = "";
    char *string = json_parser_get_string(&str);
    char *string_expected = "string";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_string, valid_1)
{
    char *str = "\"string\":  ";
    char *expected = ":  ";
    char *string = json_parser_get_string(&str);
    char *string_expected = "string";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_string, valid_2)
{
    char *str = "\"\":  ";
    char *expected = ":  ";
    char *string = json_parser_get_string(&str);
    char *string_expected = "";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_string, valid_3)
{
    char *str = "\"esc\\nape\":  false,";
    char *expected = ":  false,";
    char *string = json_parser_get_string(&str);
    char *string_expected = "esc\nape";

    cr_assert_str_eq(string, string_expected);
    cr_assert_str_eq(str, expected);
    free(string);
}

Test(json_parser_get_string, valid_4)
{
    char *str = "\"\\b\\f\\n\\r\\t\\\"\\\\\":  false,";
    char *expected = ":  false,";
    char *string = json_parser_get_string(&str);
    char *string_expected = "\b\f\n\r\t\"\\";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_string, valid_5)
{
    char *str = "\"null\"";
    char *expected = "";
    char *string = json_parser_get_string(&str);
    char *string_expected = "null";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, empty)
{
    char *str = "";
    char *string = json_parser_get_value_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_value_string, j_bool)
{
    char *str = "false";
    char *string = json_parser_get_value_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_value_string, j_int)
{
    char *str = "-144";
    char *string = json_parser_get_value_string(&str);

    cr_assert_null(string);
}

Test(json_parser_get_value_string, j_string)
{
    char *str = "\"some string\"";
    char *string = json_parser_get_value_string(&str);

    cr_assert_null(string);
}

Test(jp_get_value_string_size, null)
{
    char *str = " ";
    int size = jp_get_value_string_size(str);
    int expected = -1;

    cr_assert_eq(size, expected);
}

Test(jp_get_value_string_size, empty_next)
{
    char *str = ", ";
    int size = jp_get_value_string_size(str);
    int expected = 0;

    cr_assert_eq(size, expected);
}

Test(jp_get_value_string_size, space)
{
    char *str = "  , ";
    int size = jp_get_value_string_size(str);
    int expected = 0;

    cr_assert_eq(size, expected);
}

Test(jp_get_value_string_size, j_bool)
{
    char *str = "false  , ";
    int size = jp_get_value_string_size(str);
    int expected = 5;

    cr_assert_eq(size, expected);
}

Test(jp_get_value_string_size, j_int)
{
    char *str = "-26  }";
    int size = jp_get_value_string_size(str);
    int expected = 3;

    cr_assert_eq(size, expected);
}

Test(json_parser_get_value_string, empty_next)
{
    char *str = ", ";
    char *expected = ", ";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, empty_next_1)
{
    char *str = "}";
    char *expected = "}";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, empty_next_2)
{
    char *str = "  , ";
    char *expected = ", ";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_bool_next)
{
    char *str = "false, \"key2\"";
    char *expected = ", \"key2\"";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "false";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_bool_next_2)
{
    char *str = "false  , \"key2\"";
    char *expected = ", \"key2\"";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "false";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_int_next)
{
    char *str = "-144, random";
    char *expected = ", random";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "-144";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_int_next_2)
{
    char *str = "-144  , random";
    char *expected = ", random";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "-144";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_int_next_3)
{
    char *str = "-144  } , random";
    char *expected = "} , random";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "-144";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_int_next_4)
{
    char *str = "-144  ] , random";
    char *expected = "] , random";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "-144";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_int_next_5)
{
    char *str = "-144   \n   ] , random";
    char *expected = "] , random";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "-144";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_string_next)
{
    char *str = "\"some string\", some else";
    char *expected = ", some else";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "\"some string\"";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_string_next_2)
{
    char *str = "\"some string  \"  , some else";
    char *expected = ", some else";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "\"some string  \"";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_string_next_3)
{
    char *str = "\"some string  \" \n\t\r , some else";
    char *expected = ", some else";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "\"some string  \"";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_string_next_4)
{
    char *str = "\"some, string\", some else";
    char *expected = ", some else";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "\"some, string\"";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_string_next_5)
{
    char *str = "\"some string \"}, some else";
    char *expected = "}, some else";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "\"some string \"";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_string, j_string_next_6)
{
    char *str = "\"some string \"   }, some else";
    char *expected = "}, some else";
    char *string = json_parser_get_value_string(&str);
    char *string_expected = "\"some string \"";

    cr_assert_str_eq(str, expected);
    cr_assert_str_eq(string, string_expected);
    free(string);
}

Test(json_parser_get_value_type, j_unexist_0)
{
    char *string = "";
    enum json_type type;
    enum json_type expected = j_unexist;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_unexist_1)
{
    char *string = "flase";
    enum json_type type;
    enum json_type expected = j_unexist;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_null)
{
    char *string = "null";
    enum json_type type;
    enum json_type expected = j_null;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_bool_0)
{
    char *string = "false";
    enum json_type type;
    enum json_type expected = j_bool;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_bool_1)
{
    char *string = "true";
    enum json_type type;
    enum json_type expected = j_bool;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_int_0)
{
    char *string = "0";
    enum json_type type;
    enum json_type expected = j_int;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_int_1)
{
    char *string = "144";
    enum json_type type;
    enum json_type expected = j_int;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_int_2)
{
    char *string = "2147483647";
    enum json_type type;
    enum json_type expected = j_int;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_int_3)
{
    char *string = "-2147483648";
    enum json_type type;
    enum json_type expected = j_int;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_int_4)
{
    char *string = "-26";
    enum json_type type;
    enum json_type expected = j_int;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_int__overflow_0)
{
    char *string = "-21474836481";
    enum json_type type;
    enum json_type expected = j_unexist;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_int__overflow_1)
{
    char *string = "2147483648";
    enum json_type type;
    enum json_type expected = j_unexist;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_string_0)
{
    char *string = "\"str\"";
    enum json_type type;
    enum json_type expected = j_string;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_string_1)
{
    char *string = "\"str string !!! \\n\\n\"";
    enum json_type type;
    enum json_type expected = j_string;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_string__error_0)
{
    char *string = "\"str\n\"";
    enum json_type type;
    enum json_type expected = j_unexist;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_string__error_1)
{
    char *string = "\"str string !!! \n\n\"";
    enum json_type type;
    enum json_type expected = j_unexist;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}

Test(json_parser_get_value_type, j_string__error_2)
{
    char *string = "\"str string !!!";
    enum json_type type;
    enum json_type expected = j_unexist;

    type = json_parser_get_value_type(string);
    cr_assert_eq(type, expected);
}
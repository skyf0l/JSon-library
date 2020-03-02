/*
** EPITECH PROJECT, 2020
** PRIVATE_JSON
** File description:
** Private_json header
*/

#ifndef PRIVATE_JSON_H_
#define PRIVATE_JSON_H_

//////////////////////// VAR ////////////////////////

// const
static char const ESCAPE_CHARS[8] = "\b\f\n\r\t\"\\";
static char const UNESCAPE_CHARS[8] = "bfnrt\"\\";
static char const WHITE_SPACES[5] = " \n\r\t";

// def struct
typedef struct list_s list_t;
typedef struct json_array_s json_array_t;
typedef struct json_object_s json_object_t;
typedef struct json_element_s json_element_t;

// enum
#ifndef JSON_TYPE
#define JSON_TYPE
enum json_type {j_null, j_array, j_object, j_bool, j_int, j_string};
#endif /* !JSON_TYPE */

// struct
struct json_element_s
{
    enum json_type type;
    char *key;
    json_array_t *json_array;
    json_object_t *json_object;
    int json_int;
    char *json_string;
};

///////////////////// PROTOTYPE /////////////////////

// json_array_get
json_element_t *json_array_get_element(json_array_t *ja, int id);

// json_object_get
json_element_t *json_object_get_element(json_object_t *jo, char *key);

// json_element
json_element_t *json_element_create(char *key);
json_element_t *json_element_clone(json_element_t *je);
json_element_t *json_element_create_json_array(char *key, json_array_t *value);
json_element_t *json_element_create_json_object(char *key,
    json_object_t *value);
json_element_t *json_element_create_bool(char *key, int value);
json_element_t *json_element_create_int(char *key, int value);
json_element_t *json_element_create_string(char *key, char *value);
void *json_element_destroy(json_element_t *je);
void json_element_destroy_no_rtn(json_element_t *je);

// json_to_string
char *json_element_to_string(json_element_t *je);
char *json_key_to_string(char *key);
int json_to_string_append(char **str, char *to_add);

// json_string
char js_to_escape_char(char c);
char js_to_unescape_char(char c);
int js_is_unescape_char(char c);
int js_is_escape_char(char c);
int js_count_special_chars(char *str);
char *get_string_from_json_format(char *str);
char *get_string_to_json_format(char *str);

// json_parser
json_object_t *jo_create_from_string(char **str);
void json_parser_skip_white_spaces(char **str);
char *json_parser_get_string(char **str);

// j_str
size_t j_strlen(char const *str);
char *j_strclone(char const *str);
int j_strcmp(char const *s1, char const *s2);
char *j_itoa(int n);
char *j_strrev(char *str);

#endif /* !PRIVATE_JSON_H_ */
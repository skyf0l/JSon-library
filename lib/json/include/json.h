/*
** EPITECH PROJECT, 2020
** JSON
** File description:
** Json header
*/

#ifndef JSON_H_
#define JSON_H_

//////////////////////// VAR ////////////////////////

// const
static char const ESCAPE_CHARS[8] = "\b\f\n\r\t\"\\";
static char const UNESCAPE_CHARS[8] = "bfnrt\"\\";

// def
typedef struct list_s list_t;
typedef struct json_array_s json_array_t;
typedef struct json_object_s json_object_t;
typedef struct json_element_s json_element_t;

// enum
enum json_type {j_null, j_array, j_object, j_bool, j_int, j_string};

// struct
struct json_array_s
{
    int elements_count;
    list_t *elements;
};
struct json_object_s
{
    int elements_count;
    list_t *elements;
};
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

// json_array
json_array_t *json_array_create(void);
json_array_t *json_array_create_from_string(char *str);
void *json_array_destroy(json_array_t *ja);

// json_object
json_object_t *json_object_create(void);
json_object_t *json_object_create_from_string(char *str);
int json_object_remove(json_object_t *jo, char *key);
void *json_object_destroy(json_object_t *jo);

// json_object_get
json_element_t *json_object_get_element(json_object_t *jo, char *key);
int json_object_has(json_object_t *jo, char *key);
int json_object_is_null(json_object_t *jo, char *key);
int json_object_get_size(json_object_t *jo);
enum json_type json_object_get_type(json_object_t *jo, char *key);
json_array_t *json_object_get_json_array(json_object_t *jo, char *key);
json_object_t *json_object_get_json_object(json_object_t *jo, char *key);
int json_object_get_bool(json_object_t *jo, char *key);
int json_object_get_int(json_object_t *jo, char *key);
char *json_object_get_string(json_object_t *jo, char *key);

// json_object_put
int json_object_put_null(json_object_t *jo, char *key);
int json_object_put_json_array(json_object_t *jo, char *key,
    json_array_t *value);
int json_object_put_json_object(json_object_t *jo, char *key,
    json_object_t *value);
int json_object_put_bool(json_object_t *jo, char *key, int value);
int json_object_put_int(json_object_t *jo, char *key, int value);
int json_object_put_string(json_object_t *jo, char *key, char *value);

// json_element
json_element_t *json_element_create(char *key);
json_element_t *json_element_create_json_array(char *key, json_array_t *value);
json_element_t *json_element_create_json_object(char *key,
    json_object_t *value);
json_element_t *json_element_create_bool(char *key, int value);
json_element_t *json_element_create_int(char *key, int value);
json_element_t *json_element_create_string(char *key, char *value);
void *json_element_destroy(json_element_t *je);
void json_element_destroy_no_rtn(json_element_t *je);

// json_to_string
char *json_array_to_string(json_array_t *ja);
char *json_object_to_string(json_object_t *jo);
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

// j_str
size_t j_strlen(char const *str);
char *j_strclone(char const *str);
int j_strcmp(char const *s1, char const *s2);
char *j_itoa(int n);
char *j_strrev(char *str);

#endif /* !JSON_H_ */
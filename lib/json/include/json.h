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
void *json_object_destroy(json_object_t *jo);

// json_element
json_element_t *json_element_create(char *key);
json_element_t *json_element_create_bool(char *key, int value);
json_element_t *json_element_create_int(char *key, int value);
json_element_t *json_element_create_string(char *key, char *value);
void *json_element_destroy(json_element_t *je);

// json_to_string
char *json_array_to_string(json_array_t *ja);
char *json_object_to_string(json_object_t *jo);
char *json_element_to_string(json_element_t *je);
char *json_key_to_string(char *key);
int json_to_string_append(char **str, char *to_add);

// json_string
char *get_string_from_json_format(char *str);
char *get_string_to_json_format(char *str);

// j_str
size_t j_strlen(char const *str);
char *j_strclone(char const *str);
int j_strcmp(char const *s1, char const *s2);
char *j_itoa(int n);
char *j_strrev(char *str);

#endif /* !JSON_H_ */
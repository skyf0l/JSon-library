/*
** EPITECH PROJECT, 2020
** JSON
** File description:
** Json header
*/

#ifndef JSON_H_
#define JSON_H_

//////////////////////// VAR ////////////////////////

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

///////////////////// PROTOTYPE /////////////////////

// json_array
json_array_t *json_array_create(void);
json_array_t *json_array_clone(json_array_t *ja);
json_array_t *json_array_create_from_string(char *str);
char *json_array_to_string(json_array_t *ja);
void *json_array_destroy(json_array_t *ja);

// json_array_get
int json_array_is_null(json_array_t *ja, int id);
int json_array_get_size(json_array_t *ja);

// json_array_put
int json_array_put_null(json_array_t *ja);
int json_array_put_null_at(json_array_t *ja, int id);
int json_array_put_json_array(json_array_t *ja, json_array_t *value);
int json_array_put_json_array_at(json_array_t *ja, json_array_t *value, int id);
int json_array_put_json_object(json_array_t *ja, json_object_t *value);
int json_array_put_json_object_at(json_array_t *ja,
    json_object_t *value, int id);
int json_array_put_bool(json_array_t *ja, int value);
int json_array_put_bool_at(json_array_t *ja, int value, int id);
int json_array_put_int(json_array_t *ja, int value);
int json_array_put_int_at(json_array_t *ja, int value, int id);
int json_array_put_string(json_array_t *ja, char *value);
int json_array_put_string_at(json_array_t *ja, char *value, int id);

// json_object
json_object_t *json_object_create(void);
json_object_t *json_object_create_from_string(char *str);
json_object_t *json_object_clone(json_object_t *jo);
int json_object_remove(json_object_t *jo, char *key);
char *json_object_to_string(json_object_t *jo);
void *json_object_destroy(json_object_t *jo);

// json_object_get
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

#endif /* !JSON_H_ */
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
typedef union json_parser_s json_parser_t;

// enum
enum json_type {j_array, j_object, j_int, j_string};

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
union json_element_s
{
    enum json_type type;
    struct json_array_s json_array;
    struct json_object_s json_object;
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

#endif /* !JSON_H_ */
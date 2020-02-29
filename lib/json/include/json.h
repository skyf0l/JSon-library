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
typedef struct json_object_s json_object_t;

// struct
struct json_object_s
{

};

///////////////////// PROTOTYPE /////////////////////

// json_object
json_object_t *json_object_create();
void *json_object_destroy(json_object_t *jo);

#endif /* !JSON_H_ */
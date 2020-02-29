/*
** EPITECH PROJECT, 2019
** PRIVATE_LIST
** File description:
** Private_list header
*/

#ifndef PRIVATE_LIST_H_
#define PRIVATE_LIST_H_

//////////////////////// VAR ////////////////////////

// def struct
typedef struct list_s list_t;
typedef struct simple_list_s simple_list_t;

///////////////////// PROTOTYPE /////////////////////

simple_list_t *create_element(void *data);
simple_list_t *get_element(list_t *list, int index);
void destroy_data(list_t *list, void *data);

void list_remove_link(list_t *list, simple_list_t *element);

#endif /* !PRIVATE_LIST_H_ */
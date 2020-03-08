#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node *next;
} Node, *Stack; //Node等价于struct Node, Stack等价于struct Node *

Stack create_stack();

void empty_stack(Stack s);

void delete_stack(Stack s);

bool is_empty(Stack s);

bool push(Stack s, DataType data);

int pop(Stack s);

DataType get_top_element(Stack s);

int get_stack_size(Stack s);
#endif

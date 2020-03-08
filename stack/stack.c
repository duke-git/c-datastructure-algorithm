#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


/**
 * Create an empty stack
 * @return
 */
Stack create_stack()
{
    Stack s = (Stack) malloc(sizeof(Node));

    if(s == NULL) {
        printf("内存分配失败，程序退出！\n");
        exit(-1);
    }
    s->next = NULL;
    return s;
}

/**
 * Push element into stack
 * @param s
 * @return
 */
bool push(Stack s, DataType data)
{
    Stack new_node = (Stack) malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("内存分配失败，程序退出！\n");
        return false;
    }

    new_node->data = data;
    new_node->next = s->next;
    s->next = new_node;

    return true;
}


/**
 * pop element of stack
 * @param s
 * @return
 */
DataType pop(Stack s)
{
    if (is_empty(s) == true) {
        printf("栈为空！\n");
    }
    DataType data = get_top_element(s);
    Stack pop_node = s->next;
    s->next = s->next->next;
    free(pop_node);
    return data;
}

/**
 * Get the top element of stack
 * @param s
 * @return
 */
DataType get_top_element(Stack s)
{
    if (is_empty(s) == true) {
        printf("栈为空！\n");
    }

    return s->next->data;
}

/**
 * Get size of stack
 * @param s
 * @return
 */
int get_stack_size(Stack s)
{
    int size = 0;
    while(s->next) {
        size++;
    }
    return size;
}

/**
 *
 * @param s
 * @return
 */
bool is_empty(Stack s)
{
    if (s->next == NULL) {
        return true;
    } else {
        return false;
    }
}




#ifndef LINK_H
#define LINK_H
#include <stdbool.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkList; //Node等价于struct Node, LinkList等价于struct Node *


LinkList create_linkList();

void traverse_linkList(LinkList p_head);

int get_length(LinkList p_head);

LinkList find_element(LinkList p_head, int value);

bool is_empty(LinkList p_head);

bool insert_element(LinkList p_head, int position, int value);

bool delete_element(LinkList p_head, int position, int *value);

LinkList reverse_linklist(LinkList p_head);
#endif

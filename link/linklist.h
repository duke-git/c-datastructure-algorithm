#include <stdbool.h>

#ifndef LINK_H
#define LINK_H

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkList; //Node等价于struct Node, LinkList等价于struct Node *


LinkList create_linklist();

void traverse_linklist(LinkList p_head);

int get_length(LinkList p_head);

LinkList find_element(LinkList p_head, int value);

bool is_empty(LinkList p_head);

bool insert_element(LinkList p_head, int position, int value);

bool delete_element(LinkList p_head, int position, int *value);

LinkList reverse_linklist(LinkList p_head);

LinkList sort(LinkList p_head);

LinkList delete_after_n(LinkList p_head, int n);

LinkList merge_sorted_link(LinkList link_1, LinkList link_2);

LinkList get_middle_node(LinkList p_head);

#endif

#ifndef SKIPLIST_H
#define SKIPLIST_H

#define MAX_LEVEL 15

struct node {
    int val;
    int max_level;
    struct node *forward[MAX_LEVEL];
};

struct skip_list {
    struct node head;
    int max_level;
    int max_level_nodes;
};

void node_init(struct node* node);

void skip_list_init(struct skip_list* sl);

void insert_node(struct skip_list *sl, int val);

struct node *find(struct skip_list* sl, int val);

void delete_node(struct skip_list* sl, int val);

void print_sl(struct skip_list* sl);

#endif

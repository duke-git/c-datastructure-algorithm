#ifndef TREE_H
#define TREE_H

#define MAX_SIZE	1024

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} BinaryNode, *BinaryTree; //BinaryNode等价于struct Node, BinaryTree等价于struct Node *


BinaryTree create_binary_tree();

//横向打印
void print_binary_tree_hor(BinaryTree root);
//纵向打印
void print_binary_tree_ver(BinaryTree root);

int get_tree_height(BinaryTree root);

int get_tree_depth(BinaryTree root);

int get_node_count(BinaryTree root);

void pre_order_binary_tree(BinaryTree root);

void in_order_binary_tree(BinaryTree root);

void post_order_binary_tree(BinaryTree root);

void level_order_binary_tree(BinaryTree root);


//队列，用于二叉树层次遍历
typedef struct Queue {
    BinaryTree items[MAX_SIZE];
    int head;
    int tail;
} BtQueue;



#endif

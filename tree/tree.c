#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "tree.h"

BinaryTree create_binary_node(int i, int num);

int root_node_height_depth(BinaryTree root);

void print_node_hor(BinaryTree root, bool left, char* str);

/*
*	队列函数
*/
BtQueue* initQueue();
bool emptyQueue(BtQueue* q);
bool enQueue(BtQueue* q, BinaryTree bt);
BinaryTree deQueue(BtQueue* q);

/**
 * 1.从根节点开始编号，从上到下，从左到右，编号是连续的

   2.在n个节点的完成二叉树中，对于第i个节点，有如下特性:

   <0>父节点 : i != 1 ,它有父节点，且父节点的编号 i / 2

   <1>左孩子 : 2 * i <= n 表示i有左孩子节点，且左孩子节点的编号是2 * i

   <2>右孩子 : 2 * i + 1 <= n 表示i有右孩子节点，且右孩子节点的编号是2 * i + 1 

   <3>左兄弟 : i是奇数且i <= n,此时有左兄弟，且左兄弟的编号是i - 1

   <4>右兄弟 : i是偶数且i+1 <= n,此时有右兄弟，且右兄弟的编号是 i + 1
 * 创建完全二叉树
 * @param n（>=0)
 * @return
 */
BinaryTree create_binary_tree()
{
    int num;
    int i = 1;
    printf("请输入输入节点总数（>0）：");
    scanf("%d", &num);

    if (num < 1) {
        printf("节点总数需大于0\n");
        exit(-1);
    }
    BinaryTree root = create_binary_node(i, num);
    return root;
}

/**
 * 创建顺序：前序遍历， 父节点->左孩子->右孩子
 * @param n 当前节点编号
 * @param num 节点个数
 * @return
 */
BinaryTree create_binary_node(int i, int num)
{

    int data;
    if (i == 1) {
        printf("请输入根结点值（第1个节点）：");
    } else {
        printf("（第%d个结点）：", i);
    }

    scanf("%d", &data);

    BinaryTree root = (BinaryTree) malloc(sizeof(BinaryNode));
    if(root == NULL) {
        printf("内存分配失败，程序退出！\n");
        exit(-1);
    }

    root->data = data;
    root->left = NULL;
    root->right = NULL;

    if (2 * i <= num) { //左孩子
        printf("请输入%d的左孩子结点值", data);
        root->left = create_binary_node(2 * i, num);
    }
    if (2 * i + 1 <= num) { //右孩子
        printf("请输入%d的右孩子结点值", data);
        root->right = create_binary_node(2 * i + 1, num);
    }

    return root;
}

/**
 * get tree height
 * 叶子结点到根节点的最长路径（边数）
 * @param root
 * @return tree height start from 0
 */
int get_tree_height(BinaryTree root)
{
    int h = root_node_height_depth(root);
    return h - 1;
}

/**
 * get tree depth
 * 根节点到最深叶子节点所经历的边的个数
 * @param root
 * @return
 */
int get_tree_depth(BinaryTree root)
{
    int d =  root_node_height_depth(root);
    return d - 1;
}

/**
 * 获取根节点高度&深度
 * @param root
 * @return
 */
int root_node_height_depth(BinaryTree root)
{
    int rh = 0;
    int lh = 0;
    int max = 0;

    if (root != NULL) {
        lh = root_node_height_depth(root->left);
        rh = root_node_height_depth(root->right);

        max = (lh > rh) ? lh : rh;
        return max + 1;
    } else {
        return 0;
    }

}

/**
 *
 * @param root
 */
void print_binary_tree_hor(BinaryTree root) {
    char str[1024];
//    memset(str, '\0', 1000);

    if (root->left) {
        print_node_hor(root->left, true, str);
    }

    printf("%d\n", root->data);

    if (root->right) {
        print_node_hor(root->right, false, str);
    }
}

/**
 *
 * @param root
 */
void print_binary_tree_ver(BinaryTree root)
{

}

/**
 *
 * @param root
 * @param left
 * @param str
 */
void print_node_hor(BinaryTree root, bool left, char* str) {


    if (root->left) {
        print_node_hor(root->left, true, strcat(str, (left ? "    " : "|   ")));
    }

    printf("%s", str);
    printf("%c", (left==true ? '/' : '\\'));
    printf("----");
    printf("%d\n", root->data);

    if (root->right) {
        print_node_hor(root->right, false, strcat(str, (left ? "|   " : "    ")));
    }

    str[strlen(str) - 4] = '\0';
}

/**
 * 获取节点个数
 * @param root
 * @return
 */
int get_node_count(BinaryTree root)
{
    int count = 1;

    if (root != NULL) {
        count += get_node_count(root->left) + get_node_count(root->right);
    } else {
        count = 0;
    }
    return count;
}

/**
 * 前序遍历
 * 对于树中的任意节点来说，先打印这个节点，然后再打印它的左子树，最后打印它的右子树
 * @param root
 */
void pre_order_binary_tree(BinaryTree root)
{
    if (root == NULL)
        return;
    printf("%d -->", root->data);
    pre_order_binary_tree(root->left);
    pre_order_binary_tree(root->right);
}


/**
 * 中序遍历
 * @param root
 */
void in_order_binary_tree(BinaryTree root)
{
    if (root == NULL)
        return;

    pre_order_binary_tree(root->left);
    printf("%d -->", root->data);
    pre_order_binary_tree(root->right);
}
/**
 * 后序遍历
 * @param root
 */
void post_order_binary_tree(BinaryTree root)
{
    if (root == NULL)
        return;
    pre_order_binary_tree(root->left);
    pre_order_binary_tree(root->right);
    printf("%d -->", root->data);
}



/**
 * 层次遍历: 用一个队列保存被访问的当前节点的左右孩子以实现层次遍历。
   在进行层次遍历的时候，设置一个队列结构，遍历从二叉树的根节点开始，首先将根节点指针入队列，然后从队头取出一个元素，每取一个元素，执行下面两个操作：
   1 访问该元素所指向的节点
   2 若该元素所指节点的左右孩子节点非空，则将该元素所指节点的左孩子指针和右孩子指针顺序入队。此过程不断进行，当队列为空时，二叉树的层次遍历结束。
 * @param root
 */
void level_order_binary_tree(BinaryTree root)
{
    if (root == NULL)
        return;

    BtQueue* bt_queue = initQueue();
    enQueue(bt_queue, root);

    while(emptyQueue(bt_queue) == false) {
        BinaryTree bt = deQueue(bt_queue);
        if(bt != NULL) {
            printf("%d -->", bt->data);

            if(bt->left!=NULL)
                enQueue(bt_queue, bt->left);

            if(bt->right!=NULL)
                enQueue(bt_queue, bt->right);
        }
    }
}

//队列函数
BtQueue* initQueue()
{
    BtQueue* q = (BtQueue *) malloc(sizeof(BtQueue));

    if(q == NULL) {
        printf("内存分配失败，程序退出！\n");
        exit(-1);
    }
    q->head = 0;
    q->tail = 0;

    return q;
}

bool emptyQueue(BtQueue* q)
{
    if(q->head == q->tail) {
        return true;
    } else {
        return false;
    }
}

bool enQueue(BtQueue* q, BinaryTree bt)
{
    int tail = q->tail;

    //如果队尾没有空间
    if (tail == MAX_SIZE - 1) {
        return false;
    }

    (q->items)[tail] = bt;
    q->tail++;

    return true;
}

BinaryTree deQueue(BtQueue* q)
{
    int head = q->head;
    int tail = q->tail;

    if (head == tail) {
        printf("队列为空！\n");
        exit(-1);
    }
    BinaryTree item = (q->items)[head];
    q->head++;

    return item;
}
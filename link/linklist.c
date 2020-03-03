#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linklist.h"


/**
 * create linklist
 */
LinkList create_linkList()
{
    int length;
    int data;
    int i;

    //创建头节点
    LinkList p_head = (LinkList) malloc(sizeof(Node));

    if (NULL == p_head) {
        printf("内存分配失败，程序退出！\n");
        exit(-1);
    }

    //创建尾节点
    LinkList p_tail = p_head;
    p_tail->next = NULL;

    printf("请输入想要创建链表结点的个数：length = ");
    scanf("%d", &length);

    for (i = 0; i < length; i++) {
        printf("请输入第%d个结点的值：", i+1);
        scanf("%d", &data);
        LinkList p_new = (LinkList)malloc(sizeof(Node));
        if(NULL == p_new) {
            printf("内存分配失败，程序退出！\n");
            exit(-1);
        }

        p_new->data = data;
        p_tail->next = p_new;
        p_new->next = NULL;
        p_tail = p_new;
    }

    return p_head;

}

/**
 * traverse linklist
 * @param p_head : head pointer of linklist
 */
void traverse_linkList(LinkList p_head)
{
    printf("============开始遍历链表=============\n");

    if (p_head == NULL || p_head->next == NULL) {
        printf("链表为空\n");
    }

    //设置当前节点为第一个节点
    LinkList p_current = p_head->next;

    while (p_current != NULL) {
        printf("存储数据值：%d, 存储的指针值：%p\n ", p_current->data, p_current->next);
        p_current = p_current->next; //移动当前节点
    }

    printf("============结束遍历链表=============\n");
}
/**
 * get the elements length of linklist
 * @param p_head : head pointer of linklist
 * @return
 */
int get_length(LinkList p_head)
{
    int len = 0;

    if (p_head == NULL || p_head->next == NULL) {
        printf("链表不存在\n");
        return len;
    }
    LinkList p_current = p_head->next;;
    //设置当前节点为第一个节点
    while (p_current != NULL) {
        len++;
        p_current = p_current->next;
    };
    printf("链表长度为: %d\n", len);
    return len;
}

/**
 * find element in linklist
 * @param p_head header pointer of linklist
 * @param value the find value
 * @return the find node
 */
LinkList find_element(LinkList p_head, int value)
{
    if (p_head == NULL || p_head->next == NULL) {
        printf("链表不存在\n");
        return NULL;
    }

    int index = 0;

    LinkList p_current = p_head->next;;

    while (p_current != NULL) {
        index++;
        if (p_current->data == value) {
            printf("查找到第%d个节点，存储数据值：%d, 存储的指针值：%p\n ", index, p_current->data, p_current->next);
            return p_current;
        }
        p_current = p_current->next;
    };

    return NULL;
}

/**
 *
 * @param p_head
 * @return
 */
bool is_empty(LinkList p_head)
{
    if (p_head->next == NULL) {
        return true;
    } else {
        return false;
    }
}

#include <stdio.h>
#include "linklist.h"

void do_command();

int main()
{
    do_command();
    return 0;
}

void do_command()
{
    LinkList p_head = NULL;


    int choice;
    do
    {
        printf("==============================操作选择==============================\n");
        printf("1.创建列表\t2.遍历链表\t3.查找链表元素\n4.插入链表元素\t5.删除链表元素\t6.排序链表\n7.反置链表\t8.删除链表倒数第n个元素\n");
        printf("==============================操作选择==============================\n");

        printf("请输入你的选择:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:
            {
                printf("good bye\n");
                break;
            }
            case 1:
            {
                p_head = create_linklist();
                break;
            }
            case 2:
            {
                traverse_linklist(p_head);
                break;
            }
            case 3:
            {
                int value;
                printf("请输入查找的值: \n");
                scanf("%d", &value);
                find_element(p_head, value);
                break;
            }
            case 4:
            {
                int value, position;
                printf("原链表长度为: %d\n", get_length(p_head));
                printf("请输入插入位置（1～链表长度）: \n");
                scanf("%d", &position);
                printf("请输入插入的值: \n");
                scanf("%d", &value);
                insert_element(p_head, position, value);
                printf("插入后链表长度为: %d\n", get_length(p_head));
                break;
            }
            case 5:
            {
                int value, position;
                printf("请输入插入位置（1～链表长度）: \n");
                scanf("%d", &position);
                printf("请输入插入的值: \n");
                scanf("%d", &value);
                delete_element(p_head, position, &value);
                break;
            }
            case 6:
            {
                printf("链表排序前: \n");
                traverse_linklist(p_head);
                printf("链表排序后: \n");
                sort(p_head);
                traverse_linklist(p_head);
                break;
            }
            case 7:
            {
                reverse_linklist(p_head);
                traverse_linklist(p_head);
                break;
            }
            case 8:
            {
                int index;
                printf("请输入删除倒数第几个值: \n");
                scanf("%d", &index);
                delete_after_n(p_head, index);
                traverse_linklist(p_head);
                break;
            }

            default:printf("输入错误，请重新输入\n");
                break;
        }
    } while (choice != 0);
}
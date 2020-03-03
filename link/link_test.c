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
        printf("1.创建列表\t2.遍历链表\t3.查找链表元素\n4.插入链表元素\t5.删除链表元素\t6.排序链表\n7.反置链表\t8.返回链表长度\t9.ListDelete\n");
        printf("\n请输入你的选择:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
            {
                printf("good bye\n");
                break;
            }
            case 1:
            {
                p_head = create_linkList();
                break;
            }
            case 2:
            {
                traverse_linkList(p_head);
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

            default:printf("输入错误，请重新输入\n");
                break;
        }
    } while (choice != 0);
}
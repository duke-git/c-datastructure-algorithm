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
        printf("1.创建列表\t2.遍历链表\t3.查找链表元素\n4.插入链表元素\t5.删除链表元素\t6.排序链表\n"
               "7.反置链表\t8.删除链表倒数第n个元素\t9.合并两个有序链表\t10.获取链表中间节点\n");
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
            case 9:
            {
                printf("创建第一个有序链表: \n");
                LinkList link_1 = create_linklist();
                printf("创建第二个有序链表: \n");
                LinkList link_2 = create_linklist();
                printf("合并前两个链表: \n");
                traverse_linklist(link_1);
                traverse_linklist(link_2);
                printf("开始合并有序链表: \n");
                LinkList sorted_link = merge_sorted_link(link_1, link_2);
                printf("合并后链表: \n");
                traverse_linklist(sorted_link);
                break;
            }
            case 10:
            {
                printf("创建链表: \n");
                LinkList link = create_linklist();
                printf("链表长度: %d\n", get_length(link));

                LinkList middle_node = get_middle_node(link);
                if (middle_node != NULL) {
                    printf("链表中间节点: %d\n", middle_node->data);
                } else {
                    printf("链表不存在中间节点\n");
                }
                break;
            }

            default:printf("输入错误，请重新输入\n");
                break;
        }
    } while (choice != 0);
}
#include <stdio.h>
#include "tree.h"

void do_command();

int main()
{
    do_command();
    return 0;
}

void do_command()
{
    BinaryTree root = NULL;


    int choice;
    do
    {
        printf("==============================操作选择==============================\n");
        printf("1.创建完全二叉树\t2.前序遍历\t3.中序遍历\t4.后序遍历\t5.层次遍历\t6.获取树高度\t7横向打印树\n");
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
                root = create_binary_tree();
                break;
            }
            case 2:
            {
                printf("前序遍历\n");
                pre_order_binary_tree(root);
                printf("\n");
                break;
            }
            case 3:
            {
                printf("中序遍历\n");
                in_order_binary_tree(root);
                printf("\n");
                break;
            }
            case 4:
            {
                printf("后序遍历\n");
                post_order_binary_tree(root);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("层次遍历\n");
                level_order_binary_tree(root);
                printf("\n");
                break;
            }
            case 6:
            {
                int height = get_tree_height(root);
                printf("树高度：%d\n", height);
                break;
            }
            case 7:
            {
                printf("横向打印树\n");
                print_binary_tree_hor(root);
                break;
            }

            default:printf("输入错误，请重新输入\n");
                break;
        }
    } while (choice != 0);
}
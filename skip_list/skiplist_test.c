#include <stdio.h>
#include "skiplist.h"

void do_command();
void print_benchmark_result();
void print_result(int a[], int n, int flag);



int main()
{
    do_command();
    return 0;
}

void do_command()
{

    struct skip_list sl;
    struct node *node = NULL;
    int i;

    int choice;
    do {
        printf("\n==============================操作选择==============================\n");
        printf("1.初始化跳表\t2.查找跳表元素\t3.删除跳表元素\n");
        printf("==============================操作选择==============================\n");

        printf("请输入你的选择:");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("程序退出\n");
                return;
            case 1:
            {
                skip_list_init(&sl);
                print_sl(&sl);
                for (i = 0; i < 300; i++)
                    insert_node(&sl, i);
                print_sl(&sl);
                break;
            }
            case 2:
            {
                node = find(&sl, 8);
                if (node)
                    printf("find 8 in sl %d\n", node->val);
                else
                    printf("8 not in sl\n");
                break;
            }
            case 3:
            {
                for (i = 0; i < 5; i++) {
                    delete_node(&sl, i);
                    print_sl(&sl);
                }
                break;
            }
            default: printf("输入错误，请重新输入\n");
                break;
        }

    }while (choice != 0);

}



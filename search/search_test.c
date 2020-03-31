#include <stdio.h>
#include "search.h"

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

    int n = 1000;
    int a[1000];
    generate_order_array(a, n);
    int index = -1;

    int choice;
    do {
        printf("\n==============================操作选择==============================\n");
        printf("1.二分查找\t2.二叉排序树todo\t3.散列表todo\t4.查找函数benchmark\n");
        printf("==============================操作选择==============================\n");

        printf("请输入你的选择:");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("程序退出\n");
                return;
            case 1:
            {
                generate_order_array(a, n);
                int value;
                printf("输入查找元素（0～1000）:");
                scanf("%d", &value);
                index = binary_search(a, n, value);
                printf("查找值%d的位置为：%d\n", value, index);
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                print_benchmark_result();
                break;
            }
            default: printf("输入错误，请重新输入\n");
                break;
        }

    }while (choice != 0);

}

void print_benchmark_result()
{
    printf("--------------|-----------------|----------------\n");

    printf("Search function |  Execution time |  Time complexity\n");

    printf("--------------|-----------------|----------------\n");

    printf("%s   | %9.6f       | %s\n", "binary search", benchmark_search(binary_search), "O(logn)");

    printf("--------------|-----------------|----------------\n");
}


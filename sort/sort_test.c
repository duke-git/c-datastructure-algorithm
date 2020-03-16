
#include <stdio.h>
#include "sort.h"

void do_command();
void print_result(int a[], int n, int flag);

int main()
{
    do_command();
    return 0;
}

void do_command()
{
    int a[] = {5, 6, 4, 7, 9, 10, 3, 1, 2, 8};
    int n = 10;

    int choice;
    do {
        printf("\n==============================操作选择==============================\n");
        printf("1.冒泡排序\t2.插入排序\t3.选择排序\n4.快速排序\n");
        printf("==============================操作选择==============================\n");

        printf("请输入你的选择:");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("程序退出\n");
                return;
                break;
            case 1:
            {
                print_result(a, n, 0);
                bubble_sort(a, n);
                print_result(a, n, 1);
                break;
            }
            case 2:
            {
                print_result(a, n, 0);
                insert_sort(a, n);
                print_result(a, n, 1);
                break;
            }
            case 3:
            {
                print_result(a, n, 0);
                select_sort(a, n);
                print_result(a, n, 1);
                break;
            }
            default: printf("输入错误，请重新输入\n");
                break;
        }

    }while (choice != 0);

}

void print_result(int a[], int n, int flag)
{
    char *s;
    s = flag == 0 ? "排序前数组: " : "排序后数组: ";
    printf("%s", s);

    for (int i = 0; i < n; ++i) {
        if (i == n -1) {
            printf("%d\n", a[i]);
            break;
        } else {
            printf("%d, ", a[i]);
        }
    }
}
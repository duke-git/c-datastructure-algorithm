
#include <stdio.h>
#include "sort.h"

void do_command();
void print_benchmark_result();
void print_result(int a[], int n, int flag);

void generate_desc_order_array(int a[], int len, int base);

int main()
{
    do_command();
    return 0;
}

void do_command()
{
    int n = 10;
    int a[10];


//    int n = 100;
//    int a[100];
//    generate_desc_order_array(a, n, 100);

    int choice;
    do {
        printf("\n==============================操作选择==============================\n");
        printf("1.冒泡排序\t2.插入排序\t3.选择排序\t4.归并排序\t5.快速排序\t6.排序函数benchmark\n");
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
                generate_int_array(a, n);
                print_result(a, n, 0);
                bubble_sort(a, n);
                print_result(a, n, 1);
                break;
            }
            case 2:
            {
                generate_int_array(a, n);
                print_result(a, n, 0);
                insert_sort(a, n);
                print_result(a, n, 1);
                break;
            }
            case 3:
            {
                generate_int_array(a, n);
                print_result(a, n, 0);
                select_sort(a, n);
                print_result(a, n, 1);
                break;
            }
            case 4:
            {
                generate_int_array(a, n);
                print_result(a, n, 0);
                merge_sort(a, n);
                print_result(a, n, 1);
                break;
            }
            case 5:
            {
                generate_int_array(a, n);
                print_result(a, n, 0);
                merge_sort(a, n);
                print_result(a, n, 1);
                break;
            }
            case 6:
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

    printf("Sort function |  Execution time |  Time complexity\n");

    printf("--------------|-----------------|----------------\n");

    printf("%s   | %9.6f       | %s\n", "bubble sort", benchmark_sort(bubble_sort), "O(n^2)");

    printf("%s   | %9.6f       | %s\n", "insert sort", benchmark_sort(insert_sort), "O(n^2)");

    printf("%s   | %9.6f       | %s\n", "select sort", benchmark_sort(select_sort), "O(n^2)");

    printf("%s    | %9.6f       | %s\n", "merge sort", benchmark_sort(merge_sort), "O(nlogn)");

    printf("%s    | %9.6f       | %s\n", "quick sort", benchmark_sort(quick_sort), "O(nlogn)");

    printf("--------------|-----------------|----------------\n");
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

void generate_desc_order_array(int a[], int len, int base)
{
    for (int i = 0; i < len; i++) {
        a[i] = base;
        base--;
    }
}
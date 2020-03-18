
#include <stdio.h>
#include "sort.h"

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
    int a[] = {5, 6, 4, 7, 9, 10, 3, 1, 2, 8};
    int n = 10;

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
            case 4:
            {
                print_result(a, n, 0);
                merge_sort(a, n);
                print_result(a, n, 1);
                break;
            }
            case 5:
            {
//                print_result(a, n, 0);
//                merge_sort(a, n);
//                print_result(a, n, 1);

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
    int length = 10000;
    int a[10000];
    generate_int_array(a, length);

    printf("--------------|-----------------|----------------\n");

    printf("Sort function |  Execution time |  Time complexity\n");

    printf("--------------|-----------------|----------------\n");

    printf("%s   | %9.6f       | %s\n", "bubble sort", benchmark_sort(bubble_sort, a, length), "O(n^2)");

    printf("%s   | %9.6f       | %s\n", "insert sort", benchmark_sort(insert_sort, a, length), "O(n^2)");

    printf("%s   | %9.6f       | %s\n", "select sort", benchmark_sort(select_sort, a, length), "O(n^2)");

    printf("%s    | %9.6f       | %s\n", "merge sort", benchmark_sort(merge_sort, a, length), "O(nlogn)");

//    printf("%s  | %9.2lf     | %s\n", "quick sort", benchmark_sort(merge_sort, a, length), "O(nlogn)");

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
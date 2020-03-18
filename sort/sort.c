
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "sort.h"

void merge(int a[], int start, int middle, int end);

void merge_sort_recursion(int a[], int start, int end);

void quick_sort_recursion(int a[], int start, int end);

int partition(int a[], int start, int end);

void swap(int arr[], int a, int b);

void quick_sort_3_path(int data[], int left, int right);

void copy_n(int dest[], int src[], int start, int n);


/**
 * bubble sort (stable)
 * worst: O(n^2)
 * best: O(n)
 * average: O(n^2)
 * space: O(1)
 * 有序度：0 ～ n*(n-1)/2
 * 逆序度(交换测试)：满有序度-有序度
 * @param a array tobe sorted
 * @param n length of array
 */
void bubble_sort(int a[], int n) {
    if (n <= 1) return;

    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                flag = true;
            }
        }
        if (flag == false) break;
    }
}

/**
 * insert sort (stable)
 * worst: O(n^2)
 * best: O(n)
 * average: O(n^2)
 * space: O(1)
 * 有序度：0 ～ n*(n-1)/2
 * 逆序度(移动次数)：满有序度-有序度
 * @param a array tobe sorted
 * @param n length of array
 */
void insert_sort(int a[], int n) {
    if (n <= 1) return;

    int pre_index;
    int current_item;

    for (int i = 1; i < n; ++i) {
        pre_index = i -1;
        current_item = a[i];

        while (pre_index >= 0) {
            if (a[pre_index] > current_item) {
                a[pre_index + 1] = a[pre_index]; //数据移动
            } else {
                break;
            }
            pre_index--;
        }

        a[pre_index + 1] = current_item;
    }
}

/**
 * select sort (unstable)
 * worst: O(n^2)
 * best: O(n)
 * average: O(n^2)
 * space: O(1)
 * @param a array tobe sorted
 * @param n length of array
 */
void select_sort(int a[], int n) {
    if (n <= 1) return;

    int min_index;
    int tmp;

    for (int i = 0; i < n -1; ++i) {
        min_index = i;

        //寻找下标i以后的最小值
        for (int j = i+1; j < n; ++j) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            tmp = a[i];
            a[i] = a[min_index];
            a[min_index] = tmp;
        }
    }
}

/**
 * merge sort (stable)
 * worst: O(nlogn)
 * best: O(nlogn)
 * average: O(nlogn)
 * space: O(n)
 * @param a array tobe sorted
 * @param n length of array
 */
void merge_sort(int a[], int n)
{
    merge_sort_recursion(a, 0, n-1);
}

/**
 * 归并排序（递归）
 * @param a
 * @param start
 * @param end
 */
void merge_sort_recursion(int a[], int start, int end)
{
    if (start < end) {
        int middle = (start + end) / 2;
        merge_sort_recursion(a, start, middle);
        merge_sort_recursion(a, middle + 1, end);

        merge(a, start, middle, end);
    }
}


/**
 * 合并有序子序列
 * @param a
 * @param start
 * @param middle
 * @param end
 */
void merge(int a[], int start, int middle, int end)
{
    int len_left = middle - start + 1;
    int len_right = end - middle;

    int temp_left[len_left], temp_right[len_right];
    memcpy(temp_left, a + start, sizeof(int) * len_left);
    memcpy(temp_right, a + middle + 1, sizeof(int) * len_right);

    int i = 0, j = 0, index = start;

    while (i < len_left && j < len_right) {
        if (temp_left[i] < temp_right[j]) {
            a[index++] = temp_left[i++];
        }else {
            a[index++] = temp_right[j++];
        }
    }

    while (i < len_left) {
        a[index++] = temp_left[i++];
    }

}

/**
 * quick sort (unstable)
 * worst: O(nlogn)
 * best: O(nlogn)
 * average: O(nlogn)
 * space: O(n)
 * @param a array tobe sorted
 * @param n length of array
 * https://blog.csdn.net/a236209186/article/details/52012823
 */
void quick_sort(int a[], int n)
{
//    quick_sort_recursion(a, 0, n-1);
    quick_sort_3_path(a, 0, n-1);
}


/**
 *
 * @param a
 * @param start
 * @param end
 */
void quick_sort_recursion(int a[], int start, int end)
{
    if (start < end) {
        int pivot = partition(a, start, end);
        quick_sort_recursion(a, start, pivot-1);
        quick_sort_recursion(a, pivot+1, end);
    }
}

/**
 * 交换索引
 * @param arr
 * @param a
 * @param b
 */
void swap(int arr[], int a, int b)
{
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

/**
 * 三路快排
 * @param a
 * @param start
 * @param end
 * @return
 * https://www.jianshu.com/p/c61d1e82c44b
 */
void quick_sort_3_path(int data[], int left, int right)
{
    if (left < right) {
        float pivot = data[right];
        int l = left - 1;
        int j = left;
        int r = right;
        /*
        [left, l] 小于pivot
        [l+1, j] 等于pivot
        [j+1, right] 大于pivot
        */
        while (j < r) {
            if (data[j] < pivot) {
                swap(data, j, ++l);
                j++;
            }
            else if (data[j] > pivot) {
                swap(data, j, --r);
            }else {
                j++;
            }
        }
        swap(data, j, right);
        quick_sort_3_path(data, left, l);
        quick_sort_3_path(data, j+1, right);
    }
}

/**
 *
 * @param a
 * @param start
 * @param end
 * @return
 */
int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int i = start;

    for (int j = start; j < end; ++j) {
        if (a[j] < pivot) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }

    int tmp = a[i];
    a[i] = a[end];
    a[end] = tmp;

    return i;
}


/**
 * 数组拷贝(从start开始，复制n个src元素到dest中)
 * @param dest
 * @param src
 * @param start (start from 0)
 * @param n
 */
void copy_n(int dest[], int src[], int start, int n)
{
    int dest_index, src_index = start;

    for (dest_index = 0; dest_index < n; dest_index++) {
        dest[dest_index] = src[src_index];
        if (src[src_index] != 0) {
            src_index++;
        }
    }
}

/**
 * 生成元素为1-200的随机数组
 * @param length
 */
void generate_int_array(int a[], int length)
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < length; i++){
        int value = rand() % 200 + 1;
        a[i] = value;
    }
}

//**
// * 排序函数benchmark
// * benchmark基准：数组元素数量为一万，值为1-200
// * @param sort_func1, sort_func2
// */
//void benchmark_sort(void (*sort_func1) (int a[], int n), void (*sort_func2) (int a[], int n))
//{
//    int length = 10000;//2000000;
//    int a[10000];
//    generate_int_array(a, length);
//
//    clock_t start, finish;
//    double total_time;
//    start = clock();
//    sort_func1(a, length);
//    finish = clock();
//    total_time = (double)(finish - start) / CLOCKS_PER_SEC;
//    printf("执行函数%s所用时间: %f\n", "sort_func1", total_time);
//
//    clock_t start2, finish2;
//    double total_time2;
//    start2 = clock();
//    sort_func2(a, length);
//    finish2 = clock();
//    total_time2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
//    printf("执行函数%s所用时间: %f\n", "sort_func2", total_time2);
//}


/**
 * 排序函数benchmark
 * benchmark基准：数组元素数量为一万，值为1-200
 * @param sort_func
 */
double benchmark_sort(void (*sort_func) (int a[], int n))
{
    int length = 10000;//2000000;
    int a[10000];
    generate_int_array(a, length);
    clock_t start, finish;
    double total_time;
    start = clock();
    sort_func(a, length);
    finish = clock();
    total_time = (double)(finish - start) / CLOCKS_PER_SEC;

    return total_time;
}

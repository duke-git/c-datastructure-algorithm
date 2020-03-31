#include <stdio.h>
#include <time.h>
#include "search.h"



/**
 *
 * @param a
 * @param n
 * @param value
 * @return
 */
int binary_search(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        //【low, high]取中
//        int mid = (high - low) / 2;
        int mid = low + ((high - low) >> 1);

        if (a[mid] == value) {
            return mid;
        } else if (a[mid] < value) {
            low = mid + 1;
        } else if (a[mid] > value) {
            high = mid - 1;
        }
    }
    return -1;
}

/**
 * 查找第一个值等于给定值的元素
 * @param a
 * @param n
 * @param value
 * @return
 */
int binary_search_equal_first(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + ((high - low) >> 1);

        if (a[mid] < value) {
            low = mid + 1;
        } else if (a[mid] > value) {
            high = mid - 1;
        } else {
            if ((mid == 0) || (a[mid - 1] != value)) return mid;
            else high = mid - 1;
        }
    }
    return -1;
}

/**
 * 查找最后一个值等于给定值的元素
 * @param a
 * @param n
 * @param value
 * @return
 */
int binary_search_equal_last(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + ((high - low) >> 1);

        if (a[mid] < value) {
            low = mid + 1;
        } else if (a[mid] > value) {
            high = mid - 1;
        } else {
            if ((mid == n -1) || (a[mid + 1] != value)) return mid;
            else low = mid + 1;
        }
    }
    return -1;
}

/**
 * 查找第一个大于等于给定值的元素
 * @param a
 * @param n
 * @param value
 * @return
 */
int binary_search_gt_first(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + ((high - low) >> 1);

        if (a[mid] >= value) {
            if((mid == 0) || (a[mid-1] < value)) return mid;
            else high = mid + 1;
        }else {
             low = mid + 1;
        }
    }
    return -1;
}

/**
 * 查找最后一个小于等于给定值的元素
 * @param a
 * @param n
 * @param value
 * @return
 */
int binary_search_lt_first(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + ((high - low) >> 1);

        if (a[mid] <= value) {
            if((mid == n-1) || (a[mid+1] > value)) return mid;
            else high = mid + 1;
        }else {
            high = mid - 1;
        }
    }
}

/**
 * 二分法求平方根
 * @param x
 * @param precision
 * @return
 */
double binary_sqrt(double x, double precision)
{
    if (x < 0) {
        printf("Error: x is negative");
    }
    double low = 0;
    double high = x;
    if (x > 0 && x < 1) {
        low = x;
        high = 1;
    }

    double mid = low + (high - low) / 2;
    while (high - low > precision) {
        if (mid * mid > x) {
            high = mid;
        } else if (mid * mid < x) {
            low = mid;
        } else {
            return mid;
        }
        mid = low + (high - low) / 2;
    }
    return mid;
}



/**
 * 查找函数benchmark
 * benchmark基准：数组元素数量为1000000
 * @param sort_func
 */
double benchmark_search(int (*search_func) (int a[], int n, int value))
{
    int length = 1000000;//2000000;
    int a[1000000];
    int value = 0;
    generate_order_array(a, length);
    clock_t start, finish;
    double total_time;
    start = clock();
    search_func(a, length, value);
    finish = clock();
    total_time = (double)(finish - start) / CLOCKS_PER_SEC;

    return total_time;
}

/**
 *
 * @param a
 * @param len
 */
void generate_order_array(int a[], int len)
{
    for (int i = 0; i < len; i++) {
        a[i] = i;
    }
}
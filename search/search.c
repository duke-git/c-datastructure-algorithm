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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

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

        tmp = a[i];
        a[i] = a[min_index];
        a[min_index] = tmp;
    }
}
/**
 * 排序算法的执行效率:
 * 1. 最好情况、最坏情况、平均情况时间复杂度
 * 2. 时间复杂度的系数、常数 、低阶
 * 3. 比较次数和交换（或移动）次数
 *
 * 稳定性,
 *
 */

#ifndef SORT_H
#define SORT_H

void bubble_sort(int a[], int n);

void insert_sort(int a[], int n);

void select_sort(int a[], int n);

void merge_sort(int a[], int n);

void quick_sort(int a[], int n);

//void copy_n(int dest[], int src[], int start, int n);

void generate_int_array(int a[], int length);

double benchmark_sort(void (*sort_func1) (int a[], int n), int a[], int length);

#endif

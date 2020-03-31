#ifndef SEARCH_H
#define SEARCH_H

int binary_search(int a[], int n, int value);

int binary_search_equal_first(int a[], int n, int value);

int binary_search_equal_last(int a[], int n, int value);

int binary_search_gt_first(int a[], int n, int value);

int binary_search_lt_first(int a[], int n, int value);

double binary_sqrt(double x, double precision);

void generate_order_array(int a[], int len);

double benchmark_search(int (*search_func) (int a[], int n, int value));

#endif

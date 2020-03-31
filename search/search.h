#ifndef SEARCH_H
#define SEARCH_H

int binary_search(int a[], int n, int value);

void generate_order_array(int a[], int len);

double benchmark_search(int (*search_func) (int a[], int n, int value));

#endif

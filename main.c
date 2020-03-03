#include <stdio.h>

int main() {
    int a = 1;
    double b = 1.4f;
    int *p = &a;
    double *q = &b;

    printf("int类型指针大小 = %d\n", sizeof(p));

    printf("double类型指针大小 = %d\n", sizeof(q));

    return 0;
}
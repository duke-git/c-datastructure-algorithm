#ifndef QUEUE_H
#define QUEUE_H
#define MAX_SIZE 16
typedef int DataType;

typedef struct ArrayQueue {
    int items[MAX_SIZE];
    int size;
    int head;
    int tail;
}  *ArrayQueue;

#endif

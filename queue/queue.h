#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 16

typedef int DataType;

typedef struct ArrayQueueTag {
    DataType items[MAX_SIZE];
    int size;
    int head;
    int tail;
} QueueNode, *ArrayQueue;

ArrayQueue create_queue(int size);

bool enqueue(ArrayQueue queue, DataType item);

DataType dequeue(ArrayQueue queue);

void traverse_queue(ArrayQueue queue);


#endif

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


//循环队列
typedef struct CircularQueueTag {
    DataType items[MAX_SIZE];
    int size;
    int head;
    int tail;
} CircularQueueNode, *CircularQueue;

CircularQueue create_circular_queue(int size);

bool enqueue_circular(CircularQueue queue, DataType item);

DataType dequeue_circular(CircularQueue queue);

void traverse_circular_queue(CircularQueue queue);


#endif

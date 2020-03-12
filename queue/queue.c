#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

/**
 * Create queue
 * @return
 */
ArrayQueue create_queue(int size)
{
    ArrayQueue queue = (ArrayQueue) malloc(sizeof(QueueNode));

    if(queue == NULL) {
        printf("内存分配失败，程序退出！\n");
        exit(-1);
    }
    queue->size = size;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

/**
 * Item enqueue
 * @param queue
 * @param item
 * @return
 */
bool enqueue(ArrayQueue queue, DataType item)
{
    int head = queue->head;
    int tail = queue->tail;
    int size = queue->size;

    //如果队尾没有空间
    if (tail == size) {
        //队列无空间
        if (head == 0) {
            printf("队列已满！\n");
            return false;
        }
        //数据搬移
        for (int i = head; i < tail; ++i) {
            (queue->items)[i-head] = (queue->items)[i];
        }
        tail = tail - head;
        queue->tail = tail;
        queue->head = 0;
    }

    (queue->items)[tail] = item;
    queue->tail++;

    return true;
}

/**
 * item dequeue
 * @param queue
 * @return
 */
DataType dequeue(ArrayQueue queue)
{
    int head = queue->head;
    int tail = queue->tail;

    if (head == tail) {
        printf("队列为空！\n");
        return -1;
    }
    DataType item = (queue->items)[head];
    queue->head++;

    return item;
}

/**
 * Traverse queue
 * @param queue
 */
void traverse_queue(ArrayQueue queue)
{
    int head = queue->head;
    int tail = queue->tail;

    if (head == tail) {
        printf("队列为空！\n");
    }

    printf("当前队列元素: ");
    for (int i = head; i < tail; ++i) {
        if (i == tail-1) {
            printf("%d", (queue->items)[i]);
        }else {
            printf("%d-->", (queue->items)[i]);
        }
    }
}

/**
 * Create queue
 * @return
 */
CircularQueue create_circular_queue(int size)
{
    ArrayQueue queue = (ArrayQueue) malloc(sizeof(QueueNode));

    if(queue == NULL) {
        printf("内存分配失败，程序退出！\n");
        exit(-1);
    }
    queue->size = size;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

/**
 * Item enqueue
 * @param queue
 * @param item
 * @return
 */
bool enqueue_circular(CircularQueue queue, DataType item)
{
    int head = queue->head;
    int tail = queue->tail;
    int size = queue->size;

    //如果队尾没有空间
    if ( (tail + 1) % size == head) {
        printf("队列已满！\n");
        return false;
    }

    (queue->items)[tail] = item;
    tail = (tail + 1) % size;
    queue->tail = tail;

    return true;
}

/**
 * item dequeue
 * @param queue
 * @return
 */
DataType dequeue_circular(CircularQueue queue)
{
    int head = queue->head;
    int tail = queue->tail;
    int size = queue->size;

    if (head == tail) {
        printf("队列为空！\n");
        return -1;
    }
    DataType item = (queue->items)[head];
    head = (tail + 1) % size;
    queue->head = head;

    return item;
}

/**
 * Traverse circular queue
 * @param queue
 */
void traverse_circular_queue(CircularQueue queue)
{
    int head = queue->head;
    int tail = queue->tail;

    if (head == tail) {
        printf("队列为空！\n");
    }

    printf("当前队列元素: ");
    for (int i = head; i < tail; ++i) {
        if (i == tail-1) {
            printf("%d", (queue->items)[i]);
        }else {
            printf("%d-->", (queue->items)[i]);
        }
    }
}
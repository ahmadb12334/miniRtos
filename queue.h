// ========================= queue.h =========================

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 10

typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void queue_init(Queue *q);

int queue_enqueue(Queue *q, int value);

int queue_dequeue(Queue *q, int *value);

#endif
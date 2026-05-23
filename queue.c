// ========================= queue.c =========================

#include "queue.h"

void queue_init(Queue *q) {

    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

int queue_enqueue(Queue *q, int value) {

    if (q->count >= QUEUE_SIZE) {
        return 0;
    }

    q->data[q->rear] = value;

    q->rear = (q->rear + 1) % QUEUE_SIZE;

    q->count++;

    return 1;
}

int queue_dequeue(Queue *q, int *value) {

    if (q->count <= 0) {
        return 0;
    }

    *value = q->data[q->front];

    q->front = (q->front + 1) % QUEUE_SIZE;

    q->count--;

    return 1;
}
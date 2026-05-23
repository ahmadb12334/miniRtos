// ========================= semaphore.h =========================

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

typedef struct {
    int count;
} Semaphore;

void semaphore_init(Semaphore *sem, int value);
void semaphore_wait(Semaphore *sem);
void semaphore_signal(Semaphore *sem);

#endif
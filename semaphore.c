// ========================= semaphore.c =========================

#include "semaphore.h"

void semaphore_init(Semaphore *sem, int value) {

    sem->count = value;
}

void semaphore_wait(Semaphore *sem) {

    while (sem->count <= 0);

    sem->count--;
}

void semaphore_signal(Semaphore *sem) {

    sem->count++;
}
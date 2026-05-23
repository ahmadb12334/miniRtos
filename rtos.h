// ========================= rtos.h =========================

#ifndef RTOS_H
#define RTOS_H

#define MAX_TASKS 10

typedef void (*TaskFunction)(void);

typedef enum {
    READY,
    RUNNING,
    BLOCKED
} TaskState;

typedef struct {
    TaskFunction function;
    TaskState state;
    int delay_ticks;
    int priority;
    int id;
} Task;

void rtos_create_task(TaskFunction function, int priority);
void rtos_start(void);
void rtos_delay(int ticks);
void rtos_tick_update(void);

#endif
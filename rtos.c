// ========================= rtos.c =========================

#include <stdio.h>
#include "rtos.h"

static Task tasks[MAX_TASKS];

static int task_count = 0;
static int current_task = -1;
static int system_tick = 0;

void rtos_create_task(TaskFunction function, int priority) {

    if (task_count < MAX_TASKS) {

        tasks[task_count].function = function;
        tasks[task_count].state = READY;
        tasks[task_count].delay_ticks = 0;
        tasks[task_count].priority = priority;
        tasks[task_count].id = task_count;

        task_count++;
    }
}

void rtos_delay(int ticks) {

    if (current_task >= 0) {

        tasks[current_task].delay_ticks = ticks;
        tasks[current_task].state = BLOCKED;
    }
}

void rtos_tick_update(void) {

    system_tick++;

    for (int i = 0; i < task_count; i++) {

        if (tasks[i].state == BLOCKED) {

            tasks[i].delay_ticks--;

            if (tasks[i].delay_ticks <= 0) {

                tasks[i].state = READY;
            }
        }
    }
}

static int scheduler_select_task(void) {

    int highest_priority = -1;
    int selected_task = -1;

    for (int i = 0; i < task_count; i++) {

        if (tasks[i].state == READY) {

            if (tasks[i].priority > highest_priority) {

                highest_priority = tasks[i].priority;
                selected_task = i;
            }
        }
    }

    return selected_task;
}

void rtos_start(void) {

    while (1) {

        rtos_tick_update();

        current_task = scheduler_select_task();

        if (current_task >= 0) {

            tasks[current_task].state = RUNNING;

            tasks[current_task].function();

            if (tasks[current_task].state == RUNNING) {

                tasks[current_task].state = READY;
            }
        }
    }
}
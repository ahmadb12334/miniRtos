// ========================= main.c =========================

#include <stdio.h>
#include "rtos.h"
#include "queue.h"
#include "semaphore.h"

Queue message_queue;

Semaphore uart_semaphore;

void sensor_task(void) {

    static int sensor_value = 0;

    sensor_value++;

    printf("[Sensor Task] Reading sensor value: %d\n", sensor_value);

    queue_enqueue(&message_queue, sensor_value);

    rtos_delay(3);
}

void uart_task(void) {

    int value;

    semaphore_wait(&uart_semaphore);

    if (queue_dequeue(&message_queue, &value)) {

        printf("[UART Task] Sending value: %d\n", value);
    }

    semaphore_signal(&uart_semaphore);

    rtos_delay(2);
}

void logger_task(void) {

    printf("[Logger Task] Logging system status\n");

    rtos_delay(5);
}

void fault_monitor_task(void) {

    printf("[Fault Monitor] System healthy\n");

    rtos_delay(4);
}

int main(void) {

    queue_init(&message_queue);

    semaphore_init(&uart_semaphore, 1);

    rtos_create_task(sensor_task, 3);

    rtos_create_task(uart_task, 2);

    rtos_create_task(logger_task, 1);

    rtos_create_task(fault_monitor_task, 4);

    rtos_start();

    return 0;
}
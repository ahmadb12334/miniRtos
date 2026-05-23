# ========================= Makefile =========================

CC = gcc

CFLAGS = -Wall -Wextra

all:
	$(CC) $(CFLAGS) main.c rtos.c queue.c semaphore.c -o mini_rtos

run:
	./mini_rtos

clean:
	del mini_rtos.exe
# Mini RTOS in C

A lightweight Real-Time Operating System (RTOS) simulator written in C that demonstrates core embedded firmware and operating system concepts including task scheduling, synchronization, inter-task communication, and timing management.

---

# Features

- Priority-based task scheduling
- Task Control Blocks (TCBs)
- Task states:
  - READY
  - RUNNING
  - BLOCKED
- Simulated system tick timer
- Non-blocking task delays
- Message queue implementation
- Semaphore synchronization
- Inter-task communication
- Fault monitoring simulation

---

# Concepts Demonstrated

This project models several core embedded and firmware engineering concepts:

- Real-time task scheduling
- Embedded systems architecture
- Concurrency
- Synchronization primitives
- Non-blocking execution
- Event-driven systems
- Shared resource protection
- Firmware task management

---

# Project Structure

```txt
mini-rtos-c/
│
├── main.c
├── rtos.c
├── rtos.h
├── queue.c
├── queue.h
├── semaphore.c
├── semaphore.h
├── Makefile
└── README.md

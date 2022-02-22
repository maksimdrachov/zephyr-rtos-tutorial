---
layout: post
title: '10.1 Introduction'
parent: 'Lesson 10: Semaphores'
---

# Introduction

## What is a semaphore?

A semaphore is a kernel object that implements a traditional counting semaphore.

Any number of semaphores can be defined (limited only by available RAM). Each semaphore is referenced by its memory address.

A semaphore has the following key properties:
- A count that indicates the number of times the semaphore can be taken. A count of zero indicates that the semaphore is unavailable.
- A limit that indicates the maximum value the semaphore's count can reach.

A semaphore must be initialized before it can be used. Its count must be set to a non-negative value that is less than or equal to its limit.

A semaphore may be given by a thread or an ISR. Giving the semaphore increments its count, unless the count is already equal to the limit.

A semaphore may be taken by a thread. Taking the semaphore decrements its count, unless the semaphore is unavailable (i.e. at zero). When a semaphore is unavaible a thread may choose to wait for it to be given. Any number of threads may wait on an unavailable semaphore simultaneously. When the semaphore is given, it is taken by the highest priority thread that has waited the longest.

Note: The kernel does allow an ISR to take a semaphore, however the ISR must not attempt to wait if the semaphore is unavailable.

## How to define a semaphore?

A semaphore is defined using a variable of type k_sem. It must then be initialized by calling k_sem_init().

The following code defines a semaphore, then configures it as a binary semaphore by setting its count to 0 and its limit to 1.

```
struct k_sem my_sem;

k_sem_init(&my_sem, 0, 1);
```

Alternatively, a semaphore can be defined and initialized at compile time by calling K_SEM_DEFINE.

The following code has the same effect as the code segment above.

```
K_SEM_DEFINE(my_sel, 0, 1);
```

## How to use a semaphore?

A semaphore is given by calling k_sem_give().

The following code builds on the example above, and gives the semaphore to indicate that a unit of data is available for processing by a consumer thread.

```
void input_data_interrupt_handler(void *arg)
{
    /* notify thread that data is available */
    k_sem_give(&my_sem);

    ...
}
```

A semaphore is taken by calling k_sem_take().

The following code builds on the example above, and waits up to 50 milliseconds for the semaphore to be given. A warning is issued if the semaphore is not obtained in time.

```
void consumer_thread(void)
{
    ...

    if (k_sem_take(&my_sem, K_MSEC(50)) != 0) {
        printk("Input data not available!");
    } else {
        /* fetch available data */
        ...
    }
    ...
}
```

## When to use semaphores?

Use a semaphore to control access to a set of resources by multiple threads.

Use a semaphore to synchronize processing between a producing and consuming threads or ISRs.
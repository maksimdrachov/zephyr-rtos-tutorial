# Threads
- [Threads](#threads)
  - [1. Introduction](#1-introduction)
  - [2. Thread commands](#2-thread-commands)
    - [2.1. k_thread_start()](#21-k_thread_start)
    - [2.2. k_thread_abort()](#22-k_thread_abort)
    - [2.3. k_sleep()](#23-k_sleep)
    - [2.4. k_thread_suspend()](#24-k_thread_suspend)
    - [2.5. k_thread_join()](#25-k_thread_join)
  - [3. Thread states](#3-thread-states)
  - [4. Thread stack objects](#4-thread-stack-objects)
  - [5. Thread priorities](#5-thread-priorities)
  - [6. Thread options](#6-thread-options)
  - [7. Examples](#7-examples)
  - [8. Runtime statistics](#8-runtime-statistics)
  - [9. API reference](#9-api-reference)

## 1. Introduction

- **Stack area**: a region of memory used for the thread's stack. The size can be adjusted as required by the thread's processing.
- **Thread control block**: for internal bookkeeping of the thread's metadata. An instance of the type `k_thread`.
- **Entry point function**: invoked when the thread is started. Up to 3 argument values can be passed to this function. 
- **Scheduling policy**: intstructs the kernel's scheduler how to allocate CPU time to the thread. (See Scheduling)
- **Thread options**: allows the thread to receive special treatment by the kernel. (See Thread options)
- **Start delay**: specifies how long the kernel should wait before starting the thread.
- **Execution mode**: can be supervisor or user mode. By default, threads run in supervisor mode and allow access to privileged CPU instructions, the entire memory address space, and peripherals. User mode threads have a reduced set of privileges. (See User Mode)

## 2. Thread commands

### 2.1. k_thread_start()

A thread must be created before it can be used.

![k_thread_im](svg-images/k_thread_start.png)

### 2.2. k_thread_abort()
Abort a thread. Thread is taken off all kernel queues.

![k_thread_im](svg-images/k_thread_abort.png)

### 2.3. k_sleep()
A thread can prevent itself from executing for a specified amount of time. A sleeping thread becomes executable automatically once the time limit is reached.

![k_thread_im](svg-images/k_thread_sleep.png)

### 2.4. k_thread_suspend()
Prevent a thread from executing for an indefinite period of time. Once suspended, use k_thread_resume() to re-start.

![k_thread_im](svg-images/k_thread_suspend.png)

### 2.5. k_thread_join()
Sleep until a thread exits. 

![k_thread_im](svg-images/k_thread_join.png)


For example:
- THREAD_1 is responsible for setting up a hardware interface
- THREAD_2 is responsible for processing data from this interface
- As long as THREAD_1 has not exited, THREAD_2 can't start, so we'll use k_thread_join(THREAD_1, timeout) in this case.

## 3. Thread states
Ready: eligible to be selected as the next running thread.

Following factors can make a thread unready:
- Thread has not been started
- Waiting for a kernel object to complete an operation (for example, the thread is taking semaphore that is unavailable)
- Waiting for a timeout to occur
- Thread has been suspended
- Thread has terminated or aborted

![thread_states](images/thread_states_png.png)

## 4. Thread stack objects
- Use K_KERNEL_STACK macros if:
  - thread will never run in user mode
  - stack is being used for special contexts like handling interrupts
- Use K_THREAD_STACK macros if:
  - stack will need to host user threads

If CONFIG_USERSPACE is not enabled, K_THREAD_STACK macros have same effect as K_KERNEL_STACK.

## 5. Thread priorities
A thread's priority is an integer value, and can be either negative or positive. Numerically lower priorities take precedence over numerically higher values. 

Scheduler distinguishes two classes of threads based on their priority:
- Cooperative thread: has a negative priority value. Once it becomes the current thread, a cooperative thread remains the current thread until it performs an action that makes it unready.
- Preemptible thread: has a non-negative priority value. Once it becomes the current thread, a preemptible thread may be supplanted at any time if a cooperative thread, or a preemptible thread of higher or equal priority, becomes ready.

The priority of a thread can be changed, even after it has already started.

CONFIG_NUM_COOP_PRIORITIES and CONFIG_NUM_PREEMPT_PRIORITIES specify the number of priority levels for each class of thread.

## 6. Thread options
Kernel supports thread options that allow a thread to receive special treatment under specific circumstances.

- K_ESSENTIAL: tags the thread as an essential thread. Instructs the kernel to treat the termination or aborting of the thread as a fatal system error.
- K_FP_REGS: indicates that the thread uses the CPU's floating point registers. Instructs the kernel to take additional steps to save and restore the contents of these registers when scheduling the thread. 
- K_USER: if CONFIG_USERSPACE is enabled, this thread will be created in user mode and will have reduced privileges.
- K_INHERIT_PERMS: if CONFIG_USERSPACE is enabled, this thread will inherit all kernel object permissions that the parent thread had.

## 7. Examples
**k_thread_start()**

![k_thread_start](images/k_thread_start.png)

**k_thread_abort()**

![k_thread_start](images/k_thread_abort.png)

**k_sleep()**

![k_thread_start](images/k_thread_sleep.png)

**k_thread_suspend()**

![k_thread_start](images/k_thread_suspend.png)

**k_thread_join()**

![k_thread_start](images/k_thread_join.png)



## 8. Runtime statistics
Thread runtime statistics can be gathered and retrieved if CONFIG_THREAD_RUNTIME_STATS is enabled, for example, total number of execution cycles of a thread.

```
k_thread_runtime_stats_t rt_stats_thread;

k_thread_runtime_stats_get(k_current_get(), &rt_stats_thread);

printk("Cycles: %llu\n", rt_stats_thread.execution_cycles);
```

## 9. API reference
See [zephyr-wiki](https://docs.zephyrproject.org/latest/reference/kernel/threads/index.html#api-reference) (scroll down)

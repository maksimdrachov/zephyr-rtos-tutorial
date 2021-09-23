## Threads

*What are threads?* 

A thread is an isolated instance that is responsible for the execution of some task. While a microcontroller usually only has 1 CPU, the RTOS is able to have multiple tasks execute (seemingly) simultanously by exchanging the thread that gets run on the CPU as dictated by the scheduler. 

 Some key concepts:
- **Stack area**: a region of memory used for the thread's stack. The size can be adjusted as required by the thread's processing.
- **Thread control block**: for internal bookkeeping of the thread's metadata. An instance of the type `k_thread`.
- **Entry point function**: invoked when the thread is started. Up to 3 argument values can be passed to this function. 
- **Scheduling policy**: intstructs the kernel's scheduler how to allocate CPU time to the thread. (See Scheduling)
- **Execution mode**: can be supervisor or user mode. By default, threads run in supervisor mode and allow access to privileged CPU instructions, the entire memory address space, and peripherals. User mode threads have a reduced set of privileges.

The specifics of how to define a thread will be discussed in the next section

## Thread creation



## Thread states
*How does Zephyr choose which thread to run?*

"Thread is ready" = eligible to be selected as the next running thread.

Following factors can make a thread unready:
- Thread has not been started
- Waiting for a kernel object to complete an operation (for example, the thread is taking semaphore that is unavailable)
- Waiting for a timeout to occur
- Thread has been suspended
- Thread has terminated or aborted

The following diagram shows all the possible states a thread can find itself:

![thread_states](/images/threads/thread-states.png)
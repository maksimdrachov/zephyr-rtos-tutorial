## Thread commands
### k_thread_start()
A thread must be created before it can be used.

![k_thread_im](/svg-images/k_thread_start.png)

### k_thread_abort()
Abort a thread. Thread is taken off all kernel queues.

![k_thread_im](/svg-images/k_thread_abort.png)

### k_sleep()
A thread can prevent itself from executing for a specified amount of time. A sleeping thread becomes executable automatically once the time limit is reached.

![k_thread_im](/svg-images/k_thread_sleep.png)

### k_thread_suspend()
Prevent a thread from executing for an indefinite period of time. Once suspended, use k_thread_resume() to re-start.

![k_thread_im](/svg-images/k_thread_suspend.png)

### k_thread_join()
Sleep until a thread exits. 

For example:
- Thread b is responsible for setting up a hardware interface
- Thread a is responsible for processing data from this interface
- As long as thread b has not exited, thread a can't start, so we'll use k_thread_join(thread_b, timeout) in this case.

![k_thread_im](/svg-images/k_thread_join.png)

## Thread creation
A thread is spawned by defining its stack area and its thread control block, and then calling k_thread_create().

The stack area must be defined using K_THREAD_STACK_DEFINE or K_KERNEL_STACK_DEFINE to ensure it is properly set up in memory.

The thread spawning function returns its thread id, which can be used to reference the thread.

The following code spawns a thread that starts immediately.
```c
#define MY_STACK_SIZE 500
#define MY_PRIORITY 5

extern void my_entry_point(void *, void *, void *);

K_THREAD_STACK_DEFINE(my_stack_area, MY_STACK_SIZE);
struct k_thread my_thread_data;

k_tid_t my_tid = k_thread_create(&my_thread_data, my_stack_area,
                                 K_THREAD_STACK_SIZEOF(my_stack_area),
                                 my_entry_point,
                                 NULL, NULL, NULL,
                                 MY_PRIORITY, 0, K_NO_WAIT);
```

Alternatively, a thread can be declared at compile time by calling K_THREAD_DEFINE. Observe that the macro defines the stack area, control block, and thread id variables automatically.

The following code has the same effect as the code segment above.
```c
#define MY_STACK_SIZE 500
#define MY_PRIORITY 5

extern void my_entry_point(void *, void *, void *);

K_THREAD_DEFINE(my_tid, MY_STACK_SIZE,
                my_entry_point, NULL, NULL, NULL,
                MY_PRIORITY, 0, 0);
```

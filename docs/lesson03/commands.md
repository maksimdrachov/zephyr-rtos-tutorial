## Commands
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

## Thread states

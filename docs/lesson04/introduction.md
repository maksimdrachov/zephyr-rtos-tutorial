## Key concepts
- **Current thread**: the thread that is currently executing.
- **Reschedule points**: when the scheduler is given an opportunity to change the identity of the current thread. Potential reschedule points:
  - transition of a thread from running state to a suspended state or waiting state, for example by k_sem_take() or k_sleep()
  - transition of a thread to the ready state, for example by k_sem_give() or k_thread_start()
  - return to thread context after processing an interrupt
  - when a running thread invokes k_yield()

## Suggested uses
Use cooperative threads for device drivers and other performance-critical work.

Use cooperative threads to implement mutual exclusion without the need for a kernel object, such as a mutex.

Use preemptive threads to give priority to time-sensitive processing over less time-sensitive processing.
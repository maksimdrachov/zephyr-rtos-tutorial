## Commands

A couple of commands we haven't discussed in threads:

- k_yield: Yield the current thread. This routine causes the current thread to yield execution to another thread of the same or higher priority. If there are no other ready threads of the same or higher priority, the routine returns immediately.
- k_wakeup: Wake up a sleeping thread. This routine prematurely wakes up thread from sleeping.
- k_current_get: Get thread ID of the current thread. 
- k_sched_lock: A preemptible thread that does not wish to be preempted while performing a critical operation can instruct the scheduler to temporarily treat it as a cooperative thread by calling k_sched_lock(). This prevents other threads from interfering while the critical operation is being performed.
- k_sched_unlock: Once the critical operation is complete the preemptible thread must call k_sched_unlock() to restore its normal, preemptible status.
- k_busy_wait: A thread can call k_busy_wait() to perform a busy wait that delays its processing for a specified time period without relinquishing the CPU to another ready thread.
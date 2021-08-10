## Time slicing

**Cooperative Time Slicing**
Once a cooperative thread becomes the current thread, it remains the current thread
- until it performs an action that makes it unready
  
Consequently, if a cooperative thread performs lengthy computations, it may cause an unacceptable delay in the scheduling of other threads, including those of higher priority and equal priority.

![cooperative_image](/images/cooperative1.png)

To overcome such problems, a cooperative thread can volutarily relinquish the CPU from time to time to permit other threads to execute. A thread can relinquish the CPU in two ways:

- Calling k_yield() puts the thread at the back of the schedulers's prioritized list of ready threads, and then invokes the scheduler. All ready threads whose priority is higher or equal to that of the yielding thread are then allowed to execute before the yielding thread is rescheduled. If no such ready threads exist, the scheduler immediately reschedules the yielding thread without context switching. 
- Calling k_sleep() makes the thread unready for a specified period of time. Ready threads of all priorities are then allowed to execute; however there is no guarantee that threads whose priority is lower than that of the sleeping thread will actually be scheduled before the sleeping thread becomes ready once again. 

**Preemptive Time Slicing**
Once a preemptive thread becomes the current thread, it remains the current thread until
- a higher priority thread becomes ready
- or until the thread performs an action that makes it unready
  
Consequently, if a preemptive thread performs lengthy computations, it may cause an unacceptable delay in the scheduling of other threads, including those of equal priority.

![preemptive](/images/preemptive.png)

To overcome such problems, a preemptive thread can perform cooperative time slicing, or the scheduler's time slicing capability can be used to allow other threads of the same priority to execute.

![timeslicing](/images/timeslicing.png)

The scheduler divide time into a series of time slices, where slices are measured in system clock ticks. The time slice size is configurable, but this size can be changed while the application is running.

At the end of every time slice, the scheduler checks to see if the current thread is preemptible and, if so, implicity invokes k_yield() on behalf of the thread. This gives other ready threads of the same priority the opportunity to execute before the current thread is scheduled again. If no threads of equal priority are ready, the current thread remains the current thread.

A preemptible thread that does not wish to be preempted while performing a critical operation can instruct the scheduler to temporarily treat is as a cooperative thread by calling k_sched_lock(). This prevents other threads from interfering while the critical operation is being performed. 

Once the critical operation is complete the preemptible thread must call k_sched_unlock() to restore its normal, preemptible status.
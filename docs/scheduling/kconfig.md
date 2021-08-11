## Scheduling algorithm
The kernel's scheduler selects the next thread based on priority, if multiple threads have the same priority, the scheduler chooses the one that has been waiting the longest.

Execution of ISRs takes precedence over thread execution, unless interrupts are masked.

Several choices for the ready queue implementation, offering different choices between code size, constant factor runtime overhead and performance scaling when many threads are added. 
- Simple linked-list ready queue (CONFIG_SCHED_DUMB)
  
  The scheduler ready queue will be implemented as a simple unordered list, with very fast constant time performance for single threads and very low code size. This implementation should be selected on systems with constrained code size that will never see more than a small number (3, maybe) of runnable threads in the queue at any given time. On most platforms this results in a savings of ~2k of code size.

- Red/black tree ready queue (CONFIG_SCHED_SCALABLE)
  
  The scheduler ready queue will be implemented as a red/black tree. This has rather slower constant-time insertion and removal overhead, and on most platforms requires an additional ~2kb of code. The resulting behaviour will scale cleanly and quickly into many thousands of threads. Use this for applications needing many concurrent runnable threads (>20 or so). Most applications won't need this.

- Traditional multi-queue ready queue (CONFIG_SCHED_MULTIQ) 
  The scheduler will be implemented as the classic array of lists, one per priority (max 32 priorities). It incurs only a tine code size overhead vs the "dumb" scheduler and runs in O(1) time in almost all circumstances with very low constant factor. But it requires a fairly large RAM budget to store those list heads. Typical applications with small number of threads probably want the DUMB scheduler. 
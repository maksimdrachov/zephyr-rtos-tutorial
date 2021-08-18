Scheduler configuration
| CONFIG | Description |
| --- | --- |
| CONFIG_SCHED_DUMB | The scheduler ready queue will be implemented as a simple unordered list, with very fast constant time performance for single threads and very low code size. This implementation should be selected on systems with constrained code size that will never see more than a small number (3, maybe) of runnable threads in the queue at any given time. On most platforms (that are not otherwise using the red/black tree) this results in a savings of ~2k of code size. |
| CONFIG_SCHED_SCALABLE | The scheduler ready queue will be implemented as a red/black tree. This has rather slower constant-time insertion and removal overhead, and on most platforms (that are not otherwise using the red/black tree somewhere) requires an extra ~2kb of code. The resulting behavior will scale cleanly and quickly into the many thousands of threads. Use this for applications needing many concurrent runnable threads (> 20 or so). Most applications won’t need this ready queue implementation. |
| CONFIG_SCHED_MULTIQ | When selected, the scheduler ready queue will be implemented as the classic/textbook array of lists, one per priority (max 32 priorities). This corresponds to the scheduler algorithm used in Zephyr versions prior to 1.12. It incurs only a tiny code size overhead vs. the “dumb” scheduler and runs in O(1) time in almost all circumstances with very low constant factor. But it requires a fairly large RAM budget to store those list heads, and the limited features make it incompatible with features like deadline scheduling that need to sort threads more finely, and SMP affinity which need to traverse the list of threads. Typical applications with small numbers of runnable threads probably want the DUMB scheduler. |
| CONFIG_WAITQ_SCALABLE | When selected, the wait_q will be implemented with a balanced tree. Choose this if you expect to have many threads waiting on individual primitives. There is a ~2kb code size increase over CONFIG_WAITQ_DUMB (which may be shared with CONFIG_SCHED_SCALABLE) if the red/black tree is not used elsewhere in the application, and pend/unpend operations on “small” queues will be somewhat slower (though this is not generally a performance path). |
| CONFIG_WAITQ_DUMB | When selected, the wait_q will be implemented with a doubly-linked list. Choose this if you expect to have only a few threads blocked on any single IPC primitive. |

Thread priorities configuration
| CONFIG | Description |
| --- | --- |
| CONFIG_NUM_COOP_PRIORITIES | Number of coop priorities |
| CONFIG_NUM_PREEMPT_PRIORITIES | Number of preempt priorities |

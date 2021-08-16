An ISR has the following key properties:
- An interrupt request (IRQ) signal that triggers the ISR.
- A priority level associated with the IRQ.
- An interrupt handler function that is invoked to handle the interrupt.
- An argument value that is passed to that function.

The kernel supports interrupt nesting. This allows an ISR to be preempted in mid-execution if a higher priority interrupt is signaled. The lower priority ISR resumes execution once the higher priority ISR has completed its processing.

An ISR’s interrupt handler function executes in the kernel’s interrupt context. This context has its own dedicated stack area (or, on some architectures, stack areas). The size of the interrupt context stack must be capable of handling the execution of multiple concurrent ISRs if interrupt nesting support is enabled.

Preventing interruptions
A thread may temporarily prevent all IRQ handling in the system using an IRQ lock. This lock can be applied even when it is already in effect, so routines can use it without having to know if it is already in effect. The thread must unlock its IRQ lock the same number of times it was locked before interrupts can be once again processed by the kernel while the thread is running.

Offloading ISR work
An ISR should execute quickly to ensure predictable system operation. If time consuming processing is required the ISR should offload some or all processing to a thread, thereby restoring the kernel’s ability to respond to other interrupts.

The kernel supports several mechanisms for offloading interrupt-related processing to a thread.
- An ISR can signal a helper thread to do interrupt-related processing using a kernel object, such as a fifo, lifo, or semaphore.
- An ISR can signal an alert which causes the system workqueue thread to execute an associated alert handler function. (See Alerts.)
- An ISR can instruct the system workqueue thread to execute a work item. (See TBD.)

When an ISR offloads work to a thread, there is typically a single context switch to that thread when the ISR completes, allowing interrupt-related processing to continue almost immediately. However, depending on the priority of the thread handling the offload, it is possible that the currently executing cooperative thread or other higher-priority threads may execute before the thread handling the offload is scheduled.

Implementation

Defining a regular ISR

Defining a 'direct' ISR

Implementation details

Vector Table

SW ISR Table


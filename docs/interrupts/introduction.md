*What is an interrupt?*

An interrupt service routine (ISR) is a function that executes asynchronously in response to a hardware or software interrupt. An ISR normally preempts the execution of the current thread, allowing the response to occur with very low overhead. Thread execution resumes only once all ISR work has been completed.

An ISR has the following key properties:
- An interrupt request (IRQ) signal that triggers the ISR
- A priority level associated with the IRQ
- An interrupt handler function that is invoked to handle the interrupt
- An argument value that is passed to that function

An interrupt descriptor table (IDT) or a vector table is used to associate a given interrupt source with a given ISR. Only a single ISR can be associated with a specific IRQ at any given time.

Multiple ISRs can utilize the same function to process interrupts, allowing a single function to service a device that generates multiple types of interrupts or to service multiple devices (usually of the same type). The argument value passed to an ISR's function allows the function to determine which interrupt has been signaled. 

The kernel provides a default ISR for all unused IDT entries. This ISR generates a fatal system error if an unexpected interrupt is signaled.

The kernel supports interrupt nesting. This allows an ISR to be preempted in mid-execution if a higher priority interrupt is signaled. The lower priority ISR resumes execution once the higher priority ISR has completed its processing.

An ISR's interrupt handler function executes in the kernel's interrupt context. This context has its own dedicated stack area. The size of the interrupt context stack must be capable of handling the execution of multiple concurrent ISRs if interrupt nesting support is enabled. 

Important: Many kernel APIs can be used only by threads, and not by ISRs. In cases where a routine may be invoked by both threads and ISRs the kernel provides the k_is_in_isr() function to allow the routine to alter its behavior depending on whether it is executing as part of a thread or as part of an ISR.

*How to define a regular interrupt?*

An ISR is defined at run-time by calling IRQ_CONNECT. It must then be enabled by calling irq_enable().

Important: IRQ_CONNECT() is not a C function and does some inline assembly magic behind the scenes. All its arguments must be known at build time. Drivers that have multiple instances may need to define per-instance config functions to configure each instance of the interrupt.

The following code defines and enables an ISR.

```c
#define MY_DEV_IRQ  24       /* device uses IRQ 24 */
#define MY_DEV_PRIO  2       /* device uses interrupt priority 2 */
/* argument passed to my_isr(), in this case a pointer to the device */
#define MY_ISR_ARG  DEVICE_GET(my_device)
#define MY_IRQ_FLAGS 0       /* IRQ flags. Unused on non-x86 */

void my_isr(void *arg)
{
   ... /* ISR code */
}

void my_isr_installer(void)
{
   ...
   IRQ_CONNECT(MY_DEV_IRQ, MY_DEV_PRIO, my_isr, MY_ISR_ARG, MY_IRQ_FLAGS);
   irq_enable(MY_DEV_IRQ);
   ...
}
```

*How to define a 'direct' ISR?*

Regular Zephyr interrupts introduce some overhead which may be unacceptable for some low-latency use-cases. Specifically:
- The argument to the ISR is retrieved and passed to the ISR
- If power management is enabled and the system was idle, all the hardware will be resumed from low-power state before the ISR is executed, which cn be very time-consuming
- Although some architectures will do this in hardware, other architectures need to switch to the interrupt stack in code
- After the interrupt is serviced, the OS then performs some logic to potentially make a scheduling decision

Zephyr supports so-called 'direct' interrupts, which are installed via IRQ_DIRECT_CONNECT. These direct interrupts have some special implementation requirements and a reduced feature set; see the definition of IRQ_DIRECT_CONNECT for details.

The following code demonstrates a direct ISR:
```c
#define MY_DEV_IRQ  24       /* device uses IRQ 24 */
#define MY_DEV_PRIO  2       /* device uses interrupt priority 2 */
/* argument passed to my_isr(), in this case a pointer to the device */
#define MY_IRQ_FLAGS 0       /* IRQ flags. Unused on non-x86 */

ISR_DIRECT_DECLARE(my_isr)
{
   do_stuff();
   ISR_DIRECT_PM(); /* PM done after servicing interrupt for best latency */
   return 1; /* We should check if scheduling decision should be made */
}

void my_isr_installer(void)
{
   ...
   IRQ_DIRECT_CONNECT(MY_DEV_IRQ, MY_DEV_PRIO, my_isr, MY_IRQ_FLAGS);
   irq_enable(MY_DEV_IRQ);
   ...
}
```

*How to disable interrupts?*

In certain situations it may be necessary for the current thread to prevent ISRs from executing while it is performing time-sensitive or critical section operations.

A thread may temporarily prevent all IRQ handling in the system using an IRQ lock. This lock can be applied even when it is already in effect, so routines can use it without having to know if it is already in effect. The thread must unlock its IRQ lock the same number of times it was locked before interrupts can be once again processed by the kernel while the thread is running.

Important: The IRQ lock is thread-specific. if thread A locks out interrupts then performs an operation that allows thread B to run (e.g. giving a semaphore or sleeping for N milliseconds), the thread's IRQ lock no longer applies once thread A is swapped out. This means that interrupts can be processed while thread B is running unless thread B has also locked out interrupts using its own IRQ lock. 

When thread A eventually becomes the current thread once again, the kernel re-establishes thread A's IRQ lock. This ensures thread A won't be interrupted until it has explicitly unlocked its IRQ lock.

Alternatively, a thread may temporarily disable a specific IRQ. The IRQ must be subsequently enabled to permit the ISR to execute.

Important: Disabling an IRQ prevent all threads in the system from being preempted by the associated ISR, not just the thread that disabled the IRQ.

*When to use an interrupt?*

Use a regular or direct ISR to perform interrupt processing that requires a very rapid response, and can be done quickly without blocking.

Note: Interrupt processing that is time consuming, or involves blocking, should be handed off to a thread. See [Offloading ISR Work](https://docs.zephyrproject.org/1.9.0/kernel/other/interrupts.html#offloading-isr-work) for a description of various techniques that can be used in an application.


# Interrupts

## 1. Introduction
An **interrupt service routine** (ISR) is a function that executes asynchronously in response to a hardware or software interrupt. An ISR normally preempts the execution of the current thread, allowing the response to occur with very low delay. Thread execution resumes only once all ISR work has been completed. 

- **Interrupt request signal** (IRQ): triggers the ISR
- **Priority level**: associated with the IRQ
- **Interrupt hadler function**: invoked to handle the interrupt
- **Argument value**: passed to the handler function

The kernel supports **interrupt nesting**. This allows an ISR to be preempted in mid-execution if a higher interrupt is signaled. The lower priority ISR resumes execution once the higher priority ISR has completed processing. (See: [CONFIG_NESTED_INTERRUPTS](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_NESTED_INTERRUPTS.html))

An ISR's interrupt handler function executes in the kernel's interrupt context. This context has its own dedicated stack area. The size of the interrupt context stack must be capable of handling the execution of multiple concurrent ISRs if interrupt nesting support is enabled. (See: [CONFIG_ISR_STACK_SIZE](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_ISR_STACK_SIZE.html#std-kconfig-CONFIG_ISR_STACK_SIZE))

Many kernel APIs can be used only by threads, and not by ISRs. In cases where a routine may be invoked by both threads and ISRs the kernel provides the `k_is_in_isr()` function to allow the routine to alter its behaviour depending on whether it is executing as part of a thread or as part of an ISR.

## 2. Multi-level Interrupt handling

## 3. Preventing Interruptions
In certain situations it may be necessary for the current thread to prevent ISRs from executing while it is performing time-sensitive or critical section operations.

A thread may temporarily prevent all IRQ handling in the system using an IRQ lock. 

**Zero Latency Interrupts**

Preventing interruptions by applying an IRQ lock may increase the observed interrupt latency. A high interrupt latency, however, may not be acceptable for certain low-latency use-cases.

The kernel addresses such use-cases by allowing interrupts with critical latency constraints to execute at a priority level that cannot be blocked by interrupt locking. These interrupts are defined as zero-latency interrupts. The support for zero-latency interrupts requires CONFIG_ZERO_LATENCY_IRQS to be enabled. In addition to that, the flag IRQ_ZERO_LATENCY must be passed to IRQ_CONNECT or IRQ_DIRECT_CONNECT macros to configure the particular interrupt with zero latency.

## 4. Offloading ISR Work

## 5. Implementation

### 5.1. Defining a regular ISR

An ISR is defined at runtime by calling IRQ_CONNECT. It must then be enabled by calling irq_enable().

The following code defines and enables an ISR.

```c
#define MY_DEV_IRQ  24       /* device uses IRQ 24 */
#define MY_DEV_PRIO  2       /* device uses interrupt priority 2 */
/* argument passed to my_isr(), in this case a pointer to the device */
#define MY_ISR_ARG  DEVICE_GET(my_device)
#define MY_IRQ_FLAGS 0       /* IRQ flags */

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

### 5.2. Defining a direct ISR

The following code demonstrates a direct ISR:
```c
#define MY_DEV_IRQ  24       /* device uses IRQ 24 */
#define MY_DEV_PRIO  2       /* device uses interrupt priority 2 */
/* argument passed to my_isr(), in this case a pointer to the device */
#define MY_IRQ_FLAGS 0       /* IRQ flags */

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

### 5.3. Implementation Details

**Vector Table**

**SW ISR Table**

## 6. Suggested Uses

Use a regular or direct ISR to perform interrupt processing that requires a very rapid response, and can be done quickly without blocking. 

## 7. Examples

**ISR Button**



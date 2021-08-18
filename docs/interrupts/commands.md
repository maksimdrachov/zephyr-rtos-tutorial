The following interrupt-related APIs are provided by irq.h:

| Command | Description |
| --- | --- |
| IRQ_CONNECT | Initialize an interrupt handler. This routine initializes an interrupt handler for an IRQ. The IRQ must be subsequently enabled before the interrupt handler begins servicing interrupts. |
| IRQ_DIRECT_CONNECT | Initialize a ‘direct’ interrupt handler. This routine initializes an interrupt handler for an IRQ. The IRQ must be subsequently enabled via irq_enable() before the interrupt handler begins servicing interrupts. |
| ISR_DIRECT_HEADER |     Common tasks before executing the body of an ISR. This macro must be at the beginning of all direct interrupts and performs minimal architecture-specific tasks before the ISR itself can run. It takes no arguments and has no return value.|
| ISR_DIRECT_FOOTER | Common tasks before exiting the body of an ISR. This macro must be at the end of all direct interrupts and performs minimal architecture-specific tasks like EOI. It has no return value. |
| ISR_DIRECT_PM | Perform power management idle exit logic. |
| ISR_DIRECT_DECLARE | Helper macro to declare a direct interrupt service routine.  |
| irq_lock() | Lock interrupts. This routine disables all interrupts on the CPU.  |
| irq_unlock() | Unlock interrupts.  |
| irq_enable() | Enable an IRQ. |
| irq_disable() | Disable an IRQ. |
| irq_is_enabled() | Get IRQ enable state. |


The following interrupt-related APIs are provided by kernel.h:
| Command | Description |
| --- | --- |
| k_is_in_isr() | Determine if code is running at interrupt level. |
| k_is_preempt_thread() | Determine if code is running in a preemptible thread. |


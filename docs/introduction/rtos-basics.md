## RTOS basics
*Why do I need an RTOS?*

*How does an RTOS work?*

*What are some key concept in RTOS?*

*Why Zephyr?*


Before going any further it might be useful to quickly go over some basic RTOS concepts.

First: what is an RTOS? It is an operating system that is intended to serve real-time applications. Typical time requirement are below 0.01s. Two types of systems can be identified:
- Event-driven: switch tasks based on their priorities
- Time-sharing: switch the task based on clock interrupts

![rtos_basic_execution](https://maksimdrachov.github.io/zephyr-rtos-tutorial/images/introduction/rtos_basic_execution.gif)

Some key concepts:
- **Kernel**: the core component within an operating system. Takes care of scheduling the tasks in such a way that they *appear* to be happening simultanously.
- **Task**: Each executing program is a task (or thread) under control of the operating system.
- **Scheduler**: part of the kernel responsible for deciding which task should be executing at any particular time. The scheduling policy decides which task to execute at any point in time.
- **Context**: as a task executes it uses the registers and memory. The processor registers, stack, etc compromise the task execution context. On switching to a task the RTOS is responsible to set the context back to the way it was at the moment it got pre-empted the previous time. The process of saving the context of a task being suspended and restoring the context of a task being resumed is called context switching.
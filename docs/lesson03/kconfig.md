## Kconfig

- Use K_KERNEL_STACK macros if:
  - thread will never run in user mode
  - stack is being used for special contexts like handling interrupts
- Use K_THREAD_STACK macros if:
  - stack will need to host user threads


Kernel supports thread options that allow a thread to receive special treatment under specific circumstances.

- K_ESSENTIAL: tags the thread as an essential thread. Instructs the kernel to treat the termination or aborting of the thread as a fatal system error.
- K_FP_REGS: indicates that the thread uses the CPU's floating point registers. Instructs the kernel to take additional steps to save and restore the contents of these registers when scheduling the thread. 
- K_USER: if CONFIG_USERSPACE is enabled, this thread will be created in user mode and will have reduced privileges.
- K_INHERIT_PERMS: if CONFIG_USERSPACE is enabled, this thread will inherit all kernel object permissions that the parent thread had.
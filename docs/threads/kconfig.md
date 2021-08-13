## Kconfig
Threads are always included in the system configuration, therefore no *additional* configs need to be set. 

However *optionally* the following configuration options can be set:

Kconfig | Description  
---------|----------
[CONFIG_MAIN_THREAD_PRIORITY](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_MAIN_THREAD_PRIORITY.html) | Priority of initialization/main thread
[CONFIG_MAIN_STACK_SIZE](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_MAIN_STACK_SIZE.html) | Size of stack for initialization and main thread
[CONFIG_IDLE_STACK_SIZE](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_IDLE_STACK_SIZE.html) | Size of stack for idle thread
[CONFIG_THREAD_CUSTOM_DATA](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_THREAD_CUSTOM_DATA.html) | This option allows each thread to store 32 bits of custom data, which can be accessed using the k_thread_custom_data_xxx() APIs.
[CONFIG_NUM_COOP_PRIORITIES](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_NUM_COOP_PRIORITIES.html) | Number of cooperative priorities configured in the system
[CONFIG_NUM_PREEMPT_PRIORITIES](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_NUM_PREEMPT_PRIORITIES.html) | Number of preemptible priorities available in the system
[CONFIG_TIMESLICING](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_TIMESLICING.html) | This option enables time slicing between preemptible threads of equal priority.
[CONFIG_TIMESLICE_SIZE](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_TIMESLICE_SIZE.html) | This option specifies the maximum amount of time a thread can execute before other threads of equal priority are given an opportunity to run. A time slice size of zero means "no limit" (i.e. an infinitely large time slice).
[CONFIG_TIMESLICE_PRIORITY](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_TIMESLICE_PRIORITY.html) | This option specifies the thread priority level at which time slicing takes effect; threads having a higher priority than this ceiling are not subject to time slicing.
[CONFIG_USERSPACE](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_USERSPACE.html) |When enabled, threads may be created or dropped down to user mode, which has significantly restricted permissions and must interact with the kernel via system calls.

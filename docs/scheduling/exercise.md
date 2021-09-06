## Exercises
**Cooperative Time Slicing**
Implement cooperative time slicing that puts out the serial (using `printk()`)

```
thread_1: thread started
thread_1: thread_2 started
thread_1: thread loop 1
thread_1: thread loop 2
thread_1: thread loop 3
thread_2: thread started
thread_2: thread loop 1
thread_2: thread loop 2
thread_2: thread loop 3
```

*figure showing the thread priority and the fact that thread_1 doesn't yield even though lower priority*

![serial-coop-time-slicing](/images/scheduling/serial-coop-time-slicing.png)


**Preemptive Time Slicing**
Implement Preemptive time slicing that puts out the serial (using `printk()`)

```
thread_1: thread started
thread_1: thread_2 started
thread_2: thread started
thread_2: thread_3 started
thread_3: thread started
thread_3: thread loop 1
thread_3: thread loop 2
thread_3: thread loop 3
thread_2: thread loop 1
thread_2: thread loop 2
thread_2: thread loop 3
thread_1: thread loop 1
thread_1: thread loop 2
thread_1: thread loop 3
```

*figure showing the increase in thread priority and preemption and completion of each thread*

![serial-preemptive-time-slicing](/images/scheduling/serial-preemptive-time-slicing.png)

**Time Slicing (with 3 threads)**
Implement time slicing with three threads (of equal priority)

```
thread_1: thread started
thread_2: thread started
thread_3: thread started
thread_1: thread loop
thread_2: thread loop
thread_3: thread loop
thread_1: thread loop
thread_2: thread loop
thread_3: thread loop
...
```

*figure showing the equal priority threads preempting each other*

![serial-time-slicing](/images/scheduling/serial-time-slicing.png)

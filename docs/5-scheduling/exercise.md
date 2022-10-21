---
layout: post
title: '5.4 Exercise'
parent: '5. Scheduling'
---

# Exercises

## Cooperative Time Slicing

Implement cooperative time slicing that puts out the following serial output (using `printk()`)

*figure showing that thread_1, even though lower priority, doesn't yield to thread_2 (until finished)*

![serial-coop-time-slicing](/images/scheduling/serial-coop-time-slicing.png)


## Preemptive Time Slicing

Implement Preemptive time slicing that puts out the serial (using `printk()`)

*figure showing the increase in thread priority and preemption and completion of each thread*

![serial-preemptive-time-slicing](/images/scheduling/serial-preemptive-time-slicing.png)

## Time Slicing (with 3 threads)

Implement time slicing with three threads (of equal priority)

*figure showing the equal priority threads preempting each other*

![serial-time-slicing](/images/scheduling/serial-time-slicing.png)

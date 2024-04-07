---
layout: post
title: '3.4 Exercises'
parent: '3. Threads'
---

# Exercises

For solving the exercises I recommend you create your own folder inside `zephyr-rtos-tutorial` which contains the following filetree.

```
.
└── my-exercises
    ├── threads
    │   ├── thread-start
    │   ├── thread-start-define
    │   ├── thread-abort
    │   ├── thread-sleep
    │   ├── thread-suspend
    │   └── thread-join
    ├── gpio
    ├── scheduling
    ├── debugging
    ├── interrupts
    ├── timers
    ├── mutexes
    ├── semaphores
    ├── logging
    └── networking
```



## thread creation: main

- Use `k_thread_create()` to create a thread
- Implement the following

![thread-start]({{ site.baseurl }}/svg-images/threads/thread-start.png)

- Output the following serial using `printk()`

![thread-start]({{ site.baseurl }}/images/threads/thread-start.png)

solution: `exercises/threads/thread-start`

## thread creation: define

- Same as previous, but this time using `K_THREAD_DEFINE` to create thread

solution: `exercises/threads/thread-start-define`

## thread abort

- Implement the following

![thread-abort]({{ site.baseurl }}/svg-images/threads/thread-abort.png)

- Output the following serial using `printk()`

![thread-abort]({{ site.baseurl }}/images/threads/thread-abort.png)

solution: `exercises/threads/thread-abort`

## thread sleep

- Implement the following

![thread-sleep]({{ site.baseurl }}/svg-images/threads/thread-sleep.png)

- Output the following serial using `printk()`

![thread-sleep]({{ site.baseurl }}/images/threads/thread-sleep.png)

solution: `exercises/threads/thread-sleep`

## thread suspend

- Implement the following

![thread-sleep]({{ site.baseurl }}/svg-images/threads/thread-suspend.png)

- Output the following serial using `printk()`

![thread-sleep]({{ site.baseurl }}/images/threads/thread-suspend.png)

solution: `exercises/threads/thread-suspend`

## thread join

- Implement the following

![thread-join]({{ site.baseurl }}/svg-images/threads/thread-join.png)

- Output the following serial using `printk()`

![thread-join]({{ site.baseurl }}/images/threads/thread-join.png)

solution: `exercises/threads/thread-join`
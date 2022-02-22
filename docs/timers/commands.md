---
layout: post
title: '8.2 Commands'
parent: 'Lesson 8: Timers'
---

| Command | Description |
| --- | --- |
| k_timer_init | Initialize a timer. This routine initializes a timer, prior to its first use. |
| k_timer_start | Start a timer. This routine starts a timer, and resets its status to zero. The timer begins counting down using the specified duration and period values. |
| k_timer_stop | Stop a timer. This routine stops a running timer prematurely. The timer’s stop function, if one exists, is invoked by the caller. |
| k_timer_status_get | Read timer status. This routine reads the timer’s status, which indicates the number of times it has expired since its status was last read. |
| k_timer_status_sync | Synchronize thread to timer expiration. This routine blocks the calling thread until the timer’s status is non-zero (indicating that it has expired at least once since it was last examined) or the timer is stopped. If the timer status is already non-zero, or the timer is already stopped, the caller continues without waiting. |
| k_timer_expires_ticks | Get next expiration time of a timer, in system ticks. |
| k_timer_remaining_ticks | Get time remaining before a timer next expires, in system ticks.  |
| k_timer_remaining_get | Get time remaining before a timer next expires. |

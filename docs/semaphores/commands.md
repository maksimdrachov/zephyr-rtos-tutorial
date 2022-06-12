---
layout: post
title: '10.2 Commands'
parent: 'Lesson 10: Semaphores'
---

| Command | Description |
| --- | --- |
| K_SEM_MAX_LIMIT |     Maximum limit value allowed for a semaphore. This is intended for use when a semaphore does not have an explicit maximum limit, and instead is just used for counting purposes. |
| K_SEM_DEFINE | Statically define and initialize a semaphore.  |
| k_sem_init | Initialize a semaphore.  |
| k_sem_take | Take a semaphore.  |
| k_sem_give | Give a semaphore.  |
| k_sem_reset | Resets a semaphore’s count to zero. This routine sets the count of sem to zero. Any outstanding semaphore takes will be aborted with -EAGAIN. |
| k_sem_count_get | Get a semaphore’s count. This routine returns the current count of sem. |
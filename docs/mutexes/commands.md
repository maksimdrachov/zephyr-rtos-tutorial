| Command | Description |
| --- | --- |
| K_MUTEX_DEFINE | Statically define and initialize a mutex. |
| k_mutex_init | Initialize a mutex.  |
| k_mutex_lock | Lock a mutex. This routine locks mutex. If the mutex is locked by another thread, the calling thread waits until the mutex becomes available or until a timeout occurs. |
| k_mutex_unlock | Unlock a mutex. This routine unlocks mutex. The mutex must already be locked by the calling thread. |

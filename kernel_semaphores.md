# Semaphores

## 1. Introduction
A semaphore is a kernel object that implements a traditional counting semaphore.

Some key properties:
- Count: indicates the number of times the semaphore can be taken. A count of zero indicates that the semaphore is unavailable.
- Limit: indicates the maximum value the semaphore's count can reach.

A semaphore must be initialized before it can be used. Its count must be set to a non-negative value that is less than or equal to its limit. 

A semaphore can be taken by a thread or an ISR. This decreases the count of the semaphore. If the count is at zero, the semaphore is unavailable and thus cannot be taken. The thread can then choose to wait for it. Any number of threads can be waiting on an unavailable semaphore. Once the semaphore becomes available, the highest priority thread that has waited the longest can take it. 

Once a thread is finished using the semaphore it gives it back. This increases the semaphore count. 

The kernel allows an ISR to take a semaphore, however the ISR must not attempt to wait if the semaphore is unavailable. 

## 2. Implementation
### 2.1. Defining a Semaphore

### 2.2. Taking a Semaphore

### 2.3. Giving a Semaphore

## 3. Suggested Uses

Use a semaphore to control access to a set of resources by multiple threads. 

Use a semaphore to synchronize processing between a producing and consuming threads or ISRs. 

## 4. Examples


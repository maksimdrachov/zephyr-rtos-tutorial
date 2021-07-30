# Mutexes

## 1. Introduction

A mutex is a kernel object that implements a traditional reentrant mutex. A mutex allows multiple threads to safely share an associated hardware or software resource by ensuring mutually exclusive access to the resource.

Some key properties:
- Lock count: 
- Owning thread: identifies the thread that has locked the mutex, when it is locked.

A mutex be initialized before it can be used. This sets its lock count to zero.

A thread that needs to use a shared resource must first gain exclusive rights to access it by locking the associated mutex. If the mutex is already locked by another thread, the requesting thread may choose to wait for the mutex to be unlocked. 

After locking a mutex, the thread may safely use the associated resource for as long as needed; however, it is considered good practise to hold the lock for as short a time as possible to avoid negatively impacting other threads that want to use the resource. When the thread no longer needs the resource it must unlock the mutex to allow other threads to use the resource. 

Any number of threads may wait on a locked mutex simultanously. When the mutex becomes unlocked it is then locked by the highest-priority thread that has waited the longest. 

Mutex objects are not designed for use by ISRs. 

## 2. Reentrant Locking

## 3. Priority Inheritance

The [CONFIG_PRIORITY_CEILING](https://docs.zephyrproject.org/latest/reference/kconfig/CONFIG_PRIORITY_CEILING.html#std-kconfig-CONFIG_PRIORITY_CEILING) configuration option limits how high the kernel can raise a thread's priority due to priority inheritance. The default value is 0 and permits unlimited elevation. 

## 4. Implementation

### 4.1. Defining a Mutex

### 4.2. Locking a Mutex

### 4.3. Unlocking a Mutex

## 5. Suggested Uses

Use a mutex to provide exclusive access to a resource, such as a physical device.

## 6. Examples


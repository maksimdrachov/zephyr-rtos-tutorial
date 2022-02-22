---
layout: post
title: '12.1 Introduction'
parent: 'Lesson 12: Networking'
---

## Introduction
If you have no experience with network programming, I'd recommend first working through [this](https://www.youtube.com/playlist?list=PLfIJKC1ud8ggZKVtytWAlOS63vifF5iJC) course. The Lwip stack is very similar to the way the Zephyr Network stack works.

## BSD Sockets

Zephyr offers an implementation of a subset of the BSD Sockets API. This API allows to port existing simple networking applications to Zephyr.

Here are the key requirements and concepts which governed BSD Sockets compatible API implementation for Zephyr.

- Has minimal overhead, similar to the requirement for other Zephyr subsystems.
- Is namespaced by default, to avoid conflicts with well-known names like `close()`, which may be part of libc or other POSIX compatibility libraries. If enabled by `CONFIG_NET_SOCKETS_POSIX_NAMES`, it will also expose native POSIX names. 

BSD Sockets compatible API is enabled using CONFIG_NET_SOCKETS config option and implements the following operations:
- socket()
- close()
- recv()
- recvfrom()
- send()
- sendto()
- connect()
- bind()
- listen()
- accept()
- fcntl()
- getsockopt()
- setsockopt()
- poll()
- select()
- getaddrinfo()
- getnameinfo()

Based on the namespacing requirements above, these operations are by default exposed as functions with `zsock_` prefix, e.g. `zsock_socket()`,... If the config option CONFIG_NET_SOCKETS_POSIX_NAMES is defined, all the functions will be also exposed as aliases without the prefix. This includes the functions like `close()` and `fcntl()` (which may conflict with functions in libc or other libraries, for example, with the filesystem libraries).

Another entailment of the design requirements above is that the Zephyr API aggressively employs the short-read/short-write property of the POSIX API whenever possible (to minimize complexity and overheads). POSIX allows for calls like `recv()` and `send()` to actually process (receive or send) less data than requested by the user (on SOCK_STREAM type sockets). For example, a call recv(sock, 1000, 0) may return 100, meaning that only 100 bytes were read (short read), and the application needs to retry call(s) to receive the remaining 900 bytes.

The BSD Sockets API uses file descriptors to represent sockets. File descriptors are small integers, consecutively assigned from zero, shared among sockets, files, special devices (liek stdin/stdout), etc. Internally, there is a table mapping file descriptors to internal object pointers. The file descriptor table is used by the BSD Sockets API even if the rest of the POSIX subsystem (filesystem, stdin/stdout) is not enabled. 


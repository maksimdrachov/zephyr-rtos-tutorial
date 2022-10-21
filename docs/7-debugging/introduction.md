---
layout: post
title: '7.1 Introduction'
parent: '7. Debugging'
---

# Introduction

## What are some common debugging techniques and when to use them?

The three most common debugging techniques we'll be discussing here are:
- thread aware debugging (debug probe)
- thread analysis
- core dump

## How does thread aware debugging work?

To enable thread-aware debugging you'll need to add the line shown below to `zephyr/boards/arm/nucleo_f756zg/support/openocd.cfg`

```
# Enable Zephyr thread awareness
$_TARGETNAME configure -rtos Zephyr
```

![openocd-threads-support](/images/debugging/openocd-threads-support.png)

A debug probe is special hardware which allows you to control execution of a Zephyr application running on a seperate board. Debug probes usually allow reading and writing registers and memory, and support breakpoint debugging of the Zephyr application on your host workstation using tools like GDB. 

ST-LINK is a serial and debug adapter built into all Nucleo and Discovery boards. It provides a bridge between your computer (or other SUB host) and the embedded target processor, which can be used for debugging, flash programming, and serial communication, all over a simple USB cable.

It is compatible with the following host debug tools:
- OpenOCD Debug Host Tools
- J-Link Debug Host Tools

In this tutorial we'll be using OpenOCD.

## How to use OpenOCD?

OpenOCD is available by default on ST-Link and configured as the default flash and debug tool. Flash and debug can be done as follows:
```
west build -b nucleo_f756zg
west flash
```
```
west build -b nucleo_f756zg
west debug
```

## How does thread analysis work?

The thread analyzer module enables all the Zephyr options required to track the thread information, e.g. thread stack size usage and other runtime thread statistics.

The analysis is performed on demand when the application calls thread_analyzer_run() or thread_analyzer_print().

The output is put on the serial connection.

## How does core dump work?

The core dump module enables dumping the CPU registers and memory content for offline debugging. This module is called when a fatal error is encountered, and the data is printed or stored to which backends are enabled. This core dump data can be fed into a custom made GDB server as a remote target for GDB. CPU registers, memory content and stack can be examined in the debugger.

This usually involves the following steps:
1) Get the core dump log from the device depending on enabled backends.
2) Convert the core dump log into a binary format that can be parsed by the GDB server. For example, scripts/coredump/coredump_serial_log_parser.py can be used to convert the serial console log into a binary file.
3) Start the custom GDB server using the script scripts/coredump/coredump_gdbserver.py with the core dump binary log file, and the Zephyr ELF file as parameters.
4) Start the debugger corresponding to the target architecture.

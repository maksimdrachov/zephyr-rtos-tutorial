## Introduction

OpenOCD thread aware debugging
![openocd-threads-support](/images/debugging/openocd-threads-support.png)

### OpenOCD

### Thread analyzer

### Core dump
The core dump module enables dumping the CPU registers and memory content for offline debugging. This module is called when fatal error is encountered, and the data is printed or stored according to which backends are enabled.

Usage

When the core dump module is enabled, during fatal error, CPU registers and memory content are being printed or stored according to which backends are enabled. This core dump data can fed into a custom made GDB server as a remote target for GDB (and other GDB compatible debuggers). CPU registers, memory content and stack can be examined in the debugger.

This usually involves the following steps:

    Get the core dump log from the device depending on enabled backends. For example, if the log module backend is used, get the log output from the log module backend.

    Convert the core dump log into a binary format that can be parsed by the GDB server. For example, scripts/coredump/coredump_serial_log_parser.py can be used to convert the serial console log into a binary file.

    Start the custom GDB server using the script scripts/coredump/coredump_gdbserver.py with the core dump binary log file, and the Zephyr ELF file as parameters.

    Start the debugger corresponding to the target architecture.

[More on Core Dump](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/zephyr/guides/flash_debug/coredump.html)
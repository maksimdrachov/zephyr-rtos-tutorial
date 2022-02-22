---
layout: post
title: '6.3 Kconfig'
parent: 'Lesson 6: Debugging'
---

## OpenOCD

## Thread analyzer

| CONFIG | Description |
| --- | --- |
| THREAD_ANALYZER | enable the module |
| THREAD_ANALYZER_USE_PRINTK | use printk for thread statistics |
| THREAD_ANALYZER_USE_LOG | use the logger for thread statistics |
| THREAD_ANALYZER_AUTO | run the thread analyzer automatically. You do not need to add any code to the application when using this option |
| THREAD_ANALYZER_AUTO_INTERVAL | the time for which the module sleeps between consecutive printing of thread analysis in automatic mode |
| THREAD_ANALYZER_AUTO_STACK_SIZE | the stack for thread analyzer automatic thread |
| THREAD_NAME | enable this option in the kernel to print the name of the thread instead of its ID |
| THREAD_RUNTIME_STATS | enable this option to print thread runtime data such as utilization (This options is automatically selected by THREAD_ANALYZER) |




## Core dump

| CONFIG | Description |
| --- | --- |
| DEBUG_COREDUMP | enable the module |
| DEBUG_COREDUMP_BACKEND_LOGGING | use log module for core dump output |
| DEBUG_COREDUMP_BACKEND_NULL | fallback core dump backend if other backends cannot be enabled. All output is sent to null. |
| DEBUG_COREDUMP_MEMORY_DUMP_MIN | only dumps the stack of the exception thread, its thread struct, and some other bare minimal data to support walking the stack in debugger. Use this only if absolute minimum of data dump is desired. |
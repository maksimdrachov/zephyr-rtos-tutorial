---
layout: post
title: '6.2 Commands'
parent: '6. Logging'
---

X: ERR, WRN, INF or DGB 

| Command             | Description                                                                                                                                                                      |
| ------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| LOG_X               | Writes an X level message to the log                                                                                                                                             |
| LOG_PRINTK          | Unconditionally print raw log message                                                                                                                                            |
| LOG_INST_X          | Writes an X level message associated with the instance to the log                                                                                                                |
| LOG_HEXDUMP_X       | Writes an X level hexdump message to the log                                                                                                                                     |
| LOG_INST_HEXDUMP_X  | Writes an X level hexdump message associated with the instance to the log                                                                                                        |
| LOG_MODULE_REGISTER | Create module-specific state and register the module with Logger. This macro normally must be used after including <logging/log.h> to complete the initialization of the module. |
| LOG_MODULE_DECLARE  | Macro for declaring a log module (not registering it).                                                                                                                           |
| LOG_LEVEL_SET       | Macro for setting log level in the file or function where instance logging API is used.                                                                                          |
|                     |                                                                                                                                                                                  |
|                     |                                                                                                                                                                                  |
|                     |                                                                                                                                                                                  |
|                     |                                                                                                                                                                                  |

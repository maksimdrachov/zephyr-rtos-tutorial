---
layout: post
title: '6.3 Kconfig'
parent: '6. Logging'
---

Mode of operations:

| Kconfig                    | Description                     |
| -------------------------- | ------------------------------- |
| CONFIG_LOG                 | Deferred mode                   |
| CONFIG_LOG_MODE_DEFERRED   | Deferred mode                   |
| CONFIG_LOG2_MODE_DEFERRED  | Deferred mode v2                |
| CONFIG_LOG_MODE_IMMEDIATE  | Immediate (synchronous) mode    |
| CONFIG_LOG2_MODE_IMMEDIATE | Immediate (synchronous) mode v2 |
| CONFIG_LOG_MODE_MINIMAL    | Minimal footprint mode          |

Filtering options:

| Kconfig                      | Description                                                                                         |
| ---------------------------- | --------------------------------------------------------------------------------------------------- |
| CONFIG_LOG_RUNTIME_FILTERING | Enables runtime reconfiguration of the filtering.                                                   |
| CONFIG_LOG_DEFAULT_LEVEL     | Default level, sets the logging level used by modules that are not setting their own logging level. |
| CONFIG_LOG_OVERRIDE_LEVEL    | It overrides module logging level when it is not set or set lower than the override value.          |
| CONFIG_LOG_MAX_LEVEL         | Maximal (lowest severity) level which is compiled in.                                               |

Processing options:

| Kconfig                | Description                                                                                                                                                                                                                                        |
| ---------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| CONFIG_LOG_PRINTK      | Redirect printk calls to the logging                                                                                                                                                                                                               |
| CONFIG_LOG_BUFFER_SIZE | Number of bytes dedicated for the message pool. Single message capable of storing standard log with up to 3 arguments or hexdump message with 12 bytes of data take 32 bytes. In v2 it indicates buffer size dedicated for circular packet buffer. |

Formatting options:

| Kconfig                             | Description                                                                                   |
| ----------------------------------- | --------------------------------------------------------------------------------------------- |
| CONFIG_LOG_FUNC_NAME_PREFIX_ERR     | Prepend standard ERROR log messages with function name. Hexdump messages are not prepended.   |
| CONFIG_LOG_FUNC_NAME_PREFIX_WRN     | Prepend standard WARNING log messages with function name. Hexdump messages are not prepended. |
| CONFIG_LOG_FUNC_NAME_PREFIX_INF     | Prepend standard INFO log messages with function name. Hexdump messages are not prepended.    |
| CONFIG_LOG_FUNC_NAME_PREFIX_DBG     | Prepend standard DEBUG log messages with function name. Hexdump messages are not prepended.   |
| CONFIG_LOG_BACKEND_SHOW_COLOR       | Enables coloring of errors (red) and warnings (yellow).                                       |
| CONFIG_LOG_BACKEND_FORMAT_TIMESTAMP | If enabled timestamp is formatted to hh:mm:ss:mmm,uuu. Otherwise is printed in raw format.    |



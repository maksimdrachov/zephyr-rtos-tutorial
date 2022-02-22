---
layout: post
title: '11.1 Introduction'
parent: 'Lesson 11: Logging'
---

*What is logging?*

The logging API provides a common interface to process messages issued by developers. Messages are passed through a frontend and are then processed by active backends. Custom frontends and backend can be used if needed. Default configuration uses built-in frontend and UART backend.

Logging is highly configurable at compile time as well as at run time. Using Kconfig options logs can be gradually removed from compilation to reduce image size and execution time when logs are no longer needed. During compilation logs can be filtered out on module basis and severity level.

Logs can also be compiled in but filtered on run time using dedicated API. Run time filtering is indepenent for each backend and each source of log messages. Source of log messages can be a module or specific instance of the module. 

There are four severity levels available in the system: error, warning, info and debug. For each severity level the logging API (include/logging/log.h) has a set of dedicated macros. Logger API also has macros for logging data. 

For each level following set of macros are available (change X by level ERR, WRN, INF or DBG):
- LOG_X for standard printf-like messages, e.g. LOG_ERR.
- LOG_HEXDUMP_X for dumping data, e.g. LOG_HEXDUMP_WRN.
- LOG_INST_X for standard printf-like message associated with the particular instance, e.g. LOG_INST_INF.
- LOG_INST_HEXDUMP_X for dumping data associated with the particular instance, e.g. LOG_HEXDUMP_INST_DBG.

There are configuration categories: configurations per module and global configuration. When logging is enabled globally, it works for modules. However, modules can disable logging locally. Every module can specify its own logging level. The module must define the LOG_LEVEL macro before using the API. Unless a global override is set, the module logging level will be honored. The global override can only increase the logging level. It cannot be used to lower module logging levels that were previously higher. It is also possible to globally limit logs by providing maximal severity level present in the system, where maximal means lowest severity (e.g. if maximal level in the system is set to info, it means that errors, warnings and info levels are present but debug messages are excluded).

Each module which is using the logging must specify its unique name and register itself to the logging. If module consists of more than one file, registration is performed in one file but each file must define a module name.

Logger's default frontend is designed to be thread-safe and minimizes time needed to log the message. Time consuming operations like string formatting or access to the transport are not performed by default when logging API is called. When logging API is called a message is created and added to the list. Dedicated, configurable buffer for pool or log messages is used. There are 2 types of messages: standard and hexdump. Each message contains source ID (module or instance ID and domain ID which might be used for multiprocessor systems), timestamp and severity level. Standard message contains pointer to the string and arguments. Hexdump message contains copied data and string. 

*How to use logging?*

In order to use logging in the module, a unique name of a module must be specified and module must be registered using LOG_MODULE_REGISTER. Optionally, a compile time log level for the module can be specified as the second parameter. Default log level (CONFIG_LOG_DEFAULT_LEVEL) is used if custom log level is not provided.

```c
#include <logging/log.h>
LOG_MODULE_REGISTER(foo, CONFIG_FOO_LOG_LEVEL);
```

If the module consists of multiple files, then LOG_MODULE_REGISTER should appear in exactly one of them. All the other files should use LOG_MODULE_DECLARE to declare its membership in the module. Optionally, a compile time log level for the module can be specified as the second parameter. Default log level (CONFIG_LOG_DEFAULT_LEVEL) is used if custom log level is not provided.

```c
#include <logging/log.h>
/* In all files comprising the module but one */
LOG_MODULE_DECLARE(foo, CONFIG_FOO_LOG_LEVEL);
```

In order to use logging API in a function implemented in a header file LOG_MODULE_DECLARE macro must be used in the function body before logging API is called. Optionally, a compile time log level for the module can be specified as the second parameter. Default log level (CONFIG_LOG_LEVEL_DEFAULT_LEVEL) is used if custom log level is not provided.

```c
#include <logging/log.h>

static inline void foo(void)
{
     LOG_MODULE_DECLARE(foo, CONFIG_FOO_LOG_LEVEL);

     LOG_INF("foo");
}
```

Dedicated Kconfig template (subsys/logging/Kconfig.template.log_config) can be used to create local log level configuration.

Example below presents usage of the template. As a result CONFIG_FOO_LOG_LEVEL will be generated:

```
module = FOO
module-str = foo
source "subsys/logging/Kconfig.template.log_config"
```

Controlling the logging

Logging can be controlled using API defined in include/logging/log_ctrl.h. Logger must be initialized before it can be used. Optionally, user can provide a function which returns time; if not, k_cycle_get_32 is used. log_process() function is used to trigger processing of one log message (if pending). Function returns true if there is more messages pending. 

Following snippet shows how logging can be processed in simple forever loop.

```c
#include <log_ctrl.h>

void main(void)
{
     log_init();

     while (1) {
             if (log_process() == false) {
                     /* sleep */
             }
     }
}
```



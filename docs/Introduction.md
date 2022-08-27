---
layout: post
title: Introduction
nav_order: 1
---

# Introduction

In this tutorial we'll be taking a closer look at the Zephyr real-time operating system (RTOS). Before we dive in, it might be useful to understand why an RTOS has become a foundational building block for modern embedded systems. 

As embedded systems have become increasingly complex with more devices becoming connected to the Internet, the difficulty for writing software for such systems has increased as well. Modern applications often require a delicate balance between executing multiple task simultanously (with tight timing constraints), as well as managing complex protocols such as WiFi, Bluetooth, USB, encryption,... To manage this increased complexity, programming purely on the bare metal level is no longer a feasible proposition. An RTOS provides an abstraction for certain commonly used functionality allowing the developer to focus on the actual application itself, without having to re-implement everything from scratch.

In this tutorial we won't necessarily be digging 'under the hood' of the RTOS, there have already been written many [books](https://www.amazon.com/Embedded-RTOS-Design-Insights-Implementation/dp/0128228512/) that cover this topic quite extensively. Instead we'll be mainly focusing on the functionality provided by Zephyr and learning how to actually *use* it. 

## Why Zephyr?

Zephyr RTOS is a relatively new real-time operating system that offers support for a wide variety of MCU architectures. You get all the common kernel features such as threads, semaphores, mutexes, etc. that other RTOSes provide (with FreeRTOS being another popular option). A complete in-depth comparison between the different RTOSes is beyond the scope this tutorial, but suffice it to say I think Zephyr does a good job in making it easy to work with these "kernel objects".

### Open source

Another major benefit of Zephyr RTOS is that it is completely open source and backed by the Linux Foundation. Other RTOSes are often backed by industry giants such as Amazon (FreeRTOS), Azure RTOS (Microsoft) and MbedOS (ARM); resulting in possible vendor lock-in.

Perhaps unsurprisingly this means that Zephyr's addoption is heavily accelated by its open nature. This can be seen by its massive amount of contributions. 

<center>[Contributions to the Zephyr RTOS GitHub repository](https://github.com/zephyrproject-rtos/zephyr/graphs/contributors)</center>

![zephyr-github](../images/introduction/zephyr-github.png)

<center>[Contributions to the FreeRTOS GitHub repository](https://github.com/FreeRTOS/FreeRTOS-Kernel/graphs/contributors)</center>

![freertos-github](../images/introduction/freertos-github.png)

<center>[Contributions to the Azure RTOS GitHub repository](https://github.com/azure-rtos/threadx/graphs/contributors)</center>

![azure-rtos-github](../images/introduction/azure-rtos-github.png)

### Kconfig

Another distinctive feature of Zephyr is its unique build and configuration system. For those coming from the embedded Linux world, Kconfig is a familiar feature that allows developers to adjust the build process of the kernel, and hereby include only those features that are necessary (reducing the memory footprint).

There's many more features that can be discussed, if you're interested [this](https://medium.com/geekculture/the-zephyr-rtos-is-awesome-931bce3a695f) article covers some additional benefits of using Zephyr.

## Deployed examples

And last but not least here are some companies that are already using Zephyr in their products:

- teenage engineering ([video](https://twitter.com/ZephyrIoT/status/1366674644145737730))
- byte lab ([blog](https://www.byte-lab.com/why-developers-should-choose-zephyr-rtos/))
- Golioth ([blog](https://zephyrproject.org/connectig-conexio-stratus-to-golioth/))
- Antmicro ([blog](https://www.zephyrproject.org/antmicro-doubles-down-on-commitment-to-zephyr-rtos-as-community-grows-to-more-than-1000-contributors/))


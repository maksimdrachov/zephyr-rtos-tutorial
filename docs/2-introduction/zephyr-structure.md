---
layout: post
title: '2.2 Zephyr structure'
parent: '2. Introduction'
nav_order: 10
---

# Zephyr structure

## How to work with Zephyr?

Before we start writing our first applications in Zephyr, it might be a good step to take a look at the folder structure that Zephyr provides us.

![sample-folder]({{ site.baseurl }}/images/2-introduction/sample-folder.png)

Let's go one-by-one:

### build
This folder appears only once you have build your application and contains the files that are used to flash your microcontroller.

The following files are sometimes interesting to take a look at:
- **build/zephyr/zephyr.dts**: CMake uses a devicetree to tailor the build towards your specific architecture/board. This is the final version of that file. Here you'll be able to find all the different functionality (GPIO, Timers, PWM, DMA, UART, SPI, I2C, DAC, USB,...) that is present on your MCU (that can then be called upon in your application).
- **build/zephyr/.config**: The final Kconfig used for your built. This can be useful to verify if a setting has been set correctly.

### CMakeLists.txt
This file will be used by [CMake](https://en.wikipedia.org/wiki/CMake) to set up your build, during this tutorial you won't need to change this one.

### prj.conf
This is you Kconfig file. **Important!** This file will contain any *additional* settings you want set for your particular Zephyr build. Depending on your particular application, you might want to (for example) include a TCP/IP stack or make some changes to the scheduler. We'll explore some of these options throughout the tutorial.

![k-config]({{ site.baseurl }}/images/2-introduction/k-config.png)

Right now it's pretty empty, since for `basic-sample` we don't require any "fancy" functionality, just the basic Zephyr kernel. The only additional functionality we set is `CONFIG_PRINTK`, which allows us to use the `printk` function to output to the serial port (which is then displayed on your computer screen using Coolterm).

If you're ever unsure about what a particular config setting does, you have 2 options:
- Use [google](https://www.google.com/search?client=firefox-b-d&q=zephyr+CONFIG_PRINTK): usually Zephyr Documentation is one of the first links
- Use the `guiconfig`: in your `basic-sample` folder execute `west build -t guiconfig`. This will show you a menu of all the possible configuration settings and a small description of what each one does. (Use `Jump to` to find a particular config)
  
![guiconfig]({{ site.baseurl }}/images/2-introduction/guiconfig.png)

### src
Where the magic happens! This folder should contain all of your custom application code. For now it contains one file: `main.c`, which prints out a message to the serial port and then sleeps for 1 second.

![basic-sample]({{ site.baseurl }}/images/2-introduction/basic-sample.png)
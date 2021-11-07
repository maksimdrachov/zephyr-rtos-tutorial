## RTOS basics

*Why do I need an RTOS?*

An RTOS is rarely a requirement, however as you start to increase the functionality of your embedded applications, it becomes increasingly harder to do everything within one single main loop and some interrupt routines. Usually the next level of complexity is some kind of state machine, where the output of your electronic device changes depending on this (internal) state. This however only gets you so far. For example, what if you need to be able to operate multiple complex inputs and outputs simultanously? A good example could be an TCP/IP connection, over which you'll be receiving some kind of data which then has to be used to operate a robotic arm, control an electric motor, send out a signal... It quickly becomes clear that a new level of abstraction is required to not drown in the complexity that would be required to implement something like that. This is where an RTOS comes in.

An RTOS is a suite of firmware that helps you build more complex apps, than would otherwise be feasible. It gives you the tools, the way you use those tools is however completely up to you! First and foremost it means having **threads**, this means that you'll be able to execute multiple tasks in parallel, neatly dividing them into their own area in memory. Then each RTOS provides varying levels of support for different protocols such as TCP/IP, Bluetooth, LoRaWan,... This makes your life easier, since now you won't have to study these protocols as in-depth. You'll get a series of API calls which should increase speed of development.

*What makes Zephyr different from other RTOS'es?*

As I haven't had the time to study other RTOS'es as in-depth I might be biased here. However from my point of view, studying Zephyr has the following benefits:
- Zephyr is supported by the Linux Foundation
- By learning Zephyr you'll automatically get a taste for the Linux kernel. Both show some overlap in the way they are implemented, for example: Kconfig and devicetrees are some of the concepts borrowed by Zephyr from Linux
- Zephyr is flexible: you can trade off footprint versus extra functionality (through Kconfig). If you don't know how this works don't worry, I'll explain this later.
- Zephyr supports a wide variety of different dev boards/SoCs. 
- A more extensive lists of reasons can be found [here](https://docs.zephyrproject.org/latest/introduction/index.html)

*How does an RTOS work and what are some key concepts?* 

Ok, so now that I've hopefully convinced you of the *use* of an RTOS, let's start by taking a look at *how* this all works. The first and most fundamental part of an RTOS is the **kernel**. The kernel is responsible for scheduling CPU time for each particular task so that they *appear* to be happening simultanously. The particulars of how this scheduling algorithm (or also called: **scheduler**) works is not important for now. 

Each **thread** (or task) will use registers and memory as it executes. The whole of these processor registers and stack (memory) compromise the **context** of that particular thread. Once the RTOS decides to switch the thread and run something else, it will need to first *store* context away and then *load* in the context for the thread it wants to run next. This process is called **context switching**.
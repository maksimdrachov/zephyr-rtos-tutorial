## Introduction
In this lesson we'll be covering the way GPIO works in Zephyr. Only the basics:
- input
- output
- interrupts

## How it works
For using GPIO the following basic steps can be identified:

1) Get devicetree binding for required GPIO
2) Configure GPIO
    - set input/output configuration
    - set interrupt configuration
3) Use functions to affect GPIO (set, read, toggle,...)



## Devicetree
From wikipedia: "a device tree is a data structure describing the hardware components of a particular computer so that the operating system's kernel can use and manage those components, including the CPU or CPUs, the memory, the buses and the peripherals."

In short: the devicetree will help Zephyr locate all the components of your particular SoC/Board and in this way it will be able to work regardless of the underlying hardware. That also means if we want to access anything on the board from within Zephyr, we'll need to know the binding of that particular component in our devicetree. For example, if we want to blink an LED on the board, we'll first have to determine how that led is called in the devicetree. If you want to learn more about devicetree, I'd recommend watching [this](https://www.youtube.com/watch?v=m_NyYEBxfn8) video, which explains it pretty well. (Devicetree is a concept borrowed from Linux)
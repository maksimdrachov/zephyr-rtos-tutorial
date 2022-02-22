---
layout: post
title: '7.4 Exercise'
parent: 'Lesson 7: Interrupts'
---

## Button-interrupt
GPIO-input-interrupt

Configure an interrupt on a button press.

1 thread running continously putting out "loop message" every second

on button press: print out "isr message"



[Zephyr docs](https://docs.zephyrproject.org/1.9.0/kernel/other/interrupts.html)
[Example 1](https://github.com/zephyrproject-rtos/zephyr/issues/13514)
[Example 2](https://github.com/zephyrproject-rtos/zephyr/issues/9630)

User button and LED aliases can be found in the devicetree file `build/zephyr/zephyr.dts`.

![button-interrupt-alias](/images/interrupts/button-interrupt-alias.png)

Expected output:

![button-interrupt-output](/images/interrupts/button-interrupt-output.png)
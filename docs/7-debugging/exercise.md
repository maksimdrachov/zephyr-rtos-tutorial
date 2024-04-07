---
layout: post
title: '7.4 Exercise'
parent: '7. Debugging'
---

## Exercise 1: Multiple threads debugging

Using the code from the previous section (time-slicing), we'll try to see how debugging works in VSCode.

1) in `multi-thread-debug` create folder `.vscode`
2) in `.vscode` create file `launch.json`
3) setup your debug config as follows inside `launch.json` (change as applicable)

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "type": "cortex-debug",
            "request": "launch",
            "servertype": "openocd",
            "cwd": "${workspaceRoot}",
            "executable": "build/zephyr/zephyr.elf",
            "name": "zephyr STM32F756ZG",
            "configFiles": [
                "/Users/maksim/zephyrproject/zephyr/boards/arm/nucleo_f756zg/support/openocd.cfg"
                   ],
            "svdFile": "STM32F756.svd"
        }
    ]
}
```

The svd file can be found on the [STM](https://www.st.com/en/microcontrollers-microprocessors/stm32f756zg.html#cad-resources) website. Add this file to your folder and mention it in `launch.json`, this way you'll be able to easily read out the different registers/peripherals/memory once you're in debug mode.

4) the svd file is necessary to be able to read registers from that specific stm processor

5) Now go to Run->Start debugging

*The first screen should look like this:*

![debug-starting]({{ site.baseurl }}/images/debugging/debug-starting.png)

*If you put an interrupt in the first interrupt, the execution will again be stopped at this point*

![debug-breakpoint]({{ site.baseurl }}/images/debugging/debug-breakpoint-1.png)

Notice the "Cortex Peripherals" and "Cortex Registers" on the left-hand side.

## Exercise 2: Print runtime statistics

1) Go to `exercises/debugging/runtime-statistics`

2) Build & Flash

```
west build -b nucleo_f756zg
west flash
```

3) Observe the output in the serial monitor:

![runtime-statistics]({{ site.baseurl }}/images/debugging/runtime-statistics.png)

## Exercise 3: Core dump

_Come back to this when I understand GDB better_

{% include incomplete.md %}

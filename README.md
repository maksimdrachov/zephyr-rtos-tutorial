# Zephyr: Tutorial for Beginners

- [Zephyr: Tutorial for Beginners](#zephyr-tutorial-for-beginners)
  - [1. Introduction](#1-introduction)
    - [1.1. Useful links](#11-useful-links)
  - [2. Setup](#2-setup)
    - [2.1. VSCode + PlatformIO + Zephyr RTOS](#21-vscode--platformio--zephyr-rtos)
    - [2.2. VSCode + West + Zephyr RTOS](#22-vscode--west--zephyr-rtos)
    - [2.3. Eclipse + Plugin + Zephyr RTOS](#23-eclipse--plugin--zephyr-rtos)
  - [3. The Basics](#3-the-basics)
    - [3.1. RTOS basics](#31-rtos-basics)
    - [3.2. Zephyr-specific basics](#32-zephyr-specific-basics)
    - [3.3. CMake](#33-cmake)
  - [4. Examples](#4-examples)
  - [5. Debugging](#5-debugging)
  - [6. Projects using Zephyr RTOS](#6-projects-using-zephyr-rtos)

## 1. Introduction
Since Zephyr is a pretty young project I have found it a bit lacking in terms of tutorials for beginners (like myself). Therefore I decided to start writing this; to have 1 place that gives beginners a simple place to get started.

### 1.1. Useful links
- [Zephyr Official Documentation](https://docs.zephyrproject.org/latest/)
- [Introduction to the Zephyr RTOS (video)](https://www.youtube.com/watch?v=jR5E5Kz9A-k): watch from 14:30-51:00
- [PlatformIO: Zephyr RTOS documentation](https://docs.platformio.org/en/latest/frameworks/zephyr.html)
  
## 2. Setup
### 2.1. VSCode + PlatformIO + Zephyr RTOS
- NOOB-friendly!

This is the one that I'm currently using, the examples are based on this setup.

Setup:
1) Install VSCode
2) Add PlatformIO extension (will install Zephyr for you)
### 2.2. VSCode + West + Zephyr RTOS
- Real pro's use this.


### 2.3. Eclipse + Plugin + Zephyr RTOS
Relevant [section](https://docs.zephyrproject.org/latest/application/index.html?highlight=eclipse#debug-with-eclipse) in Zephyr Documentation.

- Zephyr-plugin doesn't work with the latest Eclipse. ([github-issue](https://github.com/zephyrproject-rtos/eclipse-plugin/issues/45))
- However if you use an older version it should work apparently. (haven't tested this myself)

Setup: [link](https://docs.zephyrproject.org/latest/application/index.html?highlight=eclipse#debug-with-eclipse)

Setup: [link](https://docs.zephyrproject.org/latest/getting_started/index.html)

## 3. The Basics

### 3.1. RTOS basics
This [section](https://www.freertos.org/implementation/a00002.html) from FreeRTOS should cover the basics of what an RTOS does.

### 3.2. Zephyr-specific basics

A Zephyr application directory has the following components:
- **CMakeLists.txt**: your build settings configuration file - this tells west (really a cmake build system under the hood) where to find what it needs to create your firmware. For more advanced projects, it's also used for debug settings, emulation, and other features.
- **prj.conf**: the Kernel configuration file. For most projects, it tells Zephyr whether to include specific features for use in your application code - if you use GPIO, PWM, or a serial monitor, you’ll need to enable them in this file first. Sometimes also referred to as Kconfig file. There is also something of a [GUI](https://docs.zephyrproject.org/2.4.0/guides/kconfig/menuconfig.html) which is helpful if you don't know where to start.
- **src/main.c**: your custom application code - where the magic happens! It’s advisable to put all of your custom source code in a `src/` directory like this so it doesn’t get mixed up with your configuration files.

Explanation on devicetree needed.

### 3.3. CMake

At some point you will need to understand how CMake works.

[Video Tutorial](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4) <- This one offers a pretty clear explanation for beginners

[Wiki CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

## 4. Examples
Location: `~/zephyrproject/zephyr/samples`

Basic examples useful to study for beginners are discussed here.

- PlatformIO: [examples_PIO.md](https://github.com/maksimdrachov/zephyr-rtos-tutorial/blob/main/examples_PIO.md)
- west: [examples_west.md](https://github.com/maksimdrachov/zephyr-rtos-tutorial/blob/main/examples_west.md)

More advanced examples are discussed in [examples.md](https://github.com/maksimdrachov/zephyr-rtos-tutorial/blob/main/examples.md)



## 5. Debugging
```diff
- Can someone explain the setup for debugging?
```
 Is it possible to get RTOS aware debugging inside PlatformIO?

## 6. Projects using Zephyr RTOS
- [Air-quality sensor](https://github.com/ExploratoryEngineering/air-quality-sensor-node)
- [Pinetime-hypnos](https://github.com/endian-albin/pinetime-hypnos) (smartwatch)
- [RT-Loc](https://github.com/RT-LOC/zephyr-dwm1001) (Ultra Wideband localisation using DWM1001 module)
- [BLE Environmental Sensor](https://github.com/patrickmoffitt/zephyr_ble_sensor)

This is the project I'm currently working on. For clarity, I'm documenting what each line does, so I can gain a better understanding:
- [STM32 Artnet-node](https://github.com/maksimdrachov/stm32-artnet)
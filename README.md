# Zephyr: Tutorial for Beginners

- [Zephyr: Tutorial for Beginners](#zephyr-tutorial-for-beginners)
  - [1. Introduction](#1-introduction)
    - [1.1. Useful links](#11-useful-links)
  - [2. Setup](#2-setup)
    - [2.1. VSCode + PlatformIO + Zephyr RTOS](#21-vscode--platformio--zephyr-rtos)
    - [2.2. Eclipse + Zephyr RTOS](#22-eclipse--zephyr-rtos)
    - [2.3. West + Zephyr RTOS](#23-west--zephyr-rtos)
  - [3. The Basics](#3-the-basics)
    - [3.1. RTOS basics](#31-rtos-basics)
    - [3.2. Zephyr-specific basics](#32-zephyr-specific-basics)
  - [4. Examples](#4-examples)
    - [4.1. Classic Samples](#41-classic-samples)
      - [4.1.1. Hello World](#411-hello-world)
      - [4.1.2. Synchronization Sample](#412-synchronization-sample)
      - [4.1.3. Dining Philosophers](#413-dining-philosophers)
    - [4.2. Basic Samples](#42-basic-samples)
      - [4.2.1. Blinky](#421-blinky)
      - [4.2.2. PWM Blinky](#422-pwm-blinky)
      - [4.2.3. Button](#423-button)
      - [4.2.4. Fade LED](#424-fade-led)
      - [4.2.5. Minimal footprint](#425-minimal-footprint)
      - [4.2.6. PWM: RGB LED](#426-pwm-rgb-led)
      - [4.2.7. Servomotor](#427-servomotor)
      - [4.2.8. Basic Thread Example](#428-basic-thread-example)
    - [4.3. Userspace Samples](#43-userspace-samples)
      - [4.3.1. Hello World](#431-hello-world)
      - [4.3.2. Producer/consumer](#432-producerconsumer)
      - [4.3.3. Userspace Protected Memory](#433-userspace-protected-memory)
      - [4.3.4. Syscall performances](#434-syscall-performances)
  - [6. Projects using Zephyr RTOS](#6-projects-using-zephyr-rtos)

## 1. Introduction
Since Zephyr is a pretty young project I have found it a bit lacking in terms of tutorials for beginners (like myself). Therefore I decided to start writing this; to have 1 place that gives beginners a simple place to get started.

### 1.1. Useful links
- [Zephyr Official Documentation](https://docs.zephyrproject.org/latest/)
- [Introduction to the Zephyr RTOS (video)](https://www.youtube.com/watch?v=jR5E5Kz9A-k): watch from 14:30-51:00
- [PlatformIO: Zephyr RTOS documentation](https://docs.platformio.org/en/latest/frameworks/zephyr.html)
  
## 2. Setup
### 2.1. VSCode + PlatformIO + Zephyr RTOS
This is the one that I'm currently using, the examples are based on this setup.
### 2.2. Eclipse + Zephyr RTOS
Relevant [section](https://docs.zephyrproject.org/latest/application/index.html?highlight=eclipse#debug-with-eclipse) in Zephyr Documentation.
### 2.3. West + Zephyr RTOS


## 3. The Basics

### 3.1. RTOS basics
This [section](https://www.freertos.org/implementation/a00002.html) from FreeRTOS should cover the basics of what an RTOS does.

### 3.2. Zephyr-specific basics

A Zephyr application directory has the following components:
- **CMakeLists.txt**: your build settings configuration file - this tells west (really a cmake build system under the hood) where to find what it needs to create your firmware. For more advanced projects, it's also used for debug settings, emulation, and other features.
- **prj.conf**: the Kernel configuration file. For most projects, it tells Zephyr whether to include specific features for use in your application code - if you use GPIO, PWM, or a serial monitor, you’ll need to enable them in this file first. Sometimes also referred to as Kconfig file.
- **src/main.c**: your custom application code - where the magic happens! It’s advisable to put all of your custom source code in a `src/` directory like this so it doesn’t get mixed up with your configuration files.

Explanation on devicetree needed.

## 4. Examples
Location: `~/zephyrproject/zephyr/samples`

Basic examples useful to study for beginners are discussed here.

More advanced examples are discusses in examples.md

### 4.1. Classic Samples

#### 4.1.1. Hello World
#### 4.1.2. Synchronization Sample
#### 4.1.3. Dining Philosophers

### 4.2. Basic Samples

#### 4.2.1. Blinky
#### 4.2.2. PWM Blinky
#### 4.2.3. Button
#### 4.2.4. Fade LED
#### 4.2.5. Minimal footprint
#### 4.2.6. PWM: RGB LED
#### 4.2.7. Servomotor
#### 4.2.8. Basic Thread Example

### 4.3. Userspace Samples

#### 4.3.1. Hello World
#### 4.3.2. Producer/consumer
#### 4.3.3. Userspace Protected Memory
#### 4.3.4. Syscall performances

## 6. Projects using Zephyr RTOS
- [Air-quality sensor](https://github.com/ExploratoryEngineering/air-quality-sensor-node)
- [Pinetime-hypnos](https://github.com/endian-albin/pinetime-hypnos) (smartwatch)
- [RT-Loc](https://github.com/RT-LOC/zephyr-dwm1001) (Ultra Wideband localisation using DWM1001 module)
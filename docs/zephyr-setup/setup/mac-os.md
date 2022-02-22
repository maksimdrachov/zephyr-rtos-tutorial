---
layout: post
title: 'MacOS'
parent: '1.2 Basic Workspace Setup'
grand_parent: 'Lesson 1: Zephyr Setup'
nav_order: 11
---

# Setup
**1) Install VSCode**

- Add the following extensions to VSCode:
    - C/C++
    - Cortex-Debug
    - DeviceTree

- Optional: [set terminal color to green](https://stackoverflow.com/questions/42307949/color-theme-for-vs-code-integrated-terminal)

- Clone tutorial folder into `~/zephyrproject`
```
cd ~/zephyrproject
git clone https://github.com/maksimdrachov/zephyr-rtos-tutorial

```

**2) Install Coolterm**

- [Dowload](https://freeware.the-meiers.org/)

- Connect your Nucleo board to your computer

- Set up serial connection with Nucleo
    - Port: usbmodemxxxxx
    - Baudrate: 115200

![coolterm-1](/images/zephyr-setup/coolterm-1.png)

Terminal -> check "Filter ASCII Escape Sequences"

![coolterm-2](/images/zephyr-setup/coolterm-2.png)

`File -> Save`

Save this configuration under `~/dev-tools/coolterm`, since you'll need it often.  (suggested name: nucleo-f756zg)

**3) Build and Flash basic-sample**
- Open the folder zephyr-rtos-tutorial in VScode

- Open Coolterm with the `nucleo-f756zg` configuration and connect

- `Terminal -> New Terminal`
```
cd exercises/basic-sample
west build -b nucleo_f756zg
west flash
```

Tip: if you've previously made a build for a different board, remove the old build first:

`rm -rf build`

- Verify the serial output:

![coolterm-3](/images/zephyr-setup/coolterm-3.png)

Your final setup should look something like this:

![final-setup](/images/zephyr-setup/final-setup.png)
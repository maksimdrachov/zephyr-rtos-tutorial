---
layout: post
title: 'MacOS'
parent: '1.2 Workspace Setup'
grand_parent: '1. Zephyr Setup'
nav_order: 1
---

# Setup

## 1) Coolterm

- Download and install [Coolterm](https://freeware.the-meiers.org/)

- Connect your board to your computer

- `Options`: Set up serial connection with Nucleo
    - Port: `usbmodemxxxxx`
    - Baudrate: `115200`

![coolterm-1](../../images/1-zephyr-setup/coolterm-1.png)

- `Terminal`: check "Filter ASCII Escape Sequences" and press `Ok`

![coolterm-2](../../images/1-zephyr-setup/coolterm-2.png)

- `File -> Save`: Save this configuration under `~/zephyrproject`

![coolterm-settings](../../images/1-zephyr-setup/coolterm-settings.png)

- `Connect`
  
![coolterm-connect](../../images/1-zephyr-setup/coolterm-connect.png)

## 2) VSCode

- Install [VSCode](https://code.visualstudio.com/)

- Add the following extensions to VSCode:
    - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
    - [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)
    - [DeviceTree](https://marketplace.visualstudio.com/items?itemName=plorefice.devicetree)

- Clone tutorial repository into `~/zephyrproject` and open VSCode
  
```
cd ~/zephyrproject
git clone https://github.com/maksimdrachov/zephyr-rtos-tutorial
cd zephyr-rtos-tutorial
code .
```

- VSCode: `Terminal -> New Terminal`
  
```
cd exercises/basic-sample
west build -b nucleo_l552ze_q
west flash
```

{: .note }
> If you've previously made a build for a different board, remove the old build first: `rm -rf build`
> For convenience, full path to the basic-sample page: `cd ~/zephyrproject/zephyr-rtos-tutorial/exercises/basic-sample`

- Verify the serial output:

![coolterm-3](../../images/1-zephyr-setup/coolterm-3.png)

Your final setup should look something like this:

![final-setup](../../images/1-zephyr-setup/final-setup.png)
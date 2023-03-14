---
layout: post
title: 'Linux'
parent: '1.1 Installation'
grand_parent: '1. Zephyr Setup'
nav_order: 2
---

# Install

## 1) Install dependencies
I am going to setup for Arch Linux but the steps are similar for all the other Linux distributions. You can find the official getting started guide with steps for Ubuntu [here](https://docs.zephyrproject.org/latest/develop/getting_started/index.html).
- Upgrade the OS
```
$ sudo pacman -Syyu
```
- Installing the packages
```
$ sudo pacman -S base-devel git cmake ninja gperf ccache dfu-util dtc wget python python-pip python-setuptools xz file make gcc multilib-devel sdl2 tk 
```
Verify the versions of main dependencies
```
$ cmake --version
$ python3 --version
$ dtc --version
```

## 2) Clone Zephyr
- Install `west` tool via pip
```
$ pip3 install west
```
- Get Zephyr source code
```
$ mkdir ~/zephyrproject
$ west init ~/zephyrproject
$ cd ~/zephyrproject
$ west update 
```
- Export Zephyr Cmake package
```
$ west zephyr-export
```
- Install Zephyr python dependencies
```
$ pip3 install -r zephyr/scripts/requirements.txt
```

## 3) Cloning the Zephyr SDK
I will be using the `/opt` folder to store the Zephyr SDK. I already have write access. If you get any errors of permission denied. I suggest you to `chown` the `/opt` folder.

- Download and Verify SDK
```
$ cd /opt
$ wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.15.2/zephyr-sdk-0.15.2_linux-x86_64.tar.gz
$ wget -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.15.2/sha256.sum | shasum --check --ignore-missing
```

- Extract the SDK
```
$ tar xvf zephyr-sdk-0.15.2_linux-x86_64.tar.gz
```
- Run setup script
```
$ cd zephyr-sdk-0.15.2
$ ./setup.sh
```
{:.note}
> This setup script needs to be run only once or whenever you change the location of the SDK folder.

- Install `udev` rules
```
$ sudo cp ~/zephyr-sdk-0.15.2/sysroots/x86_64-pokysdk-linux/usr/share/openocd/contrib/60-openocd.rules /etc/udev/rules.d
$ sudo udevadm control --reload
```

## 3) Building the Hello, World
{:.note}
> Thie list of supproted boards can be found [here](https://docs.zephyrproject.org/latest/boards/index.html#boards). I am going to use ESP32 for this example.
```
cd ~/zephyrproject/zephyr
$ west build -p always -b esp32 samples/hello_world/
```
The `-p` option does a pristine build. It is used to build when there is any changes done to the CMake.

A successful build looks like this
![success_build_hello_world](/images/1-zephyr-setup/hello_world_build_success.png)
Now flash the board with
```
$ west flash
```
To open the serial monitor
```
$ west espressif monitor
```
You should see the similar output
// TODO: Add hello, world output

## 4) Building the blinky
Now, let's try to blink the builtin LED on ESP32. The sample is in `zephyr/samples/basic/blinky`
```
$ west build -p -b esp32 samples/basic/blinky
```
If you encounter build errors like this
![blinky_build_error](/images/1-zephyr-setup/blinky_build_errors.png)
It means that we need to add an overlay file with the board support. This file can be added for any unsupported board with the `<board-name>.overlay`. <br/>
Create an `esp32.overlay` file in `zephyr/samples/basic/blinky/` and add the following contents
```dtc
/ {
     aliases {
             led0 = &myled0;
     };

     leds {
             compatible = "gpio-leds";
             myled0: led_0 {
                     gpios = <&gpio0 0 GPIO_ACTIVE_LOW>;
             };
     };
};
```
It will blink the LED connected to GPIO 0 (BUILTIN_LED). Now try to build
```
$ west build -p -b esp32 samples/basic/blinky
```
And flash it with 
```
$ west flash
```

The board will start to blink </br>
![](https://www.electronicshub.org/wp-content/uploads/2021/02/ESP32-LED-Blink-GIF.gif)
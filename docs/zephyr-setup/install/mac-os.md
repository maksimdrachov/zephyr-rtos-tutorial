---
layout: post
title: 'MacOS'
parent: '1.1 Installation'
grand_parent: 'Lesson 1: Zephyr Setup'
---

# Install
**1) Install dependencies**
- Install Homebrew
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

- Use brew to install the required dependencies

```
brew install cmake ninja gperf python3 ccache qemu dtc textmate    
```

**2) Clone Zephyr into new folder `zephyrproject`**
```
cd ~
mkdir zephyrproject
cd zephyrproject
git clone https://github.com/zephyrproject-rtos/zephyr
```

**3) Install `west`**
- Install west

```
pip3 install -U west
```

- Get the Zephyr source code
```
west init ~/zephyrproject
cd ~/zephyrproject
west update
```

- Export a Zephyr CMake package. This allows CMake to automatically load [boilerplate](https://en.wikipedia.org/wiki/Boilerplate_code) code required for building Zephyr applications.
```
west zephyr-export
```

- Zephyr’s `scripts/requirements.txt` file declares additional Python dependencies. Install them with `pip3`.
```
pip3 install -r ~/zephyrproject/zephyr/scripts/requirements.txt
```

**4) Install GNU ARM Embedded toolchain**
- Dowload [GNU ARM Embedded build](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) and extract in `~/dev-tools`
- Set environment variables in `~/.zshenv`
```
mate .zshenv
```
Add the following lines. Make sure to use the right toolchain version, yours might be slightly different!
```
export ZEPHYR_TOOLCHAIN_VARIANT=GNUARMEMB
export GNUARMEMB_TOOLCHAIN_PATH=/Users/maksim/dev-tools/gcc-arm-none-eabi-10.3-2021.07
```
- Restart terminal and check if environment variables are set up correctly
![env_var_check](/images/zephyr-setup/env-var-check.png)

**5) Build the Blinky sample**
```
cd ~/zephyrproject/zephyr/samples/basic/blinky
west build -b nucleo_f756zg
```
A succesful build looks like this:
![succes_build](/images/zephyr-setup/succes-build.png)

**6) Flash the Sample**
```
cd ~/zephyrproject/zephyr/samples/basic/blinky
west flash
```
A succesful flash looks like this:
![succes_flash](/images/zephyr-setup/succes-flash.png)
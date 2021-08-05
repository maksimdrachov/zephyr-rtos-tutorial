## Zephyr structure

A Zephyr application directory has the following components:
- **CMakeLists.txt**: your build settings configuration file - this tells west (really a cmake build system under the hood) where to find what it needs to create your firmware. For more advanced projects, it's also used for debug settings, emulation, and other features.
  
```
cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(blinky)

target_sources(app PRIVATE src/main.c)
```
*samples/basic/blinky/CMakeLists.txt*

- **prj.conf**: the Kernel configuration file. For most projects, it tells Zephyr whether to include specific features for use in your application code - if you use GPIO, PWM, or a serial monitor, you’ll need to enable them in this file first. Sometimes also referred to as Kconfig file. There is also something of a [GUI](https://docs.zephyrproject.org/2.4.0/guides/kconfig/menuconfig.html) which is helpful to get started.

![guiconfig](/images/guiconfig.png)

- **src/main.c**: your custom application code - where the magic happens! It’s advisable to put all of your custom source code in a `src/` directory like this so it doesn’t get mixed up with your configuration files.

Once you have succesfully built an application a build folder will appear within your directory. The following files are interesting to take a look at:
- **build/zephyr/zephyr.dts**: CMake uses a devicetree to tailor the build towards your specific architecture/board. A more in-depth discussion of devicetree follows a bit later.
- **build/zephyr/.config**: To check the final Kconfig used for your built. This can be useful to verify if a setting has been set correctly.
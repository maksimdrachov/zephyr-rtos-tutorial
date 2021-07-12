## 4. Examples

I'm using the samples from Zephyr 2.5.0, since that is the latest version of Zephyr that is available on PlatformIO.

To get Zephyr 2.5.0:
```
git clone https://github.com/zephyrproject-rtos/zephyr
git checkout v2.5-branch
```
To check version of Zephyr (for PlatformIO) -> make sure the samples you use are from the same version!
```
cd ~/.platformio/packages/framework-zephyr
mate VERSION
```

### 4.1. Classic Samples

#### 4.1.1. Hello World
Simple example, useful to understand the setup process.
1) Create new project in PlatformIO<br/>
   -> select your platform and Zephyr RTOS
2) Add `prj.conf` to `zephyr` subfolder (even though empty for this example)
3) Add `monitor_speed = 115200` to `platformio.ini` (if you get weird characters in the serial window, probably wrong baud-rate setting here)
4) Copy code to `main.c`
5) 'Build'
6) 'Flash'
7) Open Serial to verify
  
Example output (press reset on your board to see output)
![Example output](images/1_hello_world.png)

> TIP: Sometimes you want to check the Kconfig setup for your specific build. 
> See `<project>/.pio/build/<board>/zephyr/.config` for the final settings.
> ```
> cd .pio/build/nucleo_f756zg/zephyr
> mate .config
> ```


#### 4.1.2. Synchronization Sample
Same setup as previous example

Code has lots of comments so is pretty clear.

Example output:
![Example output](images/2_synchronization.png)

#### 4.1.3. Dining Philosophers
Same setup as previous example. 

There is a header file (`phil_obj_abstract.h`), which should go into the `include` subfolder (instead of `src`).

Example output:
![Example output](images/3_philosophers.png)


### 4.2. Basic Samples

#### 4.2.1. Blinky
Same setup as previous example

Lessons:
- First example that requires to set a Kconfig (see `prj.conf`)
```
CONFIG_GPIO=y
```
- Shows how to set up and use a GPIO pin

Example output: LED should blink at 1 Hz

#### 4.2.2. PWM Blinky
#### 4.2.3. Button
Lessons:
- Shows how to set up an input GPIO pin
- Shows how to set up an interrupt function

Example output:
![button.png](images/4_button.png)
#### 4.2.4. Fade LED
#### 4.2.5. Minimal footprint
1) Copy settings from example Kconfig files to `zephyr/prj.conf`
2) Inspect code using PlatformIO

Lessons:
- Shows how to check footprint

_common.conf_
```
# Drivers and peripherals
CONFIG_I2C=n
CONFIG_WATCHDOG=n
CONFIG_GPIO=n
CONFIG_PINMUX=n
CONFIG_SPI=n
CONFIG_SERIAL=n
CONFIG_FLASH=n

# Power management
CONFIG_PM=n

# Interrupts
CONFIG_DYNAMIC_INTERRUPTS=n
CONFIG_IRQ_OFFLOAD=n

# Memory protection
CONFIG_THREAD_STACK_INFO=n
CONFIG_THREAD_CUSTOM_DATA=n
CONFIG_FPU=n

# Boot
CONFIG_BOOT_BANNER=n
CONFIG_BOOT_DELAY=0

# Console
CONFIG_CONSOLE=n
CONFIG_UART_CONSOLE=n
CONFIG_STDOUT_CONSOLE=n
CONFIG_PRINTK=n
CONFIG_EARLY_CONSOLE=n

# Build
CONFIG_SIZE_OPTIMIZATIONS=y
```

_no-mt.conf_
```
# Single-threaded, no timer support in the kernel
CONFIG_MULTITHREADING=n
CONFIG_KERNEL_MEM_POOL=n
```

_no-timers.conf_
```
# No timer support in the kernel
CONFIG_SYS_CLOCK_EXISTS=n
```

Example output:
_common.conf_
![common.conf](images/5_minimal_common.png)

Example output:
_no-mt.conf_ and _no-timers.conf_
![no-mt.conf](images/6_minimal_no_mt_no_timers.png)

#### 4.2.6. PWM: RGB LED
#### 4.2.7. Servomotor
#### 4.2.8. Basic Thread Example
Lessons:
- First example that shows how to use threads, study this one carefully.

Example output:
![threads.png](images/7_threads.png)

### 4.3. Userspace Samples

#### 4.3.1. Hello World
Lessons:
- Simple example of how to create a thread with a defined stacksize.

Example output:
![userspace_helloworld](images/8_userspace_helloworld.png)

#### 4.3.2. Producer/consumer
```diff
- ERROR BUILDING
```
I suspect my error has something to do with my CMakeLists.txt, since all the problems are caused by missing 'dependencies'.

Since all the next errors have the same fundamental reason, hopefully if someone can help me fix one of them I should be able to resolve the rest. :)
```
cannot open source file "syscalls/sample_driver.h" (dependency of "sample_driver.h")
```
![9_producer_consumer](images/9_producer_consumer_error.png)

#### 4.3.3. Userspace Protected Memory
```diff
- ERROR BUILDING
```
```
storage size of 'pt_domain' isn't known
storage size of 'enc_domain' isn't known
'enc_part' undeclared (first use in this function); did you mean 'enc_parts'?
identifier "enc_part" is undefined
```
![10_UserProtected](images/10_UserProtectedMemory_erro.png)

#### 4.3.4. Syscall performances
```diff
- ERROR BUILDING
```
```
cannot open source file "syscall_list.h" (dependency of "zephyr.h")
```
![11_Syscall_error](images/11_Syscall_error.png)
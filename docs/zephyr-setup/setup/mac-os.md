## Setup
**1) Install VSCode**

The following extensions are useful to add to VSCode:
- C/C++
- Cortex-Debug
- DeviceTree

Optional: [set terminal color to green](https://stackoverflow.com/questions/42307949/color-theme-for-vs-code-integrated-terminal)

Clone tutorial folder into `~/zephyrproject`
```
cd ~/zephyrproject
git clone https://github.com/maksimdrachov/zephyr-rtos-tutorial

```

**2) Install Coolterm**

[Dowload](https://freeware.the-meiers.org/)

Connect your Nucleo board to your computer

Set up serial connection with Nucleo
- Port: usbmodemxxxxx
- Baudrate: 115200

![coolterm-1](/images/zephyr-setup/coolterm-1.png)

Under terminal -> check "Filter ASCII Escape Sequences"

![coolterm-2](/images/zephyr-setup/coolterm-2.png)

`File -> Save`

Save this configuration under `~/dev-tools/coolterm`, since you'll need it often.  (name suggestion: nucleo-f756zg)

**3) Build and Flash basic-sample**
- Open the folder zephyr-rtos-tutorial in VScode

- Open Coolterm with the nucleo-f756zg configuration

- `Terminal -> New Terminal`
```
cd exercises/basic-sample
west build -b nucleo_f756zg
west flash
```

- Verify the serial output:

![coolterm-3](/images/zephyr-setup/coolterm-3.png)



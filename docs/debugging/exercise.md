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

4) the svd file is necessary to be able to read registers from that specific stm processor

*showing the first screen*

*showing the first breakpoint*

## Exercise 2: Print runtime statistics



## Exercise 3: Core dump
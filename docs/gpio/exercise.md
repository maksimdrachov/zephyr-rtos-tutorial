## Blinky
GPIO-output

Make a 1 Hz blinky program (using set or toggle function)

Solution
1) Find led identifier in devicetree for nucleo-f756zg. See `zephyrproject/zephyr/boards/arm/nucleo_f756zg/nucleo_f756zg.dts`
2) Use devicetree defines to get right alias, label, pin, flags
    - DT_ALIAS -> returns devicetree node identifier
    - DT_NODE_HAS_STATUS -> checks node
    - DT_GPIO_LABEL -> fetches label
    - DT_GPIO_PIN -> fetches pin
    - DT_GPIO_FLAGS -> fetches flags
3) device_get_binding
4) gpio_pin_configure
5) gpio_pin_set
6) k_msleep

```
I don't completely understand what `gpios` is for? -> see devicetree it sets some default flags
```

## Button
GPIO-input

Use button to turn LED on or off. (using GPIO read)

Solution:
1) Find button identifier in devicetree for nucleo-f756zg.
2) Check with DT_NODE_HAS_STATUS
3) Get button spec with GPIO_DT_SPEC_GET_OR
4) Get led spec with GPIO_DT_SPEC_GET_OR
5) Configure button as input: gpio_pin_configure_dt
6) Configure LED port as output
7) Match LED with button input
8) Sleep
9) Loop

Solution

## 2 LEDs
Threads + GPIO

Blinky for 2 LED at different frequencies, using different threads.
---
layout: post
title: '4.1 Introduction'
parent: '4. GPIO'
---

# Introduction

In this lesson we'll be covering the way GPIO works in Zephyr. Just the basics:
- set up an input pin
- set up an output pin
- set up an interrupt pin

## GPIO setup

When setting up any GPIO the following basic steps have to be followed:

1) First you need to look up the devicetree binding for the corresponding GPIO (if you don't know what a devicetree is: see section below).

The devicetree for your particular build can be found at `build/zephyr/zephyr.dts` or for each board in `zephyrproject/zephyr/boards`

For example, the red arrow indicates the device binding to toggle the green led.
![devicetree-binding](/images/gpio/devicetree-binding.png)

2) To use the device binding in our main.c file; we need to use the following defines:

- Devicetree node identifier

```
#define LED0_NODE DT_ALIAS(led0) 
```    
Notice how we used `led0` instead of `green_led` here? This is possible due to the following aliases being defined: 

```
aliases {
	led0 = &green_led;
	led1 = &blue_led;
	led2 = &red_led;
	sw0 = &user_button;
};
```

Now we use LED0_NODE to obtain all other (optional) defines:

- Label
    
```
#define LED0    DT_GPIO_LABEL(LED0_NODE, gpios)
```    

- Pin

```
#define PIN	    DT_GPIO_PIN(LED0_NODE, gpios)
```    

- (Default) flags
    
```
#define FLAGS	DT_GPIO_FLAGS(LED0_NODE, gpios)
```    

Optionally, instead of using 'defines', you can use `gpio_dt_spec`: 
    
```
static struct gpio_dt_spec led = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios, {0});

static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});
```

3)  Configure GPIO

- input/output configuration

```c
const struct device *dev;

dev = device_get_binding(LED0);

ret = gpio_pin_configure(dev, PIN, GPIO_INPUT | FLAGS); // For input pin

ret = gpio_pin_configure(dev, PIN, GPIO_OUTPUT | FLAGS); // For output pin
```

- interrupt configuration

```
ret = gpio_pin_interrupt_configure(dev, PIN, GPIO_INT_EDGE_RISING | FLAGS); // For rising edge interrupt
```

Using `gpio_dt_spec`
- input/output configuration

```
ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT);
ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
```

- interrupt configuration

```
gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_RISING);
```
    
4)  Use GPIO through dedicated functions (set, read, toggle,...)

- set 

```c
gpio_pin_set(dev, PIN, led_state);
```

- read

```c
button_state = gpio_pin_get(dev, PIN);
```

- toggle

```c
gpio_pin_toggle(dev, PIN);
```

Using `gpio_dt_spec`

- set

```
int val = gpio_pin_set_dt(&led, val);
```

- read

```
int val = gpio_pin_get_dt(&button);
```

- toggle

```
gpio_pin_toggle_dt(&led);
```


## Devicetree

> A device tree is a data structure describing the hardware components of a particular computer so that the operating system's kernel can use and manage those components, including the CPU or CPUs, the memory, the buses and the peripherals. [Wikipedia](https://en.wikipedia.org/wiki/Devicetree)

In short: the devicetree will help Zephyr locate all the components of your particular SoC/Board and in this way it will be able to work regardless of the underlying hardware. That also means if we want to access anything on the board from within Zephyr, we'll need to know the binding of that particular component in our devicetree. For example, if we want to blink an LED on the board, we'll first have to determine how that LED is called in the devicetree. If you want to learn more about devicetree, I'd recommend watching [this](https://www.youtube.com/watch?v=m_NyYEBxfn8) video, which explains it pretty well. (devicetree is a concept borrowed from Linux)

The devicetree for the dev board (nucleo-f756zg) can be be found at `zephyrproject/zephyr/boards/arm/nucleo_f756zg` and for the microcontroller itself (stm32f756) at `zephyrproject/zephyr/dts/arm/st/f7/stm32f756Xg.dtsi`. If you study the devicetree files, you'll notice that the final devicetree is a combination of multiple files; the way this works is that each successive devicetree file gets laid over the previous one thereby forming a final devicetree (to be found in `build/zephyr/zephyr.dts`) this one should match your particular dev board and microcontroller. 
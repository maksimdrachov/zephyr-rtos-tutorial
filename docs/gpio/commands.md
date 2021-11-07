Useful API pages:
- [GPIO API](https://docs.zephyrproject.org/latest/reference/peripherals/gpio.html#api-reference)
- [Devicetree](https://docs.zephyrproject.org/latest/guides/dts/index.html)
- [Device Driver Model](https://docs.zephyrproject.org/latest/reference/drivers/index.html)

## Functions table
| Function | Description |
| --- | --- |
| gpio_pin_configure | Configure a single pin |
| gpio_pin_interrupt_configure | Configure pin interrupt |
| gpio_pin_get | Get logical level of an input pin - taking into account the GPIO_ACTIVE_LOW flag. If pin is configured as Active High, a low physical level will be interpreted as logical value 0. If pin is configured as Active Low, a low physical level will be interpreted as logical value 1. |
| gpio_pin_set | Set logical level of an output pin taking into account GPIO_ACTIVE_LOW flag. Value 0 sets the pin in logical 0 / inactive state. Any value other than 0 sets the pin in logical 1 / active state. If pin is configured as Active High, the default, setting it in inactive state will force the pin to a low physical level. If pin is configured as Active Low, setting it in inactive state will force the pin to a high physical level. |
| gpio_pin_toggle | Toggle pin level |

Callback functions: (not covered in exercises)
| Function | Description |
| --- | --- |
| gpio_init_callback | Helper to initialize a struct `gpio_callback` properly |
| gpio_add_callback | Add an application callback |
| gpio_remove_callback | Remove an application callback |

Device Driver Model
| Function | Description |
| --- | --- |
| device_get_binding | Retrieve the device structure for a driver by name. Device objects are created via the DEVICE_DEFINE() macro and placed in memory by the linker. If a driver needs to bind to another driver it can use this function to retrieve the device structure of the lower level driver by the name the driver exposes to the system.|

 

## Flags table
Input/Output configuration options:
| Flags | Description
| --- | --- | 
| GPIO_INPUT | Enables pin as input |
| GPIO_OUTPUT | Enables pin as output, no change to the output state |
| GPIO_DISCONNECTED | Disables pin for both input and output.  |
| GPIO_OUTPUT_LOW | Configures GPIO pin as output and initializes it to a low state.  |
| GPIO_OUTPUT_HIGH | Configures GPIO pin as output and initializes it to a high state. |
| GPIO_OUTPUT_INACTIVE | Configures GPIO pin as output and initializes it to a logic 0. |
| GPIO_OUTPUT_ACTIVE | Configures GPIO pin as output and initializes it to a logic 1.  |

GPIO interrupt configuration flags
| Flags | Description |
| --- | --- |
| GPIO_INT_DISABLE | Disables GPIO pin interrupt. |
| GPIO_INT_EDGE_RISING | Configures GPIO interrupt to be triggered on pin rising edge and enables it. |
| GPIO_INT_EDGE_FALLING | Configures GPIO interrupt to be triggered on pin falling edge and enables it. |
| GPIO_INT_EDGE_BOTH | Configures GPIO interrupt to be triggered on pin rising or falling edge and enables it. |
| GPIO_INT_LEVEL_LOW | Configures GPIO interrupt to be triggered on pin physical level low and enables it. |
| GPIO_INT_LEVEL_HIGH | Configures GPIO interrupt to be triggered on pin physical level high and enables it. |
| GPIO_INT_EDGE_TO_INACTIVE | Configures GPIO interrupt to be triggered on pin state change to logical level 0 and enables it. |
| GPIO_INT_EDGE_TO_ACTIVE | Configures GPIO interrupt to be triggered on pin state change to logical level 1 and enables it. |
| GPIO_INT_LEVEL_INACTIVE | Configures GPIO interrupt to be triggered on pin logical level 0 and enables it. |
| GPIO_INT_LEVEL_ACTIVE | Configures GPIO interrupt to be triggered on pin logical level 1 and enables it. |

GPIO pin active level flags
| Flags | Description |
| --- | --- |
| GPIO_ACTIVE_LOW | GPIO pin is active (has logical value ‘1’) in low state.  |
| GPIO_ACTIVE_HIGH | GPIO pin is active (has logical value ‘1’) in high state.  |

Defines
| Flags | Description |
| --- | --- |
| GPIO_INT_DEBOUNCE | Enable GPIO pin debounce |
| GPIO_DT_SPEC_GET_BY_IDX | This returns a static initializer for a `gpio_dt_spec` structure given a devicetree node identifier, a property specifying a GPIO and an index. |

| Flags | Description |
| --- | --- |
| DT_ALIAS | Get a node identifier from /aliases.  |
| DT_GPIO_LABEL | Get a label property from a gpio phandle-array property (at index 0)|
| DT_GPIO_PIN | Get a GPIO specifier’s pin cell (at index 0) |
| DT_GPIO_FLAGS | Get a GPIO specifier’s flags cell (at index 0) |``

Additional flag categories can be found [here](https://docs.zephyrproject.org/latest/reference/peripherals/gpio.html#api-reference):
- GPIO drive strength flags
- GPIO pin drive flags
- GPIO pin bias flags
- GPIO pin voltage flags
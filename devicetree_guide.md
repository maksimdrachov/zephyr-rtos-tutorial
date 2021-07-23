# Devicetree guide

## 1. Introduction

The build system uses devicetree sources and bindings to produce a generated C header. The generated header's contents are abstracted by the `devicetree.h` api (see zephyr/include/devicetree.h). 

![device_tree](images/zephyr_dt_build_flow.png)

## 2. Input and output files

![zephyr_device_tree](images/zephyr_dt_inputs_outputs.png)

There are four types of input and output files:
- sources (.dts)
- includes (.dtsi)
- overlays (.overlay)
- bindings (.yaml)

The devicetree files inside the zephyr directory looks like this:
```
boards/<ARCH>/<BOARD/<BOARD>.dts
dts/common/skeleton.dtsi
dts/<ARCH>/.../<SOC>.dtsi
dts/bindings/.../binding.yaml
```

Generally speaking, every supported board has a `BOARD.dts` file describing its hardware. For example, the reel_board has `zephyr/boards/arm/reel_board/reel_board.dts`

`BOARD.dts` includes one or more `.dtsi` files. These `.dtsi` files describe the CPU or SoC Zephyr runs on. `BOARD.dts` describes the board's specific hardware.

The `zephyr/dts/common` directory contains `skeleton.dtsi`, a minimal include file for defining a complete devicetree. Architecture-specific subdirectories (dts/<ARCH>) contains `.dtsi` files for CPUs or SoCs which extend `skeleton.dtsi`.

The C prepocessor is run on all devicetree files to expand macro references, and includes are generally done with `#include <filename>`.

`BOARD.dts` can be extended or modified using overlays. Overlays are also DTS files; the .overlay extension is just a convention which makes their purpose clear. Overlays adapt the base devicetree for different purposes:

- Zephyr applications can use overlays to enable a peripheral that is disabled by default
- Overlays are also used when defining Shields

The build system automatically picks up .overlay files stored in certain locations. It is also possible to explicitly list the overlays to include, vit the DTC_OVERLAY_FILE CMake variable. See [Set devicetree overlays](https://docs.zephyrproject.org/latest/guides/dts/howtos.html#set-devicetree-overlays) for details.

These output files are created in your application's build directory
- `<build>/zephyr/include/generated/devicetree_unfixed.h` - the generated macros and additional comments describing the devicetree. Included by devicetree.h
- `<build>/zephyr/include/generated/devicetree_fixups.h` - the concatenated contents of any dts_fixup.h files. Included by devicetree.h.
- `<build>/zephyr/zephyr.dts` - the final merged devicetree, this file is output by gen_defines.py as a debugging aid, and is unused otherwise.
- `<build>/zephyr/<BOARD>.dts.pre.tmp` - the preprocessed and concatenated DTS sources and overlays, this is an intermediate output file, which is used to create `zephyr.dts` and `devicetree_unfixed.h`.

## 3. Scripts and tools
The following libraries and scripts, located in scripts/dts, create output files from input files.
- `dtlib.py`: a low-level DTS parsing library
- `edtlib.py`: a library layered on top of dtlib that uses bindings to interpret properties and give a higher-level view of the of the devicetree.
- `gen_defines.py`: a script that uses edtlib to generate C preprocessor macros from the devicetree and binding.







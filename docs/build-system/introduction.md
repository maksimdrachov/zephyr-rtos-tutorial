---
layout: post
title: '13.1 Introduction'
parent: 'Lesson 13: Build System'
---

# Build System

## How does `west` work?

Every time you type `west build` the build process starts.

The first stage is called **configuration** and uses CMake. During configuration, the CMakeLists.txt build scripts are executed. What this means is that the Cmake commands will be read and a list of files (source files, dependencies, external libraries,...) will be compiled to be passed on to your build system. If you configure something wrong in you CMakeLists (for example forget to include an external library), this will show up as an error during the build phase (since it won't be able to find the library once you `#include` it in some file). Important to mention as well: the settings you provide in your Kconfig will also affect which files/libraries get included. This means for example that if you require a TCP/IP stack and forget to turn on CONFIG_NETWORKING, you'll get an error saying that `#include <net/net_if.h>` can't be found. 

The next stage is called the **build** stage. Cmake supports several build systems, but in our case we are only interested in Ninja and Make. Make is the 'old' build system; while Ninja is the newer, more efficient build system. These will execute the build scripts and recompile the application. As a developer we are often less interested in this stage, since it doesn't really affect the way our application works. 

## What is Cmake?

## What is Make?

## What is Ninja?

Once you start to play with multiple libraries, it might be useful to read up on Make, Cmake and Ninja (in that order). See recommended reading below. For more basic applications, it will probably suffice to understand the examples discussed below.

## How does a basic sample work?

A basic example of a CMakeLists.txt (samples/basic/blinky)

```cmake
cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(basic-sample)

target_sources(app PRIVATE src/main.c)
```

- cmake_minimum_required: makes sure that the installed version is above the threshold required to interpret the commands correctly
- find_package: finds and loads settings from an external project. (Your app will be built on top of the external package, which is the base Zephyr project in this case)
- project: sets the name of the project
- target_sources: specifies sources to use when building a target, in the case of most basic sample this is just main.c. `app` is the standard way to import your application into the zephyr build. You can find the way this integrates into your Zephyr build at `zephyrproject/zephyr/cmake/app/boilerplate.cmake`:

![boilerplate](/images/build-system/boilerplate.png)

## How does this work with more complex applications?

(samples/net/sockets/echo_client)

```cmake
cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(sockets_echo_client)

if(CONFIG_MBEDTLS_KEY_EXCHANGE_PSK_ENABLED AND
    (CONFIG_NET_SAMPLE_PSK_HEADER_FILE STREQUAL "dummy_psk.h"))
  add_custom_target(development_psk
    COMMAND ${CMAKE_COMMAND} -E echo "----------------------------------------------------------"
    COMMAND ${CMAKE_COMMAND} -E echo "--- WARNING: Using dummy PSK! Only suitable for        ---"
    COMMAND ${CMAKE_COMMAND} -E echo "--- development. Set NET_SAMPLE_PSK_HEADER_FILE to use ---"
    COMMAND ${CMAKE_COMMAND} -E echo "--- own pre-shared key.                                ---"
    COMMAND ${CMAKE_COMMAND} -E echo "----------------------------------------------------------"
  )
  add_dependencies(app development_psk)
endif()

target_sources(                     app PRIVATE src/echo-client.c)
target_sources_ifdef(CONFIG_NET_UDP app PRIVATE src/udp.c)
target_sources_ifdef(CONFIG_NET_TCP app PRIVATE src/tcp.c)
target_sources_ifdef(CONFIG_NET_VLAN app PRIVATE src/vlan.c)

include(${ZEPHYR_BASE}/samples/net/common/common.cmake)

set(gen_dir ${ZEPHYR_BINARY_DIR}/include/generated/)

generate_inc_file_for_target(
    app
    src/echo-apps-cert.der
    ${gen_dir}/echo-apps-cert.der.inc
    )
```

Let's take a look at the parts that have been added in comparison to the more 'basic' example:

```cmake
if(CONFIG_MBEDTLS_KEY_EXCHANGE_PSK_ENABLED AND
    (CONFIG_NET_SAMPLE_PSK_HEADER_FILE STREQUAL "dummy_psk.h"))
  add_custom_target(development_psk
    COMMAND ${CMAKE_COMMAND} -E echo "----------------------------------------------------------"
    COMMAND ${CMAKE_COMMAND} -E echo "--- WARNING: Using dummy PSK! Only suitable for        ---"
    COMMAND ${CMAKE_COMMAND} -E echo "--- development. Set NET_SAMPLE_PSK_HEADER_FILE to use ---"
    COMMAND ${CMAKE_COMMAND} -E echo "--- own pre-shared key.                                ---"
    COMMAND ${CMAKE_COMMAND} -E echo "----------------------------------------------------------"
  )
  add_dependencies(app development_psk)
endif()
```

- if: the following commands will only be part of the built process if some condition is satisfied. (Here we can see an example how Kconfig can affect your build)
- add_custom_target: Adds a target called "development_psk" to our built system. (where can i find this target?)
- add_dependencies: we want to use development_psk for our application, so we'll need to add it as a dependency.

```cmake
target_sources(                     app PRIVATE src/echo-client.c)
target_sources_ifdef(CONFIG_NET_UDP app PRIVATE src/udp.c)
target_sources_ifdef(CONFIG_NET_TCP app PRIVATE src/tcp.c)
target_sources_ifdef(CONFIG_NET_VLAN app PRIVATE src/vlan.c)
```

- target_sources: adds echo-client.c to our app, in the previous basic sample, this was main.c
- target_sources_ifdef: depending on our Kconfig settings we'll be adding some additional files to our app.

## How to import an external library?

(samples/application_development/external_lib)

```cmake
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(external_lib)

target_sources(app PRIVATE src/main.c)

# The external static library that we are linking with does not know
# how to build for this platform so we export all the flags used in
# this zephyr build to the external build system.
#
# Other external build systems may be self-contained enough that they
# do not need any build information from zephyr. Or they may be
# incompatible with certain zephyr options and need them to be
# filtered out.
zephyr_get_include_directories_for_lang_as_string(       C includes)
zephyr_get_system_include_directories_for_lang_as_string(C system_includes)
zephyr_get_compile_definitions_for_lang_as_string(       C definitions)
zephyr_get_compile_options_for_lang_as_string(           C options)

set(external_project_cflags
  "${includes} ${definitions} ${options} ${system_includes}"
  )

include(ExternalProject)

# Add an external project to be able download and build the third
# party library. In this case downloading is not necessary as it has
# been committed to the repository.
set(mylib_src_dir   ${CMAKE_CURRENT_SOURCE_DIR}/mylib)
set(mylib_build_dir ${CMAKE_CURRENT_BINARY_DIR}/mylib)

set(MYLIB_LIB_DIR     ${mylib_build_dir}/lib)
set(MYLIB_INCLUDE_DIR ${mylib_src_dir}/include)

if(CMAKE_GENERATOR STREQUAL "Unix Makefiles")
# https://www.gnu.org/software/make/manual/html_node/MAKE-Variable.html
set(submake "$(MAKE)")
else() # Obviously no MAKEFLAGS. Let's hope a "make" can be found somewhere.
set(submake "make")
endif()

ExternalProject_Add(
  mylib_project                 # Name for custom target
  PREFIX     ${mylib_build_dir} # Root dir for entire project
  SOURCE_DIR ${mylib_src_dir}
  BINARY_DIR ${mylib_src_dir} # This particular build system is invoked from the root
  CONFIGURE_COMMAND ""    # Skip configuring the project, e.g. with autoconf
  BUILD_COMMAND
  ${submake}
  PREFIX=${mylib_build_dir}
  CC=${CMAKE_C_COMPILER}
  AR=${CMAKE_AR}
  CFLAGS=${external_project_cflags}
  INSTALL_COMMAND ""      # This particular build system has no install command
  BUILD_BYPRODUCTS ${MYLIB_LIB_DIR}/libmylib.a
  )

# Create a wrapper CMake library that our app can link with
add_library(mylib_lib STATIC IMPORTED GLOBAL)
add_dependencies(
  mylib_lib
  mylib_project
  )
set_target_properties(mylib_lib PROPERTIES IMPORTED_LOCATION             ${MYLIB_LIB_DIR}/libmylib.a)
set_target_properties(mylib_lib PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${MYLIB_INCLUDE_DIR})

target_link_libraries(app PUBLIC mylib_lib)

```

## Recommended reading

While reading "GNU Make Manual", keep the following in mind:

> If you are new to make, or are looking for a general introduction, read the first few sections of each chapter, skipping the later sections. In each chapter, the first few sections contain introductory or general information and the later sections contain specialized or technical information. The exception is Chapter 2 [An Introduction to Makefiles], page 3, all of which is introductory.

[GNU Make Manual](https://www.gnu.org/software/make/manual/)

[CMake Cookbook](https://www.packtpub.com/product/cmake-cookbook/9781788470711)

[The Ninja build system](https://ninja-build.org/manual.html)


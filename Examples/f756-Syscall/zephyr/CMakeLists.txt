cmake_minimum_required(VERSION 3.13.1)
include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(f756-Syscall)

set_property(
   SOURCE ../src/test_user.c
   PROPERTY COMPILE_DEFINITIONS
     __ZEPHYR_USER__
)

set_property(
   SOURCE ../src/test_supervisor.c
   PROPERTY COMPILE_DEFINITIONS
     __ZEPHYR_SUPERVISOR__
)

FILE(GLOB app_sources ../src/*.c*)
target_sources(app PRIVATE ${app_sources})

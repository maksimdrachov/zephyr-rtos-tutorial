# Zephyr: Tutorial for Beginners

This repository contains a step-by-step guide that teaches you how to use Zephyr RTOS. It assumes:
- no previous experience with RTOS
- basic embedded electronics knowledge (GPIO, Timers, Interrupt,...)
- knowledge of C

Each lesson builds on the previous one. Most lessons end with exercises (with solutions!) that allow you to test your knowledge to make sure you understand everything that is covered.

This tutorial is under active development, if you want to participate - please read the [Contribution guide](docs/Contributions.md).

A web version of this tutorial can also be found [here](https://maksimdrachov.github.io/zephyr-rtos-tutorial).

## Table of Contents

- [x] **[Introduction](docs/Introduction.md)**
- [x] **[Contribution guide](docs/Contributions.md)**
- [x] **[Prerequisites](docs/Prerequisites.md)**
- [ ] **Lesson 1: Zephyr Setup** 
  - [ ] 1.1 Installation
    - [ ] [MacOS](docs/zephyr-setup/install/mac-os.md)
    - [ ] [Windows](docs/zephyr-setup/install/windows.md)
    - [ ] [Linux](docs/zephyr-setup/install/linux.md)
  - [ ] 1.2 Basic Workspace Setup
    - [ ] [MacOS](docs/zephyr-setup/setup/mac-os.md)
    - [ ] [Windows](docs/zephyr-setup/setup/windows.md)
    - [ ] [Linux](docs/zephyr-setup/setup/linux.md)

- [ ] **Lesson 2: Introduction**
  - [x] 2.1 [RTOS basics](docs/introduction/rtos-basics.md)
  - [x] 2.2 [Zephyr basics](docs/introduction/zephyr-structure.md)
  
- [ ] **Lesson 3: Threads**
  - [x] 3.1 [Introduction](docs/threads/introduction.md)
  - [x] 3.2 [Commands](docs/threads/commands.md)
  - [x] 3.3 [Kconfig](docs/threads/kconfig.md)
  - [x] 3.4 [Exercise](docs/threads/exercise.md)

- [ ] **Lesson 4: GPIO**
  - [ ] 4.1 [Introduction](docs/gpio/introduction.md)
  - [ ] 4.2 [Commands](docs/gpio/commands.md)
  - [ ] 4.3 [Kconfig](docs/gpio/kconfig.md)
  - [ ] 4.4 [Exercise](docs/gpio/exercise.md)
  
- [ ] **Lesson 5: Scheduling**
  - [x] 5.1 [Introduction](docs/scheduling/introduction.md)
  - [x] 5.2 [Commands](docs/scheduling/commands.md)
  - [x] 5.3 [Kconfig](docs/scheduling/kconfig.md)
  - [ ] 5.4 [Exercise](docs/scheduling/exercise.md)

- [ ] **Lesson 6: Debugging**
  - [ ] 6.1 [Introduction](docs/debugging/introduction.md)
  - [ ] 6.2 [Commands](docs/debugging/commands.md)
  - [ ] 6.3 [Kconfig](docs/debugging/kconfig.md)
  - [ ] 6.4 [Exercise](docs/debugging/exercise.md)

- [ ] **Lesson 7: Interrupts** 
  - [ ] 7.1 [Introduction](docs/interrupts/introduction.md)
  - [ ] 7.2 [Commands](docs/interrupts/commands.md)
  - [ ] 7.3 [Kconfig](docs/interrupts/kconfig.md)
  - [ ] 7.4 [Exercise](docs/interrupts/exercise.md)

- [ ] **Lesson 8: Mutexes**
  - [ ] 8.1 [Introduction](docs/lesson08/introduction.md)
  - [ ] 8.2 [Commands](docs/lesson08/commands.md)
  - [ ] 8.3 [Kconfig](docs/lesson08/kconfig.md)
  - [ ] 8.4 [Exercise](docs/lesson08/exercise.md)

- [ ] **Lesson 9: Semaphores**
  - [ ] 9.1 [Introduction](docs/lesson09/introduction.md)
  - [ ] 9.2 [Commands](docs/lesson09/commands.md)
  - [ ] 9.3 [Kconfig](docs/lesson09/kconfig.md)
  - [ ] 9.4 [Exercise](docs/lesson09/exercise.md)

- [ ] **Lesson 10: Logging**
  - [ ] 10.1 [Introduction](docs/logging/introduction.md)
  - [ ] 10.2 [Commands](docs/logging/commands.md)
  - [ ] 10.3 [Kconfig](docs/logging/kconfig.md)
  - [ ] 10.4 [Exercise](docs/logging/exercise.md)

- [ ] **Lesson 11: Networking**
  - [ ] 11.1 [Introduction](docs/networking/introduction.md)
  - [ ] 11.2 [Commands](docs/networking/commands.md)
  - [ ] 11.3 [Kconfig](docs/networking/kconfig.md)
  - [ ] 11.4 [Exercise](docs/networking/exercise.md)

- [ ] **Lesson 12: Timers**
  - [ ] 12.1 [Introduction](docs/timers/introduction.md)
  - [ ] 12.2 [Commands](docs/timers/commands.md)
  - [ ] 12.3 [Kconfig](docs/timers/kconfig.md)
  - [ ] 12.4 [Exercise](docs/timers/exercise.md)

## Useful Links
**General**
- [Zephyr Official Documentation](https://docs.zephyrproject.org/latest/)
- [Introduction to the Zephyr RTOS (video)](https://www.youtube.com/watch?v=jR5E5Kz9A-k)
- [awesome-zephyr](https://github.com/fkromer/awesome-zephyr)

**Youtube**
- [The Linux Foundation](https://www.youtube.com/c/LinuxfoundationOrg/search?query=zephyr)
- [Zephyr Project](https://www.youtube.com/c/ZephyrProject/videos)

## To Do
- [ ] Add next page and prev page links
- [ ] Sort images into lessons
- [ ] Add Support method: "I believe all knowledge should be freely accessible to the benefit of all.
                          If you want to support me in my endavours, here are some ways you can do so:
                            - subscribe to my youtube channel, twitter or bitclout to stay up to date on my latest videos, blogs and projects
                            - donate in your favourite cryptocurrency, see maksimdrachov.github.io/donate"
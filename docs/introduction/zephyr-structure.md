## Zephyr structure

*How to work with Zephyr?* 

Before we start writing our first applications in Zephyr, it might be a good step to take a look at the folder structure that Zephyr provides us.

![sample-folder](/images/introduction/sample-folder.png)

Let's go one-by-one:

### build
This folder appears only once you have build your application and contains the files that get flashed onto the microcontroller. 

The following files are sometimes interesting to take a look at:
- **build/zephyr/zephyr.dts**: CMake uses a devicetree to tailor the build towards your specific architecture/board. This is the final version of that file. If you don't understand what a devicetree is, don't worry we'll cover this in more detail later.
- **build/zephyr/.config**: The final Kconfig used for your built. This can be useful to verify if a setting has been set correctly.

### CMakeLists.txt
This file will be used by [CMake](https://en.wikipedia.org/wiki/CMake) to set up your build, during this tutorial you won't need to change this one.

### prj.conf
This is you Kconfig file. Important! This file will contain any *additional* settings you'll set for your Zephyr configuration. For example if you need TCP/IP, Bluetooth or want to make changes to your scheduler,... We'll explore some of the options throughout this tutorial.

![k-config](/images/introduction/k-config.png)

Right now it's pretty empty, since for the basic-sample we don't need anything "fancy", just the basic Zephyr kernel. We only set CONFIG_PRINTK=y , this will allow us to the printk function to output to the serial (which will be displayed on your computer screen).

If you're ever unsure about what a particular config setting does, you have 2 options:
- Use [google](https://www.google.com/search?client=firefox-b-d&q=zephyr+CONFIG_PRINTK): usually Zephyr Documentation is one of the first links
- Use the guiconfig: in your basic-sample folder execute `west build -t guiconfig`. This will show you a menu of all the possible configuration settings and a small description of what each one does. (Use `Jump to` to find your config)
![guiconfig](/images/introduction/guiconfig.png). 

### src
Where the magic happens! This folder should contain all of your custom application code. For now it should only contain `main.c`.
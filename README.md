# Trinkets

Handy little tools/scripts I use now and then to do tasks which would otherwise be very, **very** tedious.

###### All tools/scripts in this repository are licensed under the Expat (MIT) License.

## buildgcc

Does what it says. This is a user-friendly program which lets you choose how your custom build of [GCC](https://gcc.gnu.org "Click here to go to GCC's official website") will behave, among many other options. I created this program because I attempted building GCC from source manually many moons ago and thought I'd contribute a lot to humanity by providing means of building GCC that don't involve brain and eye torture.

Basically, I do the dirty work, look through GCC manuals for several dozen eyestraining hours, and create the program. You execute it, do what it says, and enjoy your GCC build. A huge improvement to quality of life.

It is written in ANSI C, has only one external dependency (`ncursesw`) and should work on any modern Linux distribution; with some modification, perhaps it can also run on Windows and macOS.

## pisrv

This Shell script runs as soon as my Raspberry Pi starts up. It sets up my Visual Studio Code tunnel which I can access from anywhere in the world. I use code tunnels because then I don't have to set up development environments on every machine I use. Plus, I don't get dragged down by my laptop's terribly slow HDD this way.

You may use the script as well on your own machines. Make it executable and use `crontab -e` then type in `@reboot /path/to/pisrv.sh` to run the script as soon as your machine starts. This script does not need root permissions, in fact VSCode can fail to start if you try it as root.

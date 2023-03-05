# buildgcc

Does what it says. This is a user-friendly program which lets you choose how your custom build of [GCC](https://gcc.gnu.org "Click here to go to GCC's official website") will behave, among many other options. I created this program because I attempted building GCC from source manually many moons ago and thought I'd contribute a lot to humanity by providing means of building GCC that don't involve brain and eye torture.

Basically, I do the dirty work, look through GCC manuals for several dozen eyestraining hours, and create the program. You execute it, do what it says, and enjoy your GCC build. A huge improvement to quality of life.

It is written in ANSI C, has only one external dependency (`ncursesw`) and should work on any modern Linux distribution; with some modification, perhaps it can also run on Windows and macOS.

## How to use buildgcc

1. Clone the repository
2. Run `build.linux.{arch}`, where `{arch}` is the architecture of your computer (run the build-n-run variant of the script if you would like to execute the binary it as soon as it's done building)
3. The binary will be placed in `bin/{arch}/`

###### Licensed under the Expat (MIT) License.

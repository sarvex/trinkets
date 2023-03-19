# buildgcc

Does what it says. This is a user-friendly program which lets you choose how your custom build of [GCC](https://gcc.gnu.org "Click here to go to GCC's official website") will behave, among many other options. I created this program because I attempted building GCC from source manually many moons ago and thought I'd contribute a lot to humanity by providing means of building GCC that don't involve brain and eye torture. This version is designed to build GCC 12.2, and anyone else can add support for other versions if they'd like.

Basically, I do the dirty work, look through GCC manuals for several dozen eyestraining hours, and create the script. You execute it, do what it says, and enjoy your GCC build. A huge improvement to quality of life.

It is written in Bash, has only one *optional* external dependency (`dialog` binary) and should work on any modern Linux distribution; with some modification, perhaps it can also run on Windows and macOS.

**Before you use this program** you need to have some version (preferably 11) of GCC already installed. How will you build GCC  without a compile already presentr? ;)

## How to use buildgcc

1. Clone this branch of the repository with `git clone https://github.com/HackerDaGreat57/trinkets.git --single-branch buildgcc`
2. Make sure you have root permissions and the `dialog` binary is present. The program may or may not work without root permissions, at your own risk. Also make sure you have GCC 11.0 or similar already installed.
3. Run the script. Follow the instructions in the script, and enjoy your GCC build. Report bugs at the [GitHub repository](https://github.com/HackerDaGreat57/trinkets "Click here to go to the repository.").

###### Licensed under the Expat (MIT) License.

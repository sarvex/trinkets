# pisrv

This Shell script runs as soon as my Raspberry Pi starts up. It sets up my Visual Studio Code tunnel which I can access from anywhere in the world. I use code tunnels because then I don't have to set up development environments on every machine I use. Plus, I don't get dragged down by my laptop's terribly slow HDD this way.

You may use the script as well on your own machines. Make it executable and use `crontab -e` then type in `@reboot /path/to/pisrv.sh` to run the script as soon as your machine starts. This script does not need root permissions, in fact VSCode can fail to start if you try it as root.

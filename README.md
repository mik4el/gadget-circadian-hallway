# Circadian Hallway
Control color and intensity of led strips in a hallway to match optimal human circadian rhythm. Arduino and python interface to custom electronics for 200W RGB leds.

# Suggested hardware
Raspi, Arduino Pro Micro 5V/16MHz (but it is a hazzle to program from commandline), RGB leds with common anode and 3 n-channel mosfets rated at ~10A that switch on at 5V, e.g. the STP16NF06 (but a true logic level mosfet would be better). Make sure the electronics can work with high currents and use beefy connectors (e.g. http://www.jst-mfg.com/product/detail_e.php?series=262) etc.

# Fixing the raspi for serial commands over usb
Followed instructions from http://thomasloughlin.com/connect-raspberry-pi-to-arduino-using-the-usb-cable/

1. `sudo nano /boot/cmdline.txt` 
1. delete `console=ttyAMA0,115200 kgdboc=ttyAMA0,115200`
1. `sudo nano /etc/inittab` 
1. comment out `#T0:23:respawn:/sbin/getty -L ttyAMA0 115200 vt100`
1. reboot

# Fixing the raspi to set lights for morning, evening and night mode
Quick and dirty: 

1. Connect the lights and the Arduino and then the Arduino to the raspi.
1. Download the repo on the raspi.
1. Set up crontab to set the different modes with e.g. `python send_serial_command.py --evening` starting at 19.00 etc. 
1. Make sure the raspi updates its time automatically using e.g. NTP.

# Todos
1. Take serial commands from python with color and animation time, animate to that color in the given time.
1. Deploy to raspi using Docker.
1. Put color command in python rather than in arduino, have python command that sets color for circadian rythm depending on time of day.
1. Broadcast state to online service.

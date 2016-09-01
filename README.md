# Circadian Hallway
Control color and intensity of led strips in a hallway to match optimal human circadian rhythm. Arduino and python interface to custom electronics for 200W RGB leds.

# Suggested hardware
Raspi, Arduino Pro Micro (but it is a hazzle to program from commandline), RGB leds with common anode and 3 n-channel mosfets rated at ~10A that switch on at 5V, e.g. the STP16NF06 (but a true logic level mosfet would be better). Make sure the electronics can work with high currents and use beefy connectors (e.g. http://www.jst-mfg.com/product/detail_e.php?series=262) etc.

# Fixing the raspi for serial commands over usb
Followed instructions from http://thomasloughlin.com/connect-raspberry-pi-to-arduino-using-the-usb-cable/

sudo nano /boot/cmdline.txt 
delete: "console=ttyAMA0,115200 kgdboc=ttyAMA0,115200"
sudo nano /etc/inittab 
comment out "#T0:23:respawn:/sbin/getty -L ttyAMA0 115200 vt100"
reboot

# Fixing the raspi to set lights in the evening and morning
Quick and dirty, set it up in crontab.

# Todos
1. Take serial commands from python with color and animation time, animate to that color in the given time.
1. Deploy to raspi using Docker.
1. Put color command in python rather than in arduino, have python command that sets color for circadian rythm depending on time of day.

import serial
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--evening", help="Set evening mode", action="store_true")
parser.add_argument("--morning", help="Set morning mode", action="store_true")
parser.add_argument("--night", help="Set night mode", action="store_true")
args = parser.parse_args()

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser.open()

if args.evening:
	# For evening mode:
	ser.write("255,0,0\n")
if args.morning:
	# For morning mode:
	ser.write("0,0,255\n")
if args.night:
	# For night mode:
	ser.write("0,255,0\n")

ser.close()

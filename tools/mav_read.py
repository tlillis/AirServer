#!/usr/bin/env python2
from pymavlink import mavutil
import serial
import sys
import time
import socket
import select

mav = mavutil.mavlink_connection('/dev/pts/2', baud=57600, dialect="ardupilotmega")

while True:
	msg = mav.recv_match(blocking=True)
        if msg:
        	if msg.get_type() != 'HEARTBEAT':
        		print msg
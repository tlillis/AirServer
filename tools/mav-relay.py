#!/usr/bin/env python
import socket
import serial
import select
from pymavlink import mavutil

source = ('/dev/pts/9', 921600)
bind = ("0.0.0.0", 14553)
dest = [ ("192.168.11.223", 14553) ]

port = '/dev/pts/3'
print("Opening port {0}...".format(port))
output = serial.Serial(port=port)
print("{0} opened".format(port))

udp_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_sock.bind((bind[0],bind[1]))
udp_sock.setblocking(0)
udp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

with serial.Serial(port=source[0], baudrate=source[1], timeout=0) as ser:
	while True:
		readable, writable, exceptional = select.select([ser, udp_sock], [], [], 1)
		if udp_sock in readable:
			msg1 = udp_sock.recv(4096)
			ser.write(msg1)
			output.write(msg1)
			#print("From client: %s" % msg)
		if ser in readable:
			msg = ser.read(4096)
			for d in dest:
				while 1:
					try:
						udp_sock.sendto(msg, (d[0],d[1]))
						break
					except:
						pass
			#print("From serial: %s" % msg)
#!/usr/bin/env python2
from pymavlink import mavutil
import serial
import sys
import time
import socket
import select

#mav = mavutil.mavlink_connection("/dev/ttyUSB0", baud=57600, dialect="ardupilotmega")
#mav = mavutil.mavlink_connection("tcp:192.168.2.1:14550")
mav = mavutil.mavlink_connection("/dev/ttyACM0", baud=115200, dialect="ardupilotmega")
mav2 = mavutil.mavlink_connection("udpout:192.168.11.223:14550","udpin:0.0.0.0:14551")
#mav = mavutil.mavlink_connection("udp:192.168.3.255:14550")

# bind = ("0.0.0.0", 14551)
# dest = [ ("192.168.11.223", 14550) ]

# udp_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# udp_sock.bind((bind[0],bind[1]))
# udp_sock.setblocking(0)
# udp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

print "Connected..."


good=0
bad=0
last_seq=0

#mav.param_fetch_all()

# port = '/tmp/ttyV2'
# print("Opening port {0}...".format(port))
# output = serial.Serial(port=port, baudrate=4800)
# print("{0} opened".format(port))

file_i = open('input.txt','w')
file_o = open('output.txt','w')

while True:
    readable, writable, exceptional = select.select([mav.fd, mav2.fd], [], [], 1)
    if mav.fd in readable:
        msg = mav.recv_match(blocking=False)
        if msg:
            #print msg
            if msg.get_type() != 'BAD_DATA':
                mav2.mav.send(msg)
                file_o.write(str(msg))
                file_o.write("\n")
    if mav2.fd in readable:
        msg = mav2.recv_match(blocking=False)
        if msg:
            #print msg2
            if msg.get_type() != 'BAD_DATA':
                file_i.write(str(msg))
                file_i.write("\n")
                mav.mav.send(msg)
        
    


    # if msg.get_type() == "BAD_DATA":
    #     bad+=1
    #     print msg.get_msgId()
    #     #print("GOT BAD DATA")
    #     #print(dir(msg))
    #     #print(msg._msgbuf)
    # else:
    #     good+=1
    #     print msg.get_type()
    #     if msg.get_type() == "MISSON_REQUEST":
    #         print "GOT MISSION REQUEST"
    #         print msg
    #         print msg.seq
    #     #if msg.get_type() == "HEARTBEAT":
    #     #    print "HEARTBEAT"
    #     #    print msg.get_msgId()
    #     #if msg.get_seq()-last_seq != 1:
    #     #    None
    #     #    print("### SKIPPED ### %i messages, %i/%i" % (msg.get_seq()-last_seq-1,msg.get_seq(),last_seq))
    #     #last_seq = msg.get_seq()
    #     #print(msg.to_json())
    # #print(msg.get_type())
    # #print("Good: %i / Bad: %i" % (good, bad))
    # #mav.set_mode_manual()
    # #print(msg.get_msgId())
    # sys.stdout.flush()

#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  message_checker.py
#
#  Copyright 2015 Tom Lillis <thomas.lillis@gmail.com>
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#
#


######################################################################
# Use:                                                               #
#     Enter JSON message file as first cmd line pararmeter. If you   #
#     want to do all messages in a dir use 'all' as a replacement    #
#     for the filename. To break out early after 500 messages for    #
#     quick use use 'break' as second cmd line parameter.            #
#                                                                    #
######################################################################


import sys
import os
import json

date = None

AER = False
VEC = False
PTH = False
IMU = False
GPS = False
VFR = False

files = []
flights = [[0 for x in range(4)] for x in range(500)] #Can only handle 500 messages at once!!
flight_num = 0

count = 0
line_num = 0

airspeed_max = 0
groundspeed_max = 0

breakout = False
all_msg = False

if len(sys.argv) > 1:
    if sys.argv[1] == "all":
        all_msg = True
if len(sys.argv) > 2:
    if sys.argv[2] == "break":
        breakout = True

if all_msg:
    for filename in os.listdir(os.getcwd()):
        files.append(filename)
else:
    files.append(sys.argv[1])

for filename in files:
    #Reset variables
    count = 0
    line_num = 0

    airspeed_max = 0
    groundspeed_max = 0

    date = None
    AER = False
    VEC = False
    PTH = False
    IMU = False
    GPS = False
    VFR = False

    #Open the file and start parsing
    print "Getting file",filename
    with open(filename) as file:
        for line in file:
            try:
                json_data = json.loads(line)

                #Get date of flight
                if json_data['type'] == "AEROPROBE" and date == None:
                    date = json_data['date']

                #Check to see if airspeed above 8
                if json_data['type'] == "VFR_HUD":
                    VFR = True
                    if airspeed_max < json_data['airspeed']:
                        airspeed_max = json_data['airspeed']
                    if groundspeed_max < json_data['groundspeed']:
                        groundspeed_max = json_data['groundspeed']
                    if breakout:
                        if airspeed_max > 13 and groundspeed_max > 10:
                            print "Airspeed reading indicates flight test"
                            print "Airspeed above threshold: ", json_data['airspeed']
                            if date:
                                print "Date: ", date
                            else:
                                print "Date: Uknown"
                            if AER and VEC and PTH:
                                print "Got every teensy device"
                            else:
                                print "Missing some teensy data:"
                                print "Got VEC: ", VEC
                                print "Got AER: ", AER
                                print "Got PTH: ", PTH
                            break

                #Check to see if message type gotten
                if json_data['type'] == "VECTOR_NAV" and VEC == False:
                    VEC = True
                if json_data['type'] == "AEROPROBE" and AER == False:
                    AER = True
                if json_data['type'] == "NCAR_PTH" and PTH == False:
                    PTH = True
                if json_data['type'] == "RAW_IMU" and IMU == False:
                    IMU = True
                if json_data['type'] == "GPS_RAW_INT" and GPS == False:
                    GPS = True

                #After 500 messages check for messages to see if break is needed
                if breakout:
                    #Teensy
                    if count == 500 and (VEC == False or AER == False or PTH == False):
                        print "Bad data:Teensy"
                        print "Got VEC: ", VEC
                        print "Got AER: ", AER
                        print "Got PTH: ", PTH
                        break
                    #Autopilot
                    if count == 500 and (IMU == False or GPS == False or VFR == False):
                        print "Bad data: Autopilot"
                        print "Got IMU: ", IMU
                        print "Got GPS: ", GPS
                        print "Got VFR: ", VFR
                        break
                count += 1

            except: #unable to parse JSON
                #print "Parse Error"
                print line
                pass

            line_num += 1

    if all_msg == False: #if only reading one message print out data
        print "Finished!"

        print ""
        print ""
        print ""
        print "FINAL REPORT"
        print "Date: ", date
        print ""
        print "TEENSY:"
        print "   Got VEC: ", VEC
        print "   Got AER: ", AER
        print "   Got PTH: ", PTH
        print "AUTOPILOT:"
        print "   Got IMU: ", IMU
        print "   Got GPS: ", GPS
        print "   Got VFR: ", VFR
        print ""
        if VFR:
            print "Max airspeed    : ", airspeed_max
            print "Max groundspeed : ", groundspeed_max
        print ""
        print "Lines in file: ", line_num
        print "Lines read   : ", count

        if line_num:
            print "Percent failed: ", 100-((float(count)/float(line_num))*100)
        print ""

    if airspeed_max > 8 and groundspeed_max > 8:
        flights[flight_num][0] = filename
        flights[flight_num][1] = date
        flights[flight_num][2] = airspeed_max
        flights[flight_num][3] = groundspeed_max
        flight_num += 1

for i in range(0,flight_num):
    print "File: ",flights[i][0]," Date: ",flights[i][1]," AS Max: ",flights[i][2]," GS Max: ",flights[i][3]

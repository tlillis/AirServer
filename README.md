# AirServer
Airserver acts as a bridge between the hardware and network layers. It communicates with the USB microcontroller as well as the aircraft autopilot. It then relays this information to/from the network over TCP and UCP. This network bridge allows functionality (scripts, data collection, processing, etc) to live anywhere on the network, including living on the same device as Airserver. It's intended to enable a flexible UAS architecture.

##POCO

AirServer currently uses [POCO C++ Libraries](http://pocoproject.org/). You'll need to install to run AirServer.

##SITL

SITL is useful for testing the functionality of AirServer. If you run Ubuntu you can use [this](http://www.rcgroups.com/forums/showthread.php?t=2190616) to easily set up SITL. Otherwise, you can follow [these](http://dev.ardupilot.com/wiki/simulation-2/sitl-simulator-software-in-the-loop/setting-up-sitl-on-linux/) instructions to get SITL up and running though this proved difficult in some situations.(I just found [this](http://dev.ardupilot.com/wiki/simulation-2/sitl-simulator-software-in-the-loop/setting-up-sitl-using-vagrant/) and it might be a possiblity) 

To use SITL with AirServer all you need to do is run SITL and start AirServer with the correct configuration in the ini file. Make sure that under autopilot `sitl=1` and `file=/tmp/ttyV0`. AirServer should automatically run a socat script that will link SITL and AirServer. 

##Autobahn

[Autobahn](https://github.com/tavendo/AutobahnPython) was a useful tool for having a websocket echo server to test websocket funtionality. 

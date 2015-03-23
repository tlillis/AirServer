#RECUV Airserver
all: main.cpp
	g++ -Wall -I/usr/local/Poco/include -o AirServer main.cpp serial_port.cpp threads.cpp conversions.cpp initialization.cpp -L/usr/local/Poco/lib -lPocoFoundation -lPocoNet -lPocoUtil -lPocoXML -lpthread
clean:
	$(RM) AirServer
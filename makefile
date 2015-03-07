#RECUV Airserver
all: main.cpp serialdata.cpp
	g++ -Wall -I/usr/local/Poco/include -o AirServer main.cpp serialdata.cpp serial_port.cpp -L/usr/local/Poco/lib -lPocoFoundation -lPocoNet -lPocoUtil -lPocoXML -lpthread
clean:
	$(RM) AirServer

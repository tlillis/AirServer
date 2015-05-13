#RECUV Airserver
CROSS_ARCH := arm-openwrt-linux
NATIVE_CXX := g++
CROSS_CXX := $(CROSS_ARCH)-g++
CXXFLAGS := -Wall
LIBS := -lPocoFoundation -lPocoNet -lPocoUtil -lPocoXML -lpthread
SOURCES := \
	$(wildcard src/*.cpp)
PROGRAM := airserver
IOTEST := iotest
all:
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES) $(LIBS)
cross: 
	$(CROSS_CXX) $(CXXFLAGS) -LARM -o $(PROGRAM) $(SOURCES) $(LIBS)
clean:
	rm -rf *.o $(PROGRAM)

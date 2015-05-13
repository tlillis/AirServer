#RECUV Airserver
CROSS_ARCH := arm-openwrt-linux
NATIVE_CXX := g++
CROSS_CXX := $(CROSS_ARCH)-g++
CXXFLAGS := -Wall
CROSS_DIR := /home/tom/Desktop/OpenWrt-Toolchain-brcm2708-bcm2708_gcc-4.8-linaro_glibc-2.21_eabi.Linux-x86_64/toolchain-arm_arm1176jzf-s+vfp_gcc-4.8-linaro_glibc-2.21_eabi/usr/
LIBS := -lPocoFoundation -lPocoNet -lPocoUtil -lPocoXML -lpthread
SOURCES := \
	$(wildcard src/*.cpp)
PROGRAM := airserver
all:
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES) $(LIBS)
cross: 
	$(CROSS_CXX) $(CXXFLAGS) -I$(CROSS_DIR)/include/ -L$(CROSS_DIR)/lib/ -o $(PROGRAM) $(SOURCES) $(LIBS)
clean:
	rm -rf *.o $(PROGRAM)

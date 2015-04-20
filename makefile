#RECUV Airserver
CXX = g++
CXXFLAGS = -Wall
LIBS = -lPocoFoundation -lPocoNet -lPocoUtil -lPocoXML -lpthread
SOURCES := \
	$(wildcard src/*.cpp)
PROGRAM = airserver
IOTEST = iotest
all:
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES) $(LIBS)
clean:
	rm -rf *.o $(PROGRAM)

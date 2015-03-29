#RECUV Airserver
CXX = g++
CXXFLAGS = -Wall
LIBS = -lPocoFoundation -lPocoNet -lPocoUtil -lPocoXML -lpthread
SOURCES := \
	$(wildcard src/*.cpp)
PROGRAM = airserver
all:
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES) $(LIBS)
	chmod +x sitl.sh
clean:
	rm $(PROGRAM)

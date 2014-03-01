CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		arduino-simulator.o \
			main.o

LIBS =		include/arduino-simulator.h

TARGET =	arduino-simulator.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

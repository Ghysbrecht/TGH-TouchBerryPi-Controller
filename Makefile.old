# The C++ compiler
PREFIX=/home/thomas/rpi-tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-
CC=$(PREFIX)g++

# The compiler flags
CFLAGS=-Wall -c

#
EXECUTABLE=hello

all: $(EXECUTABLE)

$(EXECUTABLE): main.o PiI2C.o PiTouch.o PiLed.o
	$(CC)  main.o PiI2C.o PiTouch.o PiLed.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

PiI2C.o: lib/PiI2C.cpp
	$(CC) $(CFLAGS) lib/PiI2C.cpp

PiTouch.o: lib/PiTouch.cpp
	$(CC) $(CFLAGS) lib/PiTouch.cpp

PiLed.o: lib/PiLed.cpp
	$(CC) $(CFLAGS) lib/PiLed.cpp


clean:
	rm -f *.o $(EXECUTABLE)

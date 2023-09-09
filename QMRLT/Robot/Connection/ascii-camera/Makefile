CC = g++ -std=c++17
CFLAGS  = -g -Wall
RM = rm

OPENCV = `pkg-config --cflags --libs opencv4`
XLIB = `pkg-config --cflags --libs x11`

LIBS = $(OPENCV) $(XLIB)

all: main

main: main.o asciiCamera.o
	$(CC) $(CFLAGS) -o run main.o asciiCamera.o $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< $(LIBS)
	
clean:
	rm *.o run
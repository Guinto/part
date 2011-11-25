#Makefile - Trent Ellingsen
CC=g++
CFLAGS=-Wall -lglut -lGL -lGLU -g -O4
#CFLAGS=-framework OpenGL -framework GLUT
LDFLAGS=

ALL=part

all: $(ALL)

part: Main.o Utilities.o
	$(CC) $(CFLAGS) -o $@ $^

Main.o: src/Main.cpp
	$(CC) $(CFLAGS) -c $<

Utilities.o: src/Utilities.cpp src/Utilities.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf core* *.o *.gch src/*.gch $(ALL)

#Makefile - Trent Ellingsen
CC=g++
CFLAGS=-Wall -lglut -lGL -lGLU -g -O4
#CFLAGS=-framework OpenGL -framework GLUT
LDFLAGS=

ALL=part

all: $(ALL)

part: lib/*.o main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: src/main.cpp src/*.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf core* *.o *.gch src/*.gch $(ALL)

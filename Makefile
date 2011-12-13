#Makefile - Trent Ellingsen
CC=g++
#CFLAGS=-Wall -lglut -lGL -lGLU -g -O4
CFLAGS=-framework OpenGL -framework GLUT
LDFLAGS=

ALL=part

all: $(ALL)

part: Main.o Utilities.o Keyboard.o Mouse.o Window.o Cube.o ObjectCollection.o Scene.o
	$(CC) $(CFLAGS) -o $@ $^

Main.o: src/Main.cpp src/*.h
	$(CC) $(CFLAGS) -c $^

Utilities.o: src/Utilities.cpp src/Utilities.h
	$(CC) $(CFLAGS) -c $^

Keyboard.o: src/Keyboard.cpp src/Keyboard.h
	$(CC) $(CFLAGS) -c $^

Mouse.o: src/Mouse.cpp src/Mouse.h
	$(CC) $(CFLAGS) -c $^

Window.o: src/Window.cpp src/Window.h
	$(CC) $(CFLAGS) -c $^

Cube.o: src/Cube.cpp src/Cube.h
	$(CC) $(CFLAGS) -c $^

ObjectCollection.o: src/ObjectCollection.cpp src/ObjectCollection.h
	$(CC) $(CFLAGS) -c $^

Scene.o: src/Scene.cpp src/Scene.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf core* *.o *.gch src/*.gch $(ALL)

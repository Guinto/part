#Makefile - Trent Ellingsen
CC=g++
#CFLAGS=-Wall -lglut -lGL -lGLU -g -O4
CFLAGS=-framework OpenGL -framework GLUT
LDFLAGS=

ALL=part

all: $(ALL)

part: Main.o Utilities.o Keyboard.o KeyboardState.o Mouse.o Window.o Camera.o Particle.o ParticleSystem.o Object.o ObjectCollection.o Ground.o Scene.o
	$(CC) $(CFLAGS) -o $@ $^

Main.o: src/Main.cpp src/*.h
	$(CC) -c $^

Utilities.o: src/Utilities.cpp src/Utilities.h
	$(CC) -c $^

Keyboard.o: src/Keyboard.cpp src/Keyboard.h 
	$(CC) -c $^

KeyboardState.o: src/KeyboardState.cpp src/KeyboardState.h
	$(CC) -c $^

Mouse.o: src/Mouse.cpp src/Mouse.h
	$(CC) -c $^

Window.o: src/Window.cpp src/Window.h
	$(CC) -c $^

Camera.o: src/Camera.cpp src/Camera.h
	$(CC) -c $^

Particle.o: src/Particle.cpp src/Particle.h
	$(CC) -c $^

ParticleSystem.o: src/ParticleSystem.cpp src/ParticleSystem.h
	$(CC) -c $^

Object.o: src/Object.cpp src/Object.h
	$(CC) -c $^

ObjectCollection.o: src/ObjectCollection.cpp src/ObjectCollection.h
	$(CC) -c $^

Ground.o: src/Ground.cpp src/Ground.h
	$(CC) -c $^

Scene.o: src/Scene.cpp src/Scene.h
	$(CC) -c $^

clean:
	rm -rf core* *.o *.gch src/*.gch $(ALL)

#include "Utilities.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Window.h"
#include "Object.h"
#include "Cube.h"
#include "ObjectCollection.h"

void initializeGlobalVariables();
void initializeGlutSettings(int argc, char **argv);
void enableDepthTestingForRendering3DPolygons();
void registerCallbackFunctions();
void startTheMainLoop();

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);

   ObjectCollection objects;
   objects.add(new Cube());

   glLoadIdentity();
   objects.get(0)->transform();
   objects.get(0)->draw();
 
   glutSwapBuffers();
}

int main(int argc, char** argv) {
   initializeGlobalVariables();
   initializeGlutSettings(argc, argv);
   enableDepthTestingForRendering3DPolygons();
   registerCallbackFunctions();
   startTheMainLoop();
}

void initializeGlobalVariables() {
   initializeMousePosition();
}

void initializeGlutSettings(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(Utilities::getGlobalWidth(), Utilities::getGlobalHeight());
   glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   glutCreateWindow("Particle System");
}

void enableDepthTestingForRendering3DPolygons() {
   glEnable(GL_DEPTH_TEST);
   glClearColor(0.0, 0.0, 0.0, 1.0);
}

void registerCallbackFunctions() {
   glutDisplayFunc(display);
   glutReshapeFunc(reshapeWindow);
   glutMouseFunc(mouseClick);
   glutMotionFunc(mouseMove);
   glutKeyboardFunc(keyboard);
}

void startTheMainLoop() {
   glutMainLoop();
}

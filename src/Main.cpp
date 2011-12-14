#include "Utilities.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Window.h"
#include "Scene.h"

void initializeGlobalVariables();
void initializeGlutSettings(int argc, char **argv);
void enableDepthTestingForRendering3DPolygons();
void registerCallbackFunctions();
void startTheMainLoop();

Scene scene;
long startLoop;

void setupScene() {
   scene.setup();
}

void loop(int n) {
   long oldStartLoop = startLoop;
   startLoop = (long) glutGet(GLUT_ELAPSED_TIME);
   float timeElapsed = (float) (startLoop - oldStartLoop);

   scene.update(timeElapsed);
   
   glutPostRedisplay();
   glutTimerFunc(TIMER_TRIGGER, loop, TIMER_TRIGGER);
}

void display() {
   glFlush();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60, ((float)Utilities::getGlobalWidth()) / 
         Utilities::getGlobalHeight(), 0.05, 2000);

   glMatrixMode(GL_MODELVIEW);
   scene.display();

   glutSwapBuffers();
}

int main(int argc, char** argv) {
   setupScene();
   initializeGlobalVariables();
   initializeGlutSettings(argc, argv);
   enableDepthTestingForRendering3DPolygons();
   registerCallbackFunctions();
   startTheMainLoop();
}

void initializeGlobalVariables() {
   startLoop = 0;
   glutTimerFunc(TIMER_TRIGGER, loop, TIMER_TRIGGER);
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

#include "Utilities.h"

#define WORLD_SIZE_MULT 2

void objectTransforms();
float viewPortWidth(int w);
float viewPortHeight(int h);
float viewPortLowerLeftCornerY();
float viewPortLowerLeftCornerX();
float leftVerticalClippingPlane(int w, int h);
float rightVerticalClippingPlane(int w, int h);
float topHorizontalClippingPlane();
float bottomHorizontalClippingPlane();
float nearDepthClippingPlane();
float farDepthClippingPlane();
void mouse(int button, int buttonState, int x, int y);
int windowYAxisPixelAdjustment(int y);
void mouseMove(int x, int y);
void keyboard(unsigned char key, int x, int y );
void exitProgram();
void resetLocalMatrixToIdentity();
void initializeGlobalVariables();
void initializeGlutSettings(int argc, char **argv);
void enableDepthTestingForRendering3DPolygons();
void registerCallbackFunctions();
void startTheMainLoop();

int startx, starty;


/*an example of a simple data structure to store a 4x4 matrix */
GLfloat objectMatrix[4][4] = {
  {1.0, 0.0, 0.0, 0.0},
  {0.0, 1.0, 0.0, 0.0},
  {0.0, 0.0, 1.0, 0.0},
  {0.0, 0.0, 0.0, 1.0}
};

GLfloat *trackballM = (GLfloat *)objectMatrix;

/*incomplete drawing of a 3d wireframe cube - needs to be completed */
void drawcube() {
  glBegin(GL_LINE_LOOP);
  glColor3f(0.5, 0.5, 0.5); 
  glVertex3f(-0.5, -0.5, -0.5); //v1

  glColor3f(1.0, 0.0, 0.0); //red
  glVertex3f(0.5, -0.5, -0.5); //v2

  glColor3f(1.0, 1.0, 0.0); //r-g
  glVertex3f(0.5, 0.5, -0.5); //v3

  glColor3f(0.0, 1.0, 0.0); //green
  glVertex3f(-0.5, 0.5, -0.5); //v4

  glColor3f(0.0, 1.0, 1.0); //g-b
  glVertex3f(-0.5, 0.5, 0.5); //v5

  glColor3f(0.95, 0.95, 0.95); 
  glVertex3f(0.5, 0.5, 0.5); //v6

  glColor3f(1.0, 0.0, 1.0);
  glVertex3f(0.5, -0.5, 0.5); //v7

  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(-0.5, -0.5, 0.5); //v8
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0); //white
  glVertex3f(-0.5, -0.5, -0.5); //v1
  glColor3f(0.0, 1.0, 0.0); //green
  glVertex3f(-0.5, 0.5, -0.5);  //v4
  glEnd();

}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  objectTransforms();
  drawcube();
 
  glutSwapBuffers();
}

void objectTransforms() {
  glRotatef(-45,  0, 1, 0);
  glRotatef(45, 1, 0, 0);
}

/*note that we have made our world 2ce as big */
void reshapeWindow(int w, int h) {
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(leftVerticalClippingPlane(w, h), rightVerticalClippingPlane(w, h), 
           topHorizontalClippingPlane(), bottomHorizontalClippingPlane(), 
           nearDepthClippingPlane(), farDepthClippingPlane());
   glMatrixMode(GL_MODELVIEW);
   glViewport(viewPortLowerLeftCornerX(), viewPortLowerLeftCornerY(), 
              viewPortWidth(w), viewPortHeight(h));
}

float viewPortWidth(int w) {
   return w;
}

float viewPortHeight(int h) {
   return h;
}

float viewPortLowerLeftCornerY() {
   return 0;
}

float viewPortLowerLeftCornerX() {
   return 0;
}

float leftVerticalClippingPlane(int w, int h) {
   return -WORLD_SIZE_MULT * (float) w / h;
}

float rightVerticalClippingPlane(int w, int h) {
   return (float) WORLD_SIZE_MULT*w / h;
}

float topHorizontalClippingPlane() {
   return -WORLD_SIZE_MULT;
}

float bottomHorizontalClippingPlane() {
   return WORLD_SIZE_MULT;
}

float nearDepthClippingPlane() {
   return -WORLD_SIZE_MULT;
}

float farDepthClippingPlane() {
   return WORLD_SIZE_MULT;
}

void mouse(int button, int buttonState, int x, int y) {
   y = windowYAxisPixelAdjustment(y);
   if (button == GLUT_LEFT_BUTTON && buttonState == GLUT_DOWN) {
      printf("mouse clicked at %d %d\n", x, y);
      startx = x;
      starty = y;
   }
}

int windowYAxisPixelAdjustment(int y) {
   return Utilities::getGlobalWidth() - y - 1;
}

void mouseMove(int x, int y) {
   printf("mouse moved at %d %d\n", x, Utilities::getGlobalWidth() - y - 1);
   //.....
   glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y )
{
   switch( key ) {
   case 'q': case 'Q' :
      exitProgram();
      break;
   case 'r' : case 'R' :
      resetLocalMatrixToIdentity();
      break;
   }
}

void exitProgram() {
   exit( EXIT_SUCCESS );
}

void resetLocalMatrixToIdentity() {
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   glGetFloatv(GL_MODELVIEW_MATRIX, trackballM);
   glPopMatrix();
   glutPostRedisplay();
}

int main(int argc, char** argv) {
   initializeGlobalVariables();
   initializeGlutSettings(argc, argv);
   enableDepthTestingForRendering3DPolygons();
   registerCallbackFunctions();
   startTheMainLoop();
}

void initializeGlobalVariables() {
   startx = starty = 0;
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
   glutMouseFunc(mouse);
   glutMotionFunc(mouseMove);
   glutKeyboardFunc(keyboard);
}

void startTheMainLoop() {
   glutMainLoop();
}

#include "Utilities.h"

int startx, starty;

/*an example of a simple data structure to store a 4x4 matrix */
GLfloat objectM[4][4] = {
  {1.0, 0.0, 0.0, 0.0},
  {0.0, 1.0, 0.0, 0.0},
  {0.0, 0.0, 1.0, 0.0},
  {0.0, 0.0, 0.0, 1.0}
};

GLfloat *trackballM = (GLfloat *)objectM;

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

  //add any transforms
  //delete the two rotation transforms - they are included 
  // just to show that the cube is partial and 3D
  glLoadIdentity();
  glRotatef(-45,  0, 1, 0);
  glRotatef(45, 1, 0, 0);
  drawcube();

  glutSwapBuffers();

}

/*note that we have made our world 2ce as big */
void reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho( -2*(float)w/h, (float)2*w/h, -2, 2, -2, 2); 
  glMatrixMode(GL_MODELVIEW);
  glViewport(0, 0, w, h);

}


void mouse(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) { /* if the left button is clicked */
      printf("mouse clicked at %d %d\n", x, Utilities::getGlobalWidth()-y-1);
      startx = x;
      starty = Utilities::getGlobalWidth()-y-1;
    } 
  }
}

void mouseMove(int x, int y) {
  printf("mouse moved at %d %d\n", x, Utilities::getGlobalWidth()-y-1);
  //.....
  glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y )
{
  switch( key ) {
  case 'q': case 'Q' :
    exit( EXIT_SUCCESS );
    break;
    /*how to reset our local matrix to the identity using the matrix stacks */
  case 'r' : case 'R' :
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glGetFloatv(GL_MODELVIEW_MATRIX, trackballM);
    glPopMatrix();
    glutPostRedisplay();
    break;
  }
}

void initializeGlobalVariables(int argc, char **argv) {
  startx = starty = 0;
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
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(mouseMove);
  glutKeyboardFunc(keyboard);
}

void startTheMainLoop() {
   glutMainLoop();
}

int main(int argc, char** argv) {
  initializeGlobalVariables(argc, argv);
  enableDepthTestingForRendering3DPolygons();
  registerCallbackFunctions();
  startTheMainLoop();
}



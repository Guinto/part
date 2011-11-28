#include "Keyboard.h"

/*an example of a simple data structure to store a 4x4 matrix */
GLfloat objectMatrix[4][4] = {
  {1.0, 0.0, 0.0, 0.0},
  {0.0, 1.0, 0.0, 0.0},
  {0.0, 0.0, 1.0, 0.0},
  {0.0, 0.0, 0.0, 1.0}
};

GLfloat *trackballM = (GLfloat *)objectMatrix;

void keyboard(unsigned char key, int x, int y) {
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

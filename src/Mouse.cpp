#include "Mouse.h"

int startPositionX, startPositionY;

void initializeMousePosition() {
   startPositionX = startPositionY = 0;
}

void mouseClick(int button, int buttonState, int x, int y) {
   y = windowYAxisPixelAdjustment(y);
   if (button == GLUT_LEFT_BUTTON && buttonState == GLUT_DOWN) {
      printf("mouse clicked at %d %d\n", x, y);
      startPositionX = x;
      startPositionY = y;
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

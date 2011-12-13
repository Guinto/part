#include "Window.h"

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

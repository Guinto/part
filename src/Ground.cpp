#include "Ground.h"

#define FLOOR_SIZE 100

void Ground::setPosition(Point3d newPosition) {
   position.x = newPosition.x;
   position.y = newPosition.y;
   position.z = newPosition.z;
}

void Ground::draw() {
   Point3d lineCreator;

   glPushMatrix(); {
      glColor3f(1, 1, 1);
      glBegin(GL_LINES); {
         lineCreator = Point3d(position.x - FLOOR_SIZE / 2, position.y, position.z - FLOOR_SIZE / 2);
         for (unsigned int i = 0; i < FLOOR_SIZE; i++) {
            glVertex3f(lineCreator.x, lineCreator.y, lineCreator.z);
            lineCreator.z += FLOOR_SIZE;
            glVertex3f(lineCreator.x, lineCreator.y, lineCreator.z);
            lineCreator.z -= FLOOR_SIZE;
            lineCreator.x++;
         }
         lineCreator = Point3d(position.x - FLOOR_SIZE / 2, position.y, position.z - FLOOR_SIZE / 2);
         for (unsigned int i = 0; i < FLOOR_SIZE; i++) {
            glVertex3f(lineCreator.x, lineCreator.y, lineCreator.z);
            lineCreator.x += FLOOR_SIZE;
            glVertex3f(lineCreator.x, lineCreator.y, lineCreator.z);
            lineCreator.x -= FLOOR_SIZE;
            lineCreator.z++;
         }
      } glEnd();
   } glPopMatrix();
}

void Ground::update(float timeElapsed) {

}

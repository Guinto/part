#include "Particle.h"

void Particle::setRandomPosition() {
   position.x = Utilities::randomNegOneToOne();
   position.y = Utilities::randomNegOneToOne();
   position.z = Utilities::randomNegOneToOne();
}

void Particle::setRotationAxis(Point3d newRotationAxis) {
   rotationAxis.x = newRotationAxis.x;
   rotationAxis.y = newRotationAxis.y;
   rotationAxis.z = newRotationAxis.z;
}

void Particle::setRotationDegree(float newRotationDegree) {
   rotationDegree = newRotationDegree;
}

void Particle::update(float timeElapsed) {
   rotationDegree++;
}

void Particle::draw() {
   glPushMatrix(); {
      glColor3f(color.red, color.green, color.blue);
      glTranslatef(position.x, position.y, position.z);
      glRotatef(rotationDegree, rotationAxis.x, rotationAxis.y, rotationAxis.z);
      glutSolidCube(0.1);
   } glPopMatrix();
}

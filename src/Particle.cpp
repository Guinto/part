#include "Particle.h"

void Particle::setPosition(Point3d newPosition) {
   position.x = newPosition.x;
   position.y = newPosition.y;
   position.z = newPosition.z;
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
      glTranslatef(position.x, position.y, position.z);
      glRotatef(rotationDegree, rotationAxis.x, rotationAxis.y, rotationAxis.z);
      glutSolidCube(0.1);
   } glPopMatrix();
}

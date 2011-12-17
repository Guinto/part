#include "Particle.h"

float randomizer() {
   return (float) rand() / RAND_MAX * 2 - 1;
}

void Particle::setPosition(Point3d newPosition) {
   position.x = newPosition.x;
   position.y = newPosition.y;
   position.z = newPosition.z;
}

void Particle::setRandomPosition() {
   position.x = randomizer();
   position.y = randomizer();
   position.z = randomizer();
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
      glColor3f(0.4f, 0.4f, 0.6f);
      glTranslatef(position.x, position.y, position.z);
      glRotatef(rotationDegree, rotationAxis.x, rotationAxis.y, rotationAxis.z);
      glutSolidCube(0.1);
   } glPopMatrix();
}

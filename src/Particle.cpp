#include "Particle.h"

Particle::Particle() {
   createColorVariance();
   life.time = DEFAULT_LIFE_TIME;
   life.birthSize = DEFAULT_BIRTH_SIZE;
   life.deathSize = DEFAULT_DEATH_SIZE;
   life.birthColor = Color(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
   life.deathColor = Color(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
   setColor();
   size = life.birthSize;
}

void Particle::createColorVariance() {
   float colorBase = Utilities::randomZeroToOne();
   color = Color(colorBase, colorBase, colorBase);
}

void Particle::setColor() {
   color += life.birthColor;
}

void Particle::update(float dt) {
   timeElapsed = dt;
   interpolateLifeTime();
   interpolateSize();
   interpolateColor();
   interpolateRotation();
}

void Particle::interpolateLifeTime() {
   life.time -= timeElapsed;
}

void Particle::interpolateSize() {
   size -= ((size - life.deathSize) / life.time) * timeElapsed;
}

void Particle::interpolateColor() {
   color -= ((color - life.deathColor) / life.time) * timeElapsed;
}

void Particle::interpolateRotation() {
   rotationDegree++;
}

bool Particle::isDead() {
   return life.time <= 0;
}

void Particle::draw() {
   glPushMatrix(); {
      glColor3f(color.red, color.green, color.blue);
      glTranslatef(position.x, position.y, position.z);
      glRotatef(rotationDegree, rotationAxis.x, rotationAxis.y, rotationAxis.z);
      glutSolidCube(size);
   } glPopMatrix();
}

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

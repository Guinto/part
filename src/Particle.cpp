#include "Particle.h"

Particle::Particle() {
   initializeColor();
   initializeDefaultLifeVariables();
   initializeDefaultSize();
   initializeDefaultPhysics();
}

void Particle::initializeDefaultLifeVariables() {
   life.time = DEFAULT_LIFE_TIME;
   life.birthSize = DEFAULT_BIRTH_SIZE;
   life.deathSize = DEFAULT_DEATH_SIZE;
   life.birthColor = Color(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
   life.deathColor = Color(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
}

void Particle::initializeColor() {
   createColorVariance();
   color += life.birthColor;
}

void Particle::createColorVariance() {
   float colorBase = Utilities::randomZeroToOne();
   color = Color(colorBase, colorBase, colorBase);
}

void Particle::initializeDefaultSize() {
   size = life.birthSize;
}

void Particle::initializeDefaultPhysics() {
   position = Point3d();
   velocity = Point3d(Utilities::randomNegOneToOne(),
                      Utilities::randomNegOneToOne(),
                      Utilities::randomNegOneToOne());
   force = Point3d(-velocity.x, -velocity.y, -velocity.z);
   mass = DEFAULT_MASS;
}

void Particle::update(float timeElapsed) {
   setTimeElapsed(timeElapsed);
   interpolateLifeTime();
   interpolateSize();
   interpolateColor();
   interpolateRotation();
   calculatePhysics();
}

void Particle::setTimeElapsed(float newTimeElapsed) {
   timeElapsed = newTimeElapsed;
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

void Particle::calculatePhysics() {
   calculateAcceleration();
   calculateVelocity();
   calculatePosition();
}

void Particle::calculateAcceleration() {
   acceleration = force / mass;
}

void Particle::calculateVelocity() {
   velocity = velocity + (acceleration * timeElapsed);
}

void Particle::calculatePosition() {
   position = position + (velocity * timeElapsed + acceleration * PHYSICS_POSITION_CONSTANT * timeElapsed * timeElapsed);
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
   rotationAxis = newRotationAxis;
}

void Particle::setRotationDegree(float newRotationDegree) {
   rotationDegree = newRotationDegree;
}

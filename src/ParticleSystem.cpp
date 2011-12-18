#include "ParticleSystem.h"

void ParticleSystem::update(float timeElapsed) {
   Particle *p = new Particle();
   p->setRandomPosition();
   particles.add(p);

   for (unsigned int i = 0; i < particles.size(); i++) {
      particles.get(i)->update(timeElapsed);
   }
}

void ParticleSystem::draw() {
   glPushMatrix(); {
      glTranslatef(position.x, position.y, position.z);
      for (unsigned int i = 0; i < particles.size(); i++) {
         particles.get(i)->draw();
      }
   } glPopMatrix();
}

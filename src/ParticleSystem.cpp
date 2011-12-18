#include "ParticleSystem.h"

void ParticleSystem::update(float timeElapsed) {
   Particle *particle = new Particle();
   particle->setRandomPosition();
   particles.add(particle);

   for (unsigned int i = 0; i < particles.size(); i++) {
      Particle *p = (Particle*) particles.get(i);
      p->update(timeElapsed);
      if (p->isDead()) {
         particles.del(i);
      }
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

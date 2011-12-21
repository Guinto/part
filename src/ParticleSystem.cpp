#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
   initializeParticlesPerSecond();
}

void ParticleSystem::initializeParticlesPerSecond() {
   particlesPerSecond = DEFAULT_PARTICLES_PER_SECOND;
}

void ParticleSystem::update(float timeElapsed) {
   keyboardActions();
   setTimeElapsed(timeElapsed);
   addParticlesToSystem();
   updateParticles();
}

void ParticleSystem::setTimeElapsed(float newTimeElapsed) {
   timeElapsed = newTimeElapsed;
}

void ParticleSystem::addParticlesToSystem() {
   if (particlesPerSecond > timeElapsed) {
      int particlesToAdd = (int)(particlesPerSecond / timeElapsed);
      for (unsigned int i = 0; i < particlesToAdd; i++) {
         particles.add(new Particle());
      }
      particlesPerSecond = 0;
   } else {
      particlesPerSecond += timeElapsed;
   }
}  

void ParticleSystem::updateParticles() {
   for (unsigned int i = 0; i < particles.size(); i++) {
      Particle *p = (Particle*) particles.get(i);
      p->update(timeElapsed);
      if (p->isDead()) {
         particles.erase(i);
      }
   }
}

void ParticleSystem::keyboardActions() {
   if (keyboardState.get('x')) {
      position.x += 0.1f;
   }
   if (keyboardState.get('X')) {
      position.x -= 0.1f;
   }
   if (keyboardState.get('y')) {
      position.y += 0.1f;
   }
   if (keyboardState.get('Y')) {
      position.y -= 0.1f;
   }
   if (keyboardState.get('z')) {
      position.z += 0.1f;
   }
   if (keyboardState.get('Z')) {
      position.z -= 0.1f;
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

void ParticleSystem::setKeyboardState(KeyboardState newKeyboardState) {
   keyboardState = newKeyboardState;
}

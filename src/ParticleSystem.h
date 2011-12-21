#ifndef _PARTICLE_SYSTEM_H_
#define _PARTICLE_SYSTEM_H_

#include "KeyboardState.h"
#include "Particle.h"
#include "ObjectCollection.h"

#define DEFAULT_PARTICLES_PER_SECOND 84

class ParticleSystem: public Object {
   private:
      ObjectCollection particles;
      float particlesPerSecond;
      float timeElapsed;
      KeyboardState keyboardState;

      void setTimeElapsed(float newTimeElapsed);
      void initializeParticlesPerSecond();
      void addParticlesToSystem();
      void updateParticles();
      void keyboardActions();

   public:
      ParticleSystem();
      void draw();
      void update(float timeElapsed);
      void setKeyboardState(KeyboardState newKeyboardState);
};

#endif

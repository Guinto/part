#ifndef _PARTICLE_SYSTEM_H_
#define _PARTICLE_SYSTEM_H_

#include "Particle.h"
#include "ObjectCollection.h"

class ParticleSystem: public Object {
   public:
      ParticleSystem() {
         particles.add(new Particle());
      }
      void draw();
      void update(float timeElapsed);

      ObjectCollection particles;
};

#endif

#ifndef _PARTICLE_SYSTEM_H_
#define _PARTICLE_SYSTEM_H_

#include "Particle.h"
#include "ObjectCollection.h"

class ParticleSystem: public Object {
   private:
      Point3d position;

   public:
      ParticleSystem() {
         position = Point3d();
         particles.add(new Particle());
      }
      void draw();
      void update(float timeElapsed);
      void setPosition(Point3d newPosition);

      ObjectCollection particles;
};

#endif

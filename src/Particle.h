#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "Object.h"
#include "Point3d.h"
#include "Color.h"

#define LIFE_TIME 2000

typedef struct Life {
   float time;
} Life;

class Particle: public Object {
   private:
      Point3d rotationAxis;
      float rotationDegree;
      Color color;
      Life life;

   public:
      Particle();
      void draw();
      void update(float timeElapsed);
      bool isDead();
      void createColorVariance();
      void setRandomPosition();
      void setRotationAxis(Point3d newRotationAxis);
      void setRotationDegree(float newRotationDegree);
};

#endif

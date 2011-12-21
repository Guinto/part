#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "Object.h"
#include "Point3d.h"
#include "Color.h"

#define DEFAULT_LIFE_TIME 2000
#define DEFAULT_BIRTH_SIZE 0.1f
#define DEFAULT_DEATH_SIZE 0
#define DEFAULT_RED 0
#define DEFAULT_GREEN 0
#define DEFAULT_BLUE 0

typedef struct Life {
   float time;
   float birthSize;
   float deathSize;
   Color birthColor;
   Color deathColor;
} Life;

class Particle: public Object {
   private:
      float timeElapsed;
      Point3d rotationAxis;
      float rotationDegree;
      float size;
      Color color;
      Life life;

      void createColorVariance();
      void setColor();
      void interpolateLifeTime();
      void interpolateSize();
      void interpolateColor();
      void interpolateRotation();


   public:
      Particle();
      void draw();
      void update(float timeElapsed);
      bool isDead();
      void setRandomPosition();
      void setRotationAxis(Point3d newRotationAxis);
      void setRotationDegree(float newRotationDegree);
};

#endif

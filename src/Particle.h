#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "Object.h"
#include "Point3d.h"
#include "Color.h"

class Particle: public Object {
   private:
      Point3d rotationAxis;
      float rotationDegree;
      Color color;

   public:
      Particle() {
         rotationAxis = Point3d();
         rotationDegree = 0;
         color = Color(1, 1, 1);
      }
      void draw();
      void update(float timeElapsed);
      void setRandomPosition();
      void setRotationAxis(Point3d newRotationAxis);
      void setRotationDegree(float newRotationDegree);
};

#endif

#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "Object.h"
#include "Point3d.h"

class Particle: public Object {
   private:
      Point3d position;
      Point3d rotationAxis;
      float rotationDegree;

   public:
      Particle() {
         position = Point3d();
         rotationAxis = Point3d();
         rotationDegree = 0;
      }
      void draw();
      void update(float timeElapsed);
      void setPosition(Point3d newPosition);
      void setRotationAxis(Point3d newRotationAxis);
      void setRotationDegree(float newRotationDegree);
};

#endif

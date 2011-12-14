#ifndef _CUBE_H_
#define _CUBE_H_

#include "Object.h"
#include "Point3d.h"

class Cube: public Object {
   public:
      Cube() {
         rotationDegrees = 0;
         position = Point3d();
      }
      void transform();
      void draw();
      void update(float timeElapsed);
      void setPosition(Point3d newPosition);

      float rotationDegrees;
      Point3d position;
};

#endif

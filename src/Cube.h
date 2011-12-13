#ifndef _CUBE_H_
#define _CUBE_H_

#include "Object.h"

class Cube: public Object {
   public:
      Cube() {
         rotationDegrees = 0;
      }
      void transform();
      void draw();
      void update(float timeElapsed);

      float rotationDegrees;
};

#endif

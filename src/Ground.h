#ifndef _GROUND_H_
#define _GROUND_H_

#include "Object.h"
#include "Point3d.h"

class Ground: public Object {
   private:
      Point3d position;

   public:
      Ground() {
         position = Point3d(0, -5, 0);
      }
      void draw();
      void update(float timeElapsed);
      void setPosition(Point3d newPosition);
};

#endif

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Utilities.h"

class Object {
   public:
      int id;
      virtual ~Object() {}
      virtual void transform() = 0;
      virtual void draw() = 0;
};

#endif

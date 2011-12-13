#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include "Object.h"
#include <vector>


class ObjectCollection {
   public:
      std::vector<Object*> collection;
      void add(Object *o); 
      int size();
      Object* get(int x);
};

#endif

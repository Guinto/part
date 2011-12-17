#ifndef _SCENE_H_
#define _SCENE_H_

#include "ParticleSystem.h"
#include "ObjectCollection.h"

class Scene {
   public:
      ~Scene() {}
      void setup();
      void display();
      void update(float timeElapsed);

      ObjectCollection objects;
};

#endif

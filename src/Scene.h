#ifndef _SCENE_H_
#define _SCENE_H_

#include "ParticleSystem.h"
#include "ObjectCollection.h"
#include "Ground.h"
#include "Camera.h"

class Scene {
   public:
      ~Scene() {}
      void setup();
      void display();
      void update(float timeElapsed);

      ObjectCollection objects;
      Camera camera;
      Ground ground;
};

#endif

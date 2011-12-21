#ifndef _SCENE_H_
#define _SCENE_H_

#include "ParticleSystem.h"
#include "ObjectCollection.h"
#include "Ground.h"
#include "Camera.h"

class Scene {
   private:
      KeyboardState keyboardState;
      ObjectCollection objects;
      Camera camera;
      Ground ground;

      void updateKeyboardStateInObjects();

   public:
      void setup();
      void draw();
      void update(float timeElapsed);
      void setKeyboardState(KeyboardState newKeyboardState);
};

#endif

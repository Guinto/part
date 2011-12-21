#include "Scene.h"

void Scene::draw() {
   camera.updateLookAt();
   glPushMatrix(); {
      ground.draw();
      for (unsigned int i = 0; i < objects.size(); i++) {
         objects.get(i)->draw();
      }
   } glPopMatrix();
}

void Scene::update(float timeElapsed) {
   updateKeyboardStateInObjects();
   camera.update();
   for (unsigned int i = 0; i < objects.size(); i++) {
      objects.get(i)->update(timeElapsed);
   }
}

void Scene::setKeyboardState(KeyboardState newKeyboardState) {
   keyboardState = newKeyboardState;
}

void Scene::updateKeyboardStateInObjects() {
   for (unsigned int i = 0; i < objects.size(); i++) {
      ParticleSystem *ps = (ParticleSystem*) objects.get(i);
      ps->setKeyboardState(keyboardState);
   }
}

void Scene::setup() {
   objects.add(new ParticleSystem());
}

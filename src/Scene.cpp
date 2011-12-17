#include "Scene.h"

void Scene::display() {
   camera.updateLookAt();
   glPushMatrix(); {
      ground.draw();
      for (unsigned int i = 0; i < objects.size(); i++) {
         objects.get(i)->draw();
      }
   } glPopMatrix();
}

void Scene::update(float timeElapsed) {
   camera.update();
   for (unsigned int i = 0; i < objects.size(); i++) {
      objects.get(i)->update(timeElapsed);
   }
}

void Scene::setup() {
   objects.add(new ParticleSystem());
}

#include "Scene.h"

void Scene::display() {
   glLoadIdentity();
   for (unsigned int i = 0; i < objects.size(); i++) {
      glPushMatrix();
         objects.get(i)->draw();
      glPopMatrix();
   }
}

void Scene::update(float timeElapsed) {
   for (unsigned int i = 0; i < objects.size(); i++) {
      objects.get(i)->update(timeElapsed);
   }
}

void Scene::setup() {
   ParticleSystem *ps = new ParticleSystem();
   ps->setPosition(Point3d(0, 0, -1));
   objects.add(ps);
}

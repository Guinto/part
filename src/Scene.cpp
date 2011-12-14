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
   Particle *p = new Particle();
   p->setRotationAxis(Point3d(1, 1, 0));
   p->setPosition(Point3d(0, 0, -1));
   objects.add(p);
}

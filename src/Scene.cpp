#include "Scene.h"

void Scene::display() {
   glLoadIdentity();
   objects.get(0)->transform();
   objects.get(0)->draw();
}

void Scene::update(float timeElapsed) {
   objects.get(0)->update(timeElapsed);
}

void Scene::setup() {
   objects.add(new Cube());
}


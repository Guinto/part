#include "Cube.h"

void Cube::transform() {
   glTranslatef(position.x, position.y, position.z);
   glRotatef(-45, 1, 0, 0);
   glRotatef(rotationDegrees, 0, 1, 0);
}

void Cube::setPosition(Point3d newPosition) {
   position.x = newPosition.x;
   position.y = newPosition.y;
   position.z = newPosition.z;
}

void Cube::update(float timeElapsed) {
   rotationDegrees += timeElapsed / 20;
}

void Cube::draw() {
  glBegin(GL_LINE_LOOP);
  glColor3f(0.5, 0.5, 0.5); 
  glVertex3f(-0.5, -0.5, -0.5); //v1

  glColor3f(1.0, 0.0, 0.0); //red
  glVertex3f(0.5, -0.5, -0.5); //v2

  glColor3f(1.0, 1.0, 0.0); //r-g
  glVertex3f(0.5, 0.5, -0.5); //v3

  glColor3f(0.0, 1.0, 0.0); //green
  glVertex3f(-0.5, 0.5, -0.5); //v4

  glColor3f(0.0, 1.0, 1.0); //g-b
  glVertex3f(-0.5, 0.5, 0.5); //v5

  glColor3f(0.95, 0.95, 0.95); 
  glVertex3f(0.5, 0.5, 0.5); //v6

  glColor3f(1.0, 0.0, 1.0);
  glVertex3f(0.5, -0.5, 0.5); //v7

  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(-0.5, -0.5, 0.5); //v8
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0); //white
  glVertex3f(-0.5, -0.5, -0.5); //v1
  glColor3f(0.0, 1.0, 0.0); //green
  glVertex3f(-0.5, 0.5, -0.5);  //v4
  glEnd();
}

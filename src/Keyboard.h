#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "Utilities.h"

void keyboard(unsigned char key, int x, int y);
void exitProgram();
void resetLocalMatrixToIdentity();

#endif

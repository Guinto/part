#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "Utilities.h"

void initializeMousePosition();
int windowYAxisPixelAdjustment(int y);
void mouseClick(int button, int buttonState, int x, int y); 
void mouseMove(int x, int y);

#endif

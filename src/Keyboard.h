#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "Utilities.h"
#include "KeyboardState.h"

void updateKeyboardStateInScene();
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void exitProgram();

#endif

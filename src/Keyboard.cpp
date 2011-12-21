#include "Keyboard.h"
#include "Scene.h"

extern Scene scene;
KeyboardState keyboardState;

void updateKeyboardStateInScene() {
   scene.setKeyboardState(keyboardState);
}

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 27:
         exitProgram();
         break;

      default:
         keyboardState.set(key, true);
         break;
   }
}

void keyboardUp(unsigned char key, int x, int y) {
   keyboardState.set(key, false);
}

void exitProgram() {
   exit(EXIT_SUCCESS);
}

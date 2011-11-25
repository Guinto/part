/**
 * Utilities to be used by the entire project.
 */

#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <GL/glut.h>

#endif

#define WINDOW_SIZE 400

class Utilities {
   private:
      int globalWidth;
      int globalHeight;

   Utilities::Utilities() {
      globalWidth = WINDOW_SIZE;
      globalHeight = WINDOW_SIZE;
   }

   public:
      static int setGlobalWidth();
      static int setGlobalHeight();
      static int getGlobalWidth();
      static int getGlobalHeight();
};

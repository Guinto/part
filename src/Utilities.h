/**
 * Utilities to be used by the entire project.
 */

#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#if 0 /* unix */
#include <GL/glut.h>
#endif

#if 1 /* mac */
#include <GLUT/glut.h>
#include <OPENGL/gl.h>
#include <OPENGL/glext.h>
#endif

#if 0 /* pc */
#include <io.h>
#include <fcnt1.h>
#include <glut.h>
#endif

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720
#define TIMER_TRIGGER 10

class Utilities {
   public:
      static int getGlobalWidth();
      static int getGlobalHeight();
};

#endif

#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct Color {
   float red;
   float green;
   float blue;
   Color(): red(0), green(0), blue(0) {};
   Color(float inRed, float inGreen, float inBlue): red(inRed), green(inGreen), blue(inBlue) {};

} Color;

#endif

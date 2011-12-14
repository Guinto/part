#ifndef _POINT3D_H_
#define _POINT3D_H_

typedef struct Point3d {
   float x;
   float y;
   float z;
   Point3d(): x(0), y(0), z(0) {};
   Point3d(float inX, float inY, float inZ): x(inX), y(inY), z(inZ) {};

} Point3d;

#endif
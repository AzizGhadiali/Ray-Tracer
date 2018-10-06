#ifndef RAY_H
#define RAY_H

#include "vector.h"
#include "point.h"

typedef struct {

    Point p;
    Vector d;

} Ray;


Point get_OriginPoint(Ray *r);

Vector get_Direction(Ray *r);

void ray_init(Ray *r);

void ray_set(Ray *r, Point *p, Vector *d);

#endif
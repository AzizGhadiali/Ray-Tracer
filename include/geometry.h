#ifndef geometry_h
#define geometry_h

#include "vector.h"
#include "color.h"

typedef struct {

    Point center;
    double radius;

} Sphere;

Sphere create_sphere(Point center, double radius);

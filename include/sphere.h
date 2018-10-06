#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"
#include "color.h"
#include "ray.h"

typedef struct {

    Vector center;
    double radius;
    Color c;

} Sphere;


void Sphere_init(Sphere *s, Vector *center, double radius, Color *c);

double get_radius(Sphere *l);

Vector get_center(Sphere *l);

Color get_color(Sphere *l);

Vector getNormalAt(Sphere *s, Vector *v);

double findIntersections(Sphere *s, Ray *r);

#endif
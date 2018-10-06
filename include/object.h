#ifndef Object_H
#define Object_H

#include "vector.h"
#include "color.h"

typedef struct {

    Vector center;
    double radius;
    Color c;

} Object;


void Object_init(Object *s, Vector *center, double radius, Color *c);

double get_radius(Object *l);

Vector get_center(Object *l);

Color get_color(Object *l);

#endif
#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"
#include "color.h"

typedef struct {

    Vector p, d;
    Color c;

} Light;


void light_init(Light *l, Vector *p, Vector *d, Color *c);

Vector get_LightPos(Light *l);

Vector get_LightDirection(Light *l);

Color get_LightColor(Light *l);

#endif
#include <stdio.h>

#include "geometry.h"


Sphere create_sphere(Vector center, double radius) {
    Sphere s = { .center = center, .radius = radius };
    return s;
}
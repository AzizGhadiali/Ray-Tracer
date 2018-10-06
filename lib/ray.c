
#include "ray.h"
#include "vector.h"
#include "color.h"
#include "point.h"

Point get_OriginPoint(Ray *r){
	return r->p;
}

Vector get_Direction(Ray *r){
	return r->d;
}

void ray_init(Ray *r){
	point_set3D(&r->p, 0.0, 0.0, 0.0);
	vector_set(&r->d , 0.0, 1.0, 0.0);
}

void ray_set(Ray *r, Point *p, Vector *d){
	point_copy(&r->p, p);
	vector_copy(&r->d, d);
}
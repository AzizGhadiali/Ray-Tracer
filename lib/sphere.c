#include <math.h>
#include "vector.h"
#include "color.h"
#include "sphere.h"

void Sphere_init(Sphere *s, Vector *center, double radius, Color *c){
	vector_copy(&s->center, center);
	s->radius = radius;
	color_copy(&s->c, c);
}

double get_radius(Sphere *l){
	return l->radius;
}

Vector get_center(Sphere *l){
	return l->center;
}

Color get_color(Sphere *l){
	return l->c;
}

Vector getNormalAt(Sphere *s, Vector *v){
	Vector center_norm; 
	Vector normal;

	vector_copy(&center_norm, &(s->center));
	vector_negate(&center_norm);
	vector_add(&normal, v, &center_norm);
	vector_normalize(&normal);
	return normal;

}

double findIntersections(Sphere *s, Ray *r){
	Vector V;

	vector_subtract(&V, &s->center, &r->p);

	float b = vector_dot(&r->d, &V);

	float b2 = b*b;
	float c = vector_dot(&V, &V)-(s->radius * s->radius);
	float f = b2 - c;

	if (f < 0.0){
		return -1.0;
	}

	float o = sqrt(f);

	float t0 = -b + o;
	float t1 = -b - o;
	
	if (t0 > t1){
		float temp = t0;
		t0 = t1;
		t1 = temp;
	}

	if (t0 < 0){
		t0 = t1;
		if (t0 < 0){ return -1.0;}
	}

	// printf("%f\n", t0);
	return t0;
}

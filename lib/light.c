#include "light.h"
#include "color.h"

void light_init(Light *l, Vector *p, Vector *d, Color *c){
	vector_copy(&l->p, p);
	vector_copy(&l->d, d);
	color_copy(&l->c, c);
}

Vector get_LightPos(Light *l){
	return l->p;
}

Vector get_LightDirection(Light *l){
	return l->d;
}

Color get_LightColor(Light *l){
	return l->c;
}
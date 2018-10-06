#include "viewer.h"
#include "vector.h"

Vector getPos(Viewer *v){
	return v->pos;
}

Vector getDir(Viewer *v){
	return v->dir;
}
Vector getUp(Viewer *v){
	return v->up;
}
Vector getSide(Viewer *v){
	return v->side;
}
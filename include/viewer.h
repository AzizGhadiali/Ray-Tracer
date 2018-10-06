// Aziz Ghadiali, Project 5, 2/18/18
// vector header file

#ifndef VIEWER_H
#define VIEWER_H

#include "vector.h"


// define vector structure
typedef struct {
	
	Vector pos, dir, up, side;

} Viewer;

Vector getPos(Viewer *v);

Vector getDir(Viewer *v);

Vector getUp(Viewer *v);

Vector getSide(Viewer *v);


#endif

// Aziz Ghadiali & Brit Biddle, Project 3, 2/18/18
// point header file

#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>


// define point structure
typedef struct {
// 	values are x, y, z, and the homogeneous coordinate
	double val[4];

} Point;


// Point Prototypes

// set the first two values of the vector to x and y. Set the third value to 0.0 and the fourth value to 1.0
void point_set2D(Point *p, double x, double y);

// set the point’s values to x and y and z. Set the homogeneous coordinate to 1.0
void point_set3D(Point *p, double x, double y, double z);

// set the four values of the vector to x, y, z, and h, respectively
void point_set(Point *p, double x, double y, double z, double h);

// normalize the x and y values of a point by its homogeneous coordinate: x = x/h, y = y/h
void point_normalize(Point *p);

// copy the point data structure
void point_copy(Point *to, Point *from);


#endif
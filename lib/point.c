/*
  Aziz Ghadiali & Brit Biddle
  point.c
  February 22, 2018
  contains all functions for points
  
*/

//include
#include <stdio.h>
#include <stdlib.h>

#include "point.h"

// set the first two values of the vector to x and y. Set the third value to 0.0 and the fourth value to 1.0
void point_set2D(Point *p, double x, double y){
	p->val[0] = x;
	p->val[1] = y;
	p->val[2] = 0.0;
	p->val[3] = 1.0;
}
	
// set the point’s values to x and y and z. Set the homogeneous coordinate to 1.0
void point_set3D(Point *p, double x, double y, double z){
	p->val[0] = x;
	p->val[1] = y;
	p->val[2] = z;
	p->val[3] = 1.0;
}

// set the four values of the vector to x, y, z, and h, respectively
void point_set(Point *p, double x, double y, double z, double h){
	p->val[0] = x;
	p->val[1] = y;
	p->val[2] = z;
	p->val[3] = h;
}

// normalize the x and y values of a point by its homogeneous coordinate: x = x/h, y = y/h
void point_normalize(Point *p){
	double h = p->val[3];
	double x = p->val[0];
	double y = p->val[1];
	
	p->val[0] = x/h;
	p->val[1] = y/h;
}
	
// copy the point data structure
void point_copy(Point *to, Point *from){
	to->val[0] = from->val[0];
	to->val[1] = from->val[1];
	to->val[2] = from->val[2];
	to->val[3] = from->val[3];
}




	
	
	






// Aziz Ghadiali, Project 5, 2/18/18
// vector header file

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

// define vector structure
typedef struct {
// 	values are x, y, z
	double val[4];

} Vector;

// Set the Vector to (x, y, z, 0.0)
void vector_set(Vector *v, double x, double y, double z);

//Copy the src Vector into the dest Vector
void vector_copy(Vector *dest, Vector *src);

// Returns the Euclidean length of the vector, assuming the homogeneous coordinate is 1.0.
double vector_length(Vector *v);

// Normalize the Vector to unit length. Do not modify the homogeneous coordinate.
void vector_normalize(Vector *v);

// Returns the scalar product of ~a and ~b.
double vector_dot(Vector *a, Vector *b);

double vector_getX(Vector *v);

double vector_getY(Vector *v);

double vector_getZ(Vector *v);

void vector_multiplyscalar(Vector *v, double a);

void vector_negate(Vector *v);

void vector_add(Vector *result, Vector *v1, Vector *v2);

void vector_print(Vector *v, FILE *fp);

// Calculates the the cross product (vector product) of ~a and ~b and puts the result in ~c.
void vector_cross(Vector *a, Vector *b, Vector *c);

void vector_subtract(Vector *result, Vector *v1, Vector *v2);

#endif

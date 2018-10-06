/*
  Aziz Ghadiali
  RayTracer.c
  October 3, 2018
  
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "point.h"
#include "ppmIO.h"
#include "image.h"
#include "vector.h"
#include "view3D.h"
#include "light.h"
#include "color.h"
#include "sphere.h"
#include "ray.h"

int main(int argc, char *argv[]){
	Image *src;
	int i,j, curPix;
	int rows = 360;
  	int cols = 640;
	Vector light_pos, light_dir;
	Vector u, v, w, pos, vrp, axisup;
	double intersection;
	Color light_color, sphere_color;
	Light l;
	Sphere s;
	Ray origin;
	Point view_ray_origin;
	Vector view_ray_dir;
	Vector sphere_center;
	double sphere_radius = 1.0;
	double aspect = (double)cols/(double)rows;
	double x, y;
	src = image_create(rows, cols);

	// Setup Viewer
	vector_set(&vrp, 0.0, 0.0, -3.0);
	vector_set(&pos, 0.0, 0.0, 0.0);
	vector_set(&w, (vector_getX(&pos)-vector_getX(&vrp)), (vector_getY(&pos)-vector_getY(&vrp)), (vector_getZ(&pos)-vector_getZ(&vrp))); //direction vector
	vector_negate(&w);
	vector_normalize(&w);
	// vector_print(&w, stdout);	
	vector_set(&axisup, 0.0, 1.0, 0.0);  
  	vector_cross(&axisup, &w, &v); //right left vector 
  	vector_cross(&w, &v, &u); //up down vector

	
	vector_print(&u, stdout);
  	vector_print(&v, stdout);
  	vector_print(&w, stdout);
  	


// Set up ray from camera
	point_set3D(&view_ray_origin, 0.0, 0.0, 0.0); //same as VPN
	vector_copy(&view_ray_dir, &w); // same as VRP

// Setup the light 
	// vector_set(&(light_pos), 7, 10, -10);
 //  	vector_set(&(light_dir), 1.0, 0.0, 0.0);
 //  	color_set(&light_color, 1.0,1.0,1.0);
	// light_init(&l, &light_pos, &light_dir, &light_color);

// Setup sphere
	vector_set(&(sphere_center), 0.0, 0.0, -3.0);
	color_set(&sphere_color, 0.3,.5,0.2);
	Sphere_init(&s, &sphere_center, sphere_radius, &sphere_color);

	

	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			curPix = j*cols + i;

			// vector_set(&view_ray_dir, x, y, -3);
			// vector_normalize(&view_ray_dir);
			Vector tmp1;
			float fov = 90;
			float imageAspectRatio = cols / (float)rows; // assuming width > height 
			float Px = (2 * ((j + 0.5) / cols) - 1) * tan(fov / 2 * M_PI / 180) * imageAspectRatio; 
			float Py = (1 - 2 * ((i + 0.5) / rows) * tan(fov / 2 * M_PI / 180)); 
			vector_set(&tmp1, Px, Py, -1);

			vector_subtract(&view_ray_dir, &tmp1, &view_ray_origin);
			vector_normalize(&view_ray_dir); // it's a direction so don't forget to normalize 
			
			vector_print(&view_ray_dir, stdout);
			ray_set(&origin, &view_ray_origin, &view_ray_dir);
			intersection = findIntersections(&s, &origin);

						
			if (intersection > 0.0 ){
				image_setc(src, i, j, 0, 1);
			}
			else{
				image_setc(src, i, j, 1, .5);
			}
			
			
		}
	}

	image_write(src, "Raytracer.ppm");
	image_free(src);

	return(0);

}

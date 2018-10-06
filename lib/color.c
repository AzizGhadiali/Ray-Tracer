/*
  Aziz Ghadiali & Brit Biddle
  color.c
  February 22, 2018
  contains all functions for colors
  
*/
//include
#include <stdio.h>
#include <stdlib.h>

#include "color.h"

//  copies the Color data
void color_copy(Color *to, Color *from){
	to->c[0] = from->c[0];
	to->c[1] = from->c[1];
	to->c[2] = from->c[2];
}
	
// sets the Color data
void color_set(Color *to, float r, float g, float b){
	to->c[0] = r;
	to->c[1] = g;
	to->c[2] = b;
}

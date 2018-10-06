// Aziz Ghadiali & Brit Biddle, Project 3, 2/18/18
// color header file


#ifndef COLOR_H
#define COLOR_H

// define color structure
typedef struct {

	float c[3];

} Color;

//  copies the Color data
void color_copy(Color *to, Color *from);

// sets the Color data
void color_set(Color *to, float r, float g, float b);


#endif
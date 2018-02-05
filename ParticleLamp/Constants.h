
///////////////////////////////////////////////////////////////////
// Constants.h
//
//
// This code is under A Creative Commons Attribution/Share-Alike License
// http://creativecommons.org/licenses/by-sa/4.0/
// 2018, Imanol Gomez
///////////////////////////////////////////////////////////////////


//General
#ifndef MAX_FPS
#define MAX_FPS 45
#endif

//Led Pixels
#ifndef PIXELS_X
#define PIXELS_X 8
#endif

#ifndef PIXELS_Y
#define PIXELS_Y 8
#endif

//particle dimensions
// The 'sand' grains exist in an integer coordinate space that's 256X
// the scale of the pixel grid, allowing them to move and interact at
// less than whole-pixel increments.
// 
// 
#ifndef MAX_X
#define MAX_X (PIXELS_X  * 256 - 1) // Maximum X coordinate in grain space
#endif

#ifndef MAX_Y
#define MAX_Y (PIXELS_Y * 256 - 1) // Maximum Y coordinate
#endif

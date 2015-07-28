#ifndef __Pointer__
#define __Pointer__

#include <stdio.h>
#include <math.h>
#include "Rectangle.h"
#include <vector>

class Pointer {
private:
    int x,y;

public:
    Pointer (int xVal,int yVal) {};
	int const getX (void) {return x;}
    int const getY (void) {return y;}

    void const setX (int xVal) {x = xVal;}
    void const setY (int yVal) {y = yVal;}
};

#endif /* defined(__Pointer__) */
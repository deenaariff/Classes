//
//  Rectangle.h
//  SimpleScreen
//
//  Created by Anand Venkataraman on 7/23/15.
//  Copyright (c) 2015 Foothill. All rights reserved.
//

#ifndef __SimpleScreen__Rectangle__
#define __SimpleScreen__Rectangle__

#include <stdio.h>

class Rectangle {
private:
    int topLeftX, topLeftY;
    int width, height;

public:
    Rectangle(int x, int y, int w, int h) : topLeftX(x), topLeftY(y), width(w), height(h) {}
    void getTopLeft(int& x, int& y) const { x = topLeftX; y = topLeftY; }
    void getDimensions(int& w, int& h) const { w = width; h = height; }
};

#endif /* defined(__SimpleScreen__Rectangle__) */

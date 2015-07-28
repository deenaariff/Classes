//
//  Rectangle.cpp
//  Screen
//
//  Created by Deen Aariff on 7/23/15.
//  Copyright (c) 2015 Deen Aariff. All rights reserved.
//

#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h);

void Rectangle::getTopLeft(int& x, int& y) {
   topLeftX = x;
   topLeftY = y;
   width = w;
   height = h;
}
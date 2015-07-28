//
//  Rectangle.h
//  Screen
//
//  Created by Deen Aariff on 7/23/15.
//  Copyright (c) 2015 Deen Aariff. All rights reserved.
//

#ifndef __Screen__Rectangle__
#define __Screen__Rectangle__

#include <stdio.h>

#endif /* defined(__Screen__Rectangle__) */

class Rectangle {
private:
   int topLeftX, topLeftY;
   int width, height;

public:
   Rectangle(int x, int y, int w, int h); 
   void getTopLeft(int& topLeftX, int& topLeftY);
   void getDimensions();
   

};

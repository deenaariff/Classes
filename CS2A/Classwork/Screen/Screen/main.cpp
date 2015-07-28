//
//  main.cpp
//  Screen
//
//  Created by Deen Aariff on 7/23/15.
//  Copyright (c) 2015 Deen Aariff. All rights reserved.
//

#include <iostream>
#include "Screen.h"
#include "Rectangle.h"


int main(int argc, const char * argv[]) {
   Screen myScreen;
   Rectangle rect1(10, 10, 20, 40);
   myScreen.draw(rect1);
   myScreen.stroke();
    return 0;
}

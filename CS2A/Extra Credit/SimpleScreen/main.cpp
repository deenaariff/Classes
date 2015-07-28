//
//  main.cpp
//  SimpleScreen
//
//  Created by Anand Venkataraman on 7/23/15.
//  Copyright (c) 2015 Foothill. All rights reserved.
//

#include <iostream>
#include "Screen.h"
#include "Screen.cpp"
#include "Rectangle.h"



int main(int argc, const char * argv[]) {
    Screen myScreen;
    Rectangle rect1(10, 10, 20, 40);

    myScreen.clear();
    myScreen.draw(rect1);
    myScreen.stroke();

    return 0;
}

//
//  main.cpp
//  SimpleScreen
//
//  Created by Anand Venkataraman on 7/23/15.
//  Copyright (c) 2015 Foothill. All rights reserved.
//

#include <iostream>
#include "Screen.h"
#include "Rectangle.h"
#include "Screen.cpp"
#include "Rectangle.cpp"
#include "Pointer.h"
#include "Pointer.cpp"

int main(int argc, const char * argv[]) {
    Screen myScreen;
    Rectangle rect1(10, 10, 20, 40);

    myScreen.clear();
    myScreen.draw(rect1);
    cout << endl;
    myScreen.stroke();

    Pointer point (15,15);
    string confirm =(isInside (point, rect1))? "true\n" : "false\n";
    cout << confirm;

    return 0;
}

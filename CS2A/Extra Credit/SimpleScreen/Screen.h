//
//  Screen.h
//  SimpleScreen
//
//  Created by Anand Venkataraman on 7/23/15.
//  Copyright (c) 2015 Foothill. All rights reserved.
//

#ifndef __SimpleScreen__Screen__
#define __SimpleScreen__Screen__

#include <stdio.h>
#include <iostream>
using namespace std;

#include "Rectangle.h"

const int WIDTH = 80, HEIGHT = 50;
class Screen {
private:
    char screenBuf[WIDTH][HEIGHT];
    char clearChar = ' ';
    char vertLineChar = '|';
    char horizLineChar = '-';
    char cornerChar = '+';

public:
    bool setClearChar(char c) { clearChar = c; return true; }
    bool setVertLineChar(char c) { vertLineChar = c; return true; }
    bool setHorizLineChar(char c) { horizLineChar = c; return true; }
    bool setCornerChar(char c) { cornerChar = c; return true; }
    int setPixel(int x, int y, char c);

    void stroke() const;
    void clear();
    int draw(const Rectangle& rect);
    // int erase(const Rectangle& rect); // Left as homework
};

#endif /* defined(__SimpleScreen__Screen__) */

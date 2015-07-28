//
//  Screen.h
//  Screen
//
//  Created by Deen Aariff on 7/23/15.
//  Copyright (c) 2015 Deen Aariff. All rights reserved.
//

#ifndef __Screen__Screen__
#define __Screen__Screen__

#include <stdio.h>
#include <iostream>
using namespace std;

const int WIDTH = 80, HEIGHT = 50;
class Screen {
private:
   char screenBuf[WIDTH][HEIGHT];
   char clearChar = ' ';
   char vertLineChar = '|';
   char horizLineChar = '-';
   char cornerChar = '+';

public:
   /*
    *Compiler Auto Provides Constructor
    */
   bool setClearChar(char c) { clearChar = c; return true; }
   bool setVertLineChar(char c) { vertLineChar = c; return true; }
   bool setHorizLineChar(char c) { horizLineChar = c; return true; }
   bool setCornerChar(char c) {cornerChar = c; return true;}
   int setPixel (int x , int y, char c);

   void stroke() const;
   void clear();
   int draw(Rectangle rect) const;
   int erase(Rectangle rect) const;
};

#endif /* defined(__Screen__Screen__) */

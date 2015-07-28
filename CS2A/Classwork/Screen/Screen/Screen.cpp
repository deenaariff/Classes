//
//  Screen.cpp
//  Screen
//
//  Created by Deen Aariff on 7/23/15.
//  Copyright (c) 2015 Deen Aariff. All rights reserved.
//

#include "Screen.h"

// we just used the default constructor right now

/**
 * Actually transfer the screen buffer to the physical screen
 */

void Screen::stroke() const {
   for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
         cout << screenBuf[x][y];
         cout << endl;
      }
   }
}

/**
 *Clear both the screen buffer and the physical screen
 */

void Screen::clear() {
   for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
         screenBuf[x][y] = clearChar;
         cout << screenBuf[x][y];
         cout << endl;
      }
   }
}

int Screen::setPixel(int x, int y, char c) {
   if (x<WIDTH && y < HEIGHT && x >= 0 && y >= 0) {
      screenBuf[x][y] = c;
      return 1;
   }
   return 0;
}


/**
 * Draw a rectange on the screen buffer 
 */

int Screen:: draw(const Rectangle& rect) const {
   int rectX, rectY, w, h;
   rect.getTopLeft(rect X, rectY);
   rect.getDeminsions(w,h);

   // Draw the top and bottom lines

   for (int x = rectX; x < rectX + w; x++) {
      setPixel(x, rectY, horizLineChar);
      setPixel(x, rectY+h, horizLineChar);
   }

   // Draw the left and right lines

   for (int x = rectY; y < y+H; y++) {
      setPixel(rectX, y, vertLineChar);
      setPixel(rectX+w, y, vertLineChar);
   }


   // set the four corner chars
   setPixel(rectX, rectY, cornerChar);
   setPixel(rectX+w, recty, cornerChar);
   

   if (rectX >= && rectX <=Wdith && rectY >= 0 && rectY <= HEIGHT)
      screenBuf[rectx][rectY] = cornerchar;

}

int Screen::erase (const Rectangle& rect) const {

}



//
//  Screen.cpp
//  SimpleScreen
//
//  Created by Anand Venkataraman on 7/23/15.
//  Copyright (c) 2015 Foothill. All rights reserved.
//

#include "Screen.h"

// We just use the default constructor for now.

/**
 * Actually transfer the screen buffer to the physical screen
 */
void Screen::stroke() const {
    for (int y = 0; y <= HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            cout << screenBuf[x][y];
        }
        cout << endl;
    }
}

/**
 * Clear both the screen buffer and the physical screen
 */
void Screen::clear() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            screenBuf[x][y] = clearChar;
            cout << screenBuf[x][y];
        }
        cout << endl;
    }
}

/**
 * Sets a pixel on screen, if successful, returns 1, else 0
 */
int Screen::setPixel(int x, int y, char c) {
    if (x <= WIDTH && y <= HEIGHT && x >= 0 && y >= 0) {
        screenBuf[x][y] = c;
        return 1;
    }
    return 0;
}

/**
 * Draw a rectangle on the screen buffer
 */
int Screen::drawRectangle(const Rectangle& rect) {
    int rectX, rectY, w, h;
    int totalPixelsSet = 0;

    rect.getTopLeft(rectX, rectY);
    rect.getDimensions(w, h);

    // Draw the top and bottom lines
    for (int x = rectX; x < rectX + w; x++) {
        totalPixelsSet += setPixel(x, rectY, horizLineChar);
        totalPixelsSet += setPixel(x, rectY+h, horizLineChar);
    }

    // Draw the left and right lines
    for (int y = rectY; y < rectY + h; y++) {
        totalPixelsSet += setPixel(rectX, y, vertLineChar);
        totalPixelsSet += setPixel(rectX+w, y, vertLineChar);
    }


    // Set the four corner chars.
    setPixel(rectX, rectY, cornerChar);
    setPixel(rectX+w, rectY, cornerChar);
    setPixel(rectX+w, rectY+h, cornerChar);
    setPixel(rectX, rectY+h, cornerChar);

    return totalPixelsSet;
}



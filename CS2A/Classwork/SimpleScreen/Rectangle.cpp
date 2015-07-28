#include "Rectangle.h"
#include <math.h>

bool Rectangle::isInside (const Point& p, Rectangle rect) {
	rect.getTopLeft(int topLeftX, int topLeftX);
    rect.getTopLeft(int height, int width);
    double x = p -> x;
    double y = p -> y;

    return ((x > topLeftX && x < topLeftX + width) && (y > topLeftY && y < topLeftY + height)?;
}

bool[] isInside (const Point p [], Rectangle rect, bool inside []) {
	bool truths [p.size()];
	for (int i = 0; i < p.size(); i++) {
		daTruth[i] = isInside(p[i], rect);
	}
	return truths
}



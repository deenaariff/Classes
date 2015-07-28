#include "Rectangle.h"
#include <math.h>
#include <vector>
#include "Pointer.h"
#include "Pointer.cpp"

bool Rectangle::isInside (Pointer& p, Rectangle rect) {
	int tLX, tLY, height, width;
	rect.getTopLeft(tLX, tLY);
    rect.getTopLeft(height, width);
    int x = p.getX();
    int y = p.getY();
    return ((x > tLX && x < tLX + width) && (y > tLX&& y < tLX + height))? true : false;
}

void Rectangle::isInside (vector<Pointer> p, Rectangle rect, bool result []) {
	for (int i = 0; i < p.size(); i++) {
		result[i] = isInside(p[i], rect);
	}

}

bool Rectangle::isOn ( Pointer& p, Rectangle rect) {
	int tLX, tLY, height, width;
	rect.getTopLeft(tLX, tLY);
    rect.getTopLeft(height, width);
    int x = p.getX();
    int y = p.getY();
    return ((x == tLX || x == tLX + width) && (y == tLY || y == tLY + height))? true : false;
}


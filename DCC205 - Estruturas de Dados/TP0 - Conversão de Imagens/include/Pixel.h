#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <string>
#include "memlog.h"
#include "msgassert.h"

using namespace std;

class Pixel 
{
	public:
		int red, green, blue;
		Pixel() : red(0), green(0), blue(0) {}
		Pixel(int r, int g, int b) : red(r), green(g), blue(b) {}
		Pixel(int gray) : red(gray), green(gray), blue(gray) {}
		int getGrayscale();
		int getGray();
};

#endif
#pragma once
#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include <iostream>
#include <vector>
#include <string>

const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	// 수직선을 그을 경우 에러 방지

	if (i0 == i1)
	{
		for (int j = j0; j < j1; j++)
			drawPixel(i0, j, red, green, blue);
		return;
	}

	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawCircle(const int& r, const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	for (int i = i0 - r; i < i0 + r; i++)
	{
		for (int j = j0 - r; j < j0 + r; j++)
		{
			int a = (i - i0) * (i - i0) + (j - j0) * (j - j0) - r * r;
			int b = (i - i0) * (i - i0) + (j - j0) * (j - j0) - (r - 1) * (r - 1) + 2 * r - 1;

			if (a < 0 && b > 0)
				drawPixel(i, j, red, green, blue);
		}
	}
}

void drawSquare(const int& edge, const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i0 + edge, j0, red, green, blue);
	drawLine(i0 + edge, j0, i0 + edge, j0 + edge, red, green, blue);
	drawLine(i0, j0 + edge, i0 + edge, j0 + edge, red, green, blue);
	drawLine(i0, j0, i0, j0 + edge, red, green, blue);
}
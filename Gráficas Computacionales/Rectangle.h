#pragma once  
#include <string>

class Rectangle
{
public:
	Rectangle();
	Rectangle(float w, float h);

	float GetWidth();
	void SetWidth(float w);
	float GetHeight();
	void SetHeight(float h);
	float GetArea();
	float GetPerimeter();

private:
	float _width = 1.0;
	float _height = 1.0;
};
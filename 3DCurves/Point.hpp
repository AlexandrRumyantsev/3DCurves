#pragma once
#include <iostream>
class Point
{
public:
	double x, y, z;
	Point(double, double, double);
};
std::ostream& operator << (std::ostream& os, const Point& point);



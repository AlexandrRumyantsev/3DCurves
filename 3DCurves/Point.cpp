#include "Point.hpp"

Point::Point(double x, double y , double z) : x(x), y(y), z(z) { }

std::ostream& operator<<(std::ostream& os, const Point& point){
	return os  << "(" << trunc(point.x * 100) /100 << "; " << trunc(point.y * 100) / 100 << "; " << trunc(point.z * 100) / 100 << ")";
}

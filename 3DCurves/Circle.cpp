#include "Circle.hpp"
#include <cmath>
#include <stdexcept>

Circle::Circle(double radius) : radius(radius) {
	if (radius <= 0) {
		throw std::invalid_argument("Nonpositive radius");
	}
}

double Circle::getRadius() const{
	return radius;
}

Point Circle::getPoint(double t) const{
	return Point(radius * cos(t), radius * sin(t), 0);
}

Point Circle::getDerivative(double t) const{
	return Point(-radius * sin(t), radius * cos(t), 0);
}

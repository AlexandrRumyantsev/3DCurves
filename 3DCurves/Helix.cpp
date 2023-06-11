#define _USE_MATH_DEFINES
#include "Helix.hpp"
#include <cmath>

Helix::Helix(double radius, double step) : Circle(radius), step(step) { }

Point Helix::getPoint(double t) const{
	return Point(radius * cos(t), radius * sin(t), step * t/ (2* M_PI));
}

Point Helix::getDerivative(double t) const{
	return Point(-radius * sin(t), radius * cos(t), step / (2 * M_PI));
}

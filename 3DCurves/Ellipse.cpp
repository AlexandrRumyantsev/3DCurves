#include "Ellipse.hpp"
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(double xRadius, double yRadius) : xRadius(xRadius), yRadius(yRadius) {
	if (xRadius <= 0 || yRadius <= 0) {
		throw std::invalid_argument("Nonpositive radius");
	}
}

Point Ellipse::getPoint(double t) const{
	return Point(xRadius*cos(t),yRadius*sin(t), 0);
}

Point Ellipse::getDerivative(double t) const{
	return Point(-xRadius*sin(t), yRadius*cos(t), 0);
}

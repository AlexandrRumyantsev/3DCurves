#pragma once
#include "Point.hpp"
class Shape
{
public:
	Shape() = default;
	virtual Point getPoint(double) const = 0;
	virtual Point getDerivative(double) const = 0;
	virtual ~Shape() = default;		
};


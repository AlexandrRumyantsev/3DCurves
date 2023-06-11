#pragma once
#include "Shape.hpp"
class Circle :
    public Shape
{
protected:
    double radius;
public:
    Circle() = delete;
    Circle(double);
    double getRadius() const;
    Point getPoint(double) const override ;
    Point getDerivative(double) const override;
};


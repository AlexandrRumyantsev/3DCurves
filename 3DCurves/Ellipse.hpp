#pragma once
#include "Shape.hpp"
class Ellipse :
    public Shape
{
protected :
    double xRadius, yRadius;
public:
    Ellipse() = delete;
    Ellipse(double, double);
    Point getPoint(double) const override;
    Point getDerivative(double) const override;
};
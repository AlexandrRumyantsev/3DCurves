#pragma once
#include "Circle.hpp"
class Helix :
    public Circle
{
protected:
    double step;
public:
    Helix() = delete;
    Helix(double, double);
    Point getPoint(double t) const override;
    Point getDerivative(double t) const override;
};


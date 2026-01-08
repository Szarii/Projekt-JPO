#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle {
public:
    // parametrized constructor
    Square(double a, const Point &p) : Rectangle(a, a, p, "Square") {}
};
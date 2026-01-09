#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle {
public:
    // parametrized constructor
    Square(double a, const Point &p) : Rectangle(a, a, p, "Square") {}
    Square(const std::array<Point, 4> corners) : Rectangle(corners, "Squere") {
        if(abs(getA() - getB()) > 0.000001){
            throw "This is not a Square";
        }  
    }

    ~Square() = default;

    double area() const override{
        return getA() * getA();
    }

    double perimeter() const override{
        return 4 * getA();
    }

};
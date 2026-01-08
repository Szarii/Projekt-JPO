#pragma once

#include "Figure.hpp"
#include <cmath>

class Circle : public Figure {
    private:
        double m_radius;
    public:
        Circle(double r, const Point &center): m_radius(r), Figure(center, "Circle"){
            setRadius(r);
        }

        double area() const override{
            return M_PI * m_radius * m_radius;
        }

        double perimeter() const override{
            return 2 * M_PI * m_radius;
        }

        void setRadius(const double &r){
            if (r < 0) {
                throw "Radius cannot be less than 0";
            }
            m_radius = r;
        }

        double getRadius() const {
            return m_radius;
        }

};
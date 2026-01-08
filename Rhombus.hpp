#pragma once

#include "Rectangle.hpp"

class Rhombus : public Rectangle {
    private:
        short int m_angle;
    public:
        Rhombus(double a, short int angle, const Point &center) : m_angle(angle), Rectangle(a, a, center, "Rhombus") {
            setAngle(angle);
        }

        double area() const override{
            double alpha = (m_angle*M_PI)/180;
            return  getA() * getA() * sin(alpha);
        }

        double perimeter() const override{
            return 4 * getA();
        }

        void setAngle(int a) {
            if (a <= 0 || a >= 90) {
                throw "alpha must be an acute angle";
            }
            m_angle = a;
        }

        int getAngle() const{
            return m_angle;
        }
};
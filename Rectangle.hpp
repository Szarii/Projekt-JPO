#pragma once

#include "Figure.hpp"
#include <cmath>
#include <array>

class Rectangle : public Figure {
    private:
        double m_sideA;
        double m_sideB;
        std::array<Point, 4> m_corner;
    protected:
        Rectangle(double a, double b, const Point &center, std::string name): m_sideA(a), m_sideB(b), Figure(center, name) {
            setA(a);
            setB(b);

            this->m_corner = { 
                Point(center.getX() - a/2, center.getY() - b/2),
                Point(center.getX() + a/2, center.getY() - b/2),
                Point(center.getX() + a/2, center.getY() + b/2),
                Point(center.getX() - a/2, center.getY() + b/2)
            };
        }

        Rectangle(const std::array<Point, 4>& corners, std::string name) : m_corner(corners), Figure(name) {
            setCorner(corners);
        }
    public:
        Rectangle(double a, double b, const Point &center): Rectangle(a, b, center, "Rectangle") {}

        Rectangle(const std::array<Point, 4>& corners) : m_corner(corners), Figure("Rectangle") {
            setCorner(corners);
        }

        ~Rectangle() = default;

        double area() const override{
            return m_sideA * m_sideB;
        }

        double perimeter() const override{
            return 2 * (m_sideA +  m_sideB);
        }

        void setA(double a) {
            if (a < 0) {
                throw "a cannot be less than 0";
            }
            m_sideA = a;
        }

        void setB(double b) {
            if (b < 0) {
                throw "b cannot be less than 0";
            }
            m_sideB = b;
        }

        void setCorner(const std::array<Point, 4>& corners) {
            int p1 = 0, p2 = -1, p3 = 1, p4 = -1;
            double maxDistance = 0.0;

            for(int i = 0; i < 4; i++){
                for(int j = i + 1; j < 4; j++ ){
                    double dx = corners[i].getX() - corners[j].getX();
                    double dy = corners[i].getY() - corners[j].getY();
                    double distance = dx * dx + dy * dy;

                    if(distance > maxDistance){
                        p1 = i;
                        p3 = j;
                        maxDistance = distance;
                    }
                }
            }

            for(int i = 0; i<4; i++){
                if(i != p1 && i != p3){
                    if(p2 == -1){
                        p2 = i;
                    }
                    else{
                        p4 = i;
                    }
                }
            }

            double xSideA = corners[p1].getX() - corners[p2].getX();
            double ySideA = corners[p1].getY() - corners[p2].getY();
            double sideA = sqrt(xSideA * xSideA + ySideA * ySideA);

            double xSideB = corners[p2].getX() - corners[p3].getX();
            double ySideB = corners[p2].getY() - corners[p3].getY();
            double sideB = sqrt(xSideB * xSideB + ySideB * ySideB);

            const double eps = 0.000001;

            if(abs(sideA * sideA + sideB * sideB - maxDistance) > eps){
                throw " This is not a Rectangle";
            }
            
            if (sideA < eps || sideB < eps){
                throw "Degenerate rectangle";
            }

            m_corner = corners;
            setA(sideA);
            setB(sideB);
        }

        double getA() const {
            return m_sideA;
        }

        double getB() const {
            return m_sideB;
        }

        std::array<Point, 4> getCorner() const{
            return m_corner;
        }

};
#pragma once

#include "Figure.hpp"
#include <cmath>
#include <array>

class Rhombus : public Figure {
    private:
        double m_sideA;
        short int m_angle;
        std::array<Point, 4> m_corner;
    public:
        Rhombus(double a, short int angle, const Point &center) : m_sideA(a), m_angle(angle), Figure(center, "Rhombus") {
            setAngle(angle);
        }

        Rhombus(const std::array<Point,4> corners) : m_corner(corners), Figure("Rhombus") {
            validateCorners();
        }

        ~Rhombus() = default;

        double area() const override{
            double alpha = (m_angle*M_PI)/180;
            return  m_sideA * m_sideA * sin(alpha);
        }

        double perimeter() const override{
            return 4 * m_sideA;
        }
        void setA(double a) {
            if (a < 0) {
                throw "a cannot be less than 0";
            }
            m_sideA = a;
        }

        double getA() const{
            return m_sideA;
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

        void validateCorners() {
            double d[6];
            int k = 0;

            for (int i = 0; i < 4; ++i) {
                for (int j = i + 1; j < 4; ++j) {
                    double dx = m_corner[i].getX() - m_corner[j].getX();
                    double dy = m_corner[i].getY() - m_corner[j].getY();
                    d[k++] = dx * dx + dy * dy;
                }
            }

            const double eps = 1e-6;

            // znajdź najmniejszą dodatnią — bok
            double side2 = 0;
            for (int i = 0; i < 6; ++i) {
                if (d[i] > eps && (side2 == 0 || d[i] < side2)) {
                side2 = d[i];
                }
            }

            if (side2 == 0)
                throw "Degenerate rhombus";

            // sprawdź, czy dokładnie 4 odległości są równe bokowi
            int count = 0;
            for (int i = 0; i < 6; ++i) {
                if (std::abs(d[i] - side2) < eps){
                count++;
                }
            }

            if (count != 4) {
                throw "Points do not form a rhombus";
            }

            // ustaw bok
            m_sideA = std::sqrt(side2);

            // przekątne to 2 największe
            double diag1 = 0, diag2 = 0;
            for (int i = 0; i < 6; ++i) {
                if (d[i] > side2 + eps) {
                    if (diag1 == 0){
                        diag1 = d[i];
                    }
                    else {
                        diag2 = d[i];
                    }
                }
            }

            if (diag1 == 0 || diag2 == 0) {
                throw "Invalid rhombus geometry";
            }

            // cos(alpha) = (d1² + d2² - 4a²) / (2 d1 d2)
            double cosAlpha = (diag1 + diag2 - 4 * side2) / (2 * std::sqrt(diag1 * diag2));

            double alpha = std::acos(cosAlpha) * 180.0 / M_PI;

            if (alpha <= 0 || alpha >= 90){
                throw "Angle must be acute";
            }

            m_angle = static_cast<short int>(alpha);
        }
};
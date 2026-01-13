#pragma once

#include "Rectangle.hpp"

namespace mw{

/**
 * \brief Represents a square.
 *
 * This class models a square as a special case of a rectangle where all
 * sides are equal. It inherits from the Rectangle class and enforces the
 * constraint that side A and side B have the same length.
 */
    class Square : public Rectangle {
        public:
            /**
             * \brief Represents a square.
             *
             * This class models a square as a special case of a rectangle where all
             * sides are equal. It inherits from the Rectangle class and enforces the
             * constraint that side A and side B have the same length.
             */
            Square(double a, const Point &p) : Rectangle(a, a, p, "Square") {}

            /**
             * \brief Creates a square from four corner points.
             *
             * Validates whether the provided points form a valid square by checking
             * that both rectangle sides have equal length.
             *
             * \param corners Array of four corner points.
             *
             * \throws const char* If the points do not form a square.
             */
            Square(const std::array<Point, 4> corners) : Rectangle(corners, "Squere") {
                if(abs(getA() - getB()) > 0.000001){
                    throw "This is not a Square";
                }  
            }

            /**
             * \brief Destructor.
             *
             * Default destructor for the Square class.
             */
            ~Square() = default;

            /**
             * \brief Calculates the area of the square.
             *
             * Uses the formula A = a².
             *
             * \return The area of the square.
             */
            double area() const override{
                return getA() * getA();
            }

            /**
             * \brief Calculates the perimeter of the square.
             *
             * Uses the formula P = 4a.
             *
             * \return The perimeter of the square.
             */
            double perimeter() const override{
                return 4 * getA();
            }

    };
} //namespace mw
#pragma once

#include "Figure.hpp"
#include "Point.hpp"
#include <cmath>
#include <array>

namespace mw{

/**
 * \brief Represents a rectangle.
 *
 * This class models a rectangle defined either by its center point and side
 * lengths, or by four corner points. It provides methods to compute the
 * rectangle's area and perimeter, as well as accessors and mutators for its
 * geometric properties.
 */
    class Rectangle : public Figure {
        private:
            /**
             * \brief Length of side A.
             *
             * Represents one side length of the rectangle. Must be non-negative.
             */
            double m_sideA;

            /**
             * \brief Length of side B.
             *
             * Represents the second side length of the rectangle. Must be non-negative.
             */
            double m_sideB;

            /**
             * \brief Corner points of the rectangle.
             *
             * Stores the four corner points of the rectangle in order.
             */
            std::array<Point, 4> m_corner;

        protected:
            /**
             * \brief Protected constructor with custom name.
             *
             * Creates a rectangle using side lengths and a center point, and assigns
             * a custom figure name. Used by derived classes.
             *
             * \param a Length of side A.
             * \param b Length of side B.
             * \param center Center point of the rectangle.
             * \param name Name of the figure.
             */
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

            /**
             * \brief Protected constructor from corner points with custom name.
             *
             * Initializes a rectangle from four corner points and assigns a custom
             * figure name. Validates whether the provided points form a rectangle.
             *
             * \param corners Array of four corner points.
             * \param name Name of the figure.
             */
            Rectangle(const std::array<Point, 4>& corners, std::string name) : m_corner(corners), Figure(name) {
                setCorner(corners);
            }

        public:

            /**
             * \brief Creates a rectangle using side lengths and a center point.
             *
            * Initializes a rectangle with the given side lengths and center.
             *
             * \param a Length of side A.
             * \param b Length of side B.
             * \param center Center point of the rectangle.
             */
            Rectangle(double a, double b, const Point &center): Rectangle(a, b, center, "Rectangle") {}

            /**
             * \brief Creates a rectangle from four corner points.
             *
             * Validates the provided points and initializes the rectangle if they
             * form a valid, non-degenerate rectangle.
             *
             * \param corners Array of four corner points.
             */
            Rectangle(const std::array<Point, 4>& corners) : m_corner(corners), Figure("Rectangle") {
                setCorner(corners);
            }

            /**
             * \brief Destructor.
             *
             * Default destructor for the Rectangle class.
             */
            ~Rectangle() = default;

            /**
             * \brief Calculates the area of the rectangle.
             *
             * Uses the formula A = a * b.
             *
             * \return The area of the rectangle.
            */
            double area() const override{
                return m_sideA * m_sideB;
            }

            /**
             * \brief Calculates the perimeter of the rectangle.
             *
             * Uses the formula P = 2 * (a + b).
             *
             * \return The perimeter of the rectangle.
             */
            double perimeter() const override{
                return 2 * (m_sideA +  m_sideB);
            }

            /**
             * \brief Sets the length of side A.
             *
             * Updates side A. The value must not be negative.
             *
             * \param a New length of side A.
             *
             * \throws const char* If a is less than zero.
             */
            void setA(double a) {
                if (a < 0) {
                    throw "a cannot be less than 0";
                }
                m_sideA = a;
            }

            /**
             * \brief Sets the length of side B.
             *
             * Updates side B. The value must not be negative.
             *
             * \param b New length of side B.
             *
             * \throws const char* If b is less than zero.
             */
            void setB(double b) {
                if (b < 0) {
                    throw "b cannot be less than 0";
                }
                m_sideB = b;
            }

            /**
             * \brief Sets rectangle corners and validates geometry.
             *
             * Determines whether the given points form a valid rectangle by checking
             * diagonal length and side orthogonality. Also rejects degenerate cases.
             *
             * \param corners Array of four corner points.
             *
             * \throws const char* If the points do not form a rectangle or form
             *         a degenerate rectangle.
             */
            void setCorner(const std::array<Point, 4>& corners) {
                int p1 = 0, p2 = -1, p3 = 1, p4 = -1;
                double maxDistance = 0.0;

                // Find the longest diagonal
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

                // Identify remaining two points
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

                // Compute side lengths
                double xSideA = corners[p1].getX() - corners[p2].getX();
                double ySideA = corners[p1].getY() - corners[p2].getY();
                double sideA = sqrt(xSideA * xSideA + ySideA * ySideA);

                double xSideB = corners[p2].getX() - corners[p3].getX();
                double ySideB = corners[p2].getY() - corners[p3].getY();
                double sideB = sqrt(xSideB * xSideB + ySideB * ySideB);

                const double eps = 0.000001;

                // Validate rectangle geometry using Pythagorean theorem
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

            /**
             * \brief Returns the length of side A.
             *
             * \return Length of side A.
             */
            double getA() const {
                return m_sideA;
            }

            /**
             * \brief Returns the length of side B.
             *
             * \return Length of side B.
             */
            double getB() const {
                return m_sideB;
            }

            /**
             * \brief Returns the corner points of the rectangle.
             *
             * \return Array containing the four corner points.
             */
            std::array<Point, 4> getCorner() const{
                return m_corner;
            }

    };
} // namespace mw
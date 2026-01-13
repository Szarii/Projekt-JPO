#pragma once

#include <array>
#include "Figure.hpp"

namespace mw{

/**
 * \brief Represents a triangle.
 *
 * This class models a triangle defined by three corner points. It provides
 * methods to compute the triangle's area and perimeter, as well as access
 * to its vertices.
 */
    class Triangle : public Figure{
        private:
            /**
             * \brief Represents a triangle.
             *
             * This class models a triangle defined by three corner points. It provides
             * methods to compute the triangle's area and perimeter, as well as access
             * to its vertices.
             */
            std::array<Point, 3> m_corner {};

        public:
            /**
             * \brief Creates a triangle from three corner points.
             *
             * Initializes a triangle using the provided vertices and validates
             * that they do not lie on a single straight line.
             *
             * \param corners Array of three corner points.
             *
             * \throws const char* If the points are collinear.
             */
            Triangle(const std::array<Point, 3>& corners) : m_corner(corners), Figure(corners[0], "Triangle"){
                setCorners(corners);
            }

            /**
             * \brief Default constructor.
             *
             * Creates a triangle with default-initialized values.
             */
            Triangle() = default;

            /**
             * \brief Destructor.
             *
             * Default destructor for the Triangle class.
             */
            ~Triangle() = default;

            /**
             * \brief Sets the corner points of the triangle.
             *
             * Validates that the given points do not lie on a single straight line,
             * ensuring a non-degenerate triangle.
             *
             * \param corners Array of three corner points.
             *
             * \throws const char* If the points are collinear.
             */
            void setCorners(const std::array<Point, 3>& corners){
                if (((m_corner[0].getX() == m_corner[1].getX()) && (m_corner[1].getX() == m_corner[2].getX()))
                || ((m_corner[0].getY() == m_corner[1].getY()) && (m_corner[1].getY() == m_corner[2].getY()))){
                    throw "Point cannot be in one line";
                }
                m_corner = corners;
            }

            /**
             * \brief Returns the triangle's corner points (read-only).
             *
             * \return Constant reference to the array of corner points.
             */
            const std::array<Point, 3>& getCorners() const {
                return m_corner;
            }

            /**
             * \brief Returns the triangle's corner points.
             *
             * Allows modification of the triangle's vertices.
             *
             * \return Reference to the array of corner points.
             */
            std::array<Point, 3>& getCorners(){
                return m_corner;
            }

            /**
             * \brief Calculates the area of the triangle.
             *
             * Uses the cross-product (determinant) formula to compute the area.
             *
             * \return The area of the triangle.
             */
            double area() const override
            {
                return (0.5) * abs((m_corner[1].getX() - m_corner[0].getX()) * 
                (m_corner[2].getY() - m_corner[0].getY()) -
                (m_corner[1].getY() - m_corner[0].getY()) *
                (m_corner[2].getX() - m_corner[0].getX()));
            }

            /**
             * \brief Calculates the perimeter of the triangle.
             *
             * Computes the sum of the lengths of all three sides.
             *
             * \return The perimeter of the triangle.
             */
            double perimeter() const override
            {
                double sideA = sqrt(((m_corner[1].getX() - m_corner[0].getX()) * (m_corner[1].getX() - m_corner[0].getX())) 
                + ((m_corner[1].getY() - m_corner[0].getY()) * (m_corner[1].getY() - m_corner[0].getY())));

                double sideB = sqrt(((m_corner[2].getX() - m_corner[1].getX()) * (m_corner[2].getX() - m_corner[1].getX())) 
                + ((m_corner[2].getY() - m_corner[1].getY()) * (m_corner[2].getY() - m_corner[1].getY())));

                double sideC = sqrt(((m_corner[0].getX() - m_corner[2].getX()) * (m_corner[0].getX() - m_corner[2].getX())) 
                + ((m_corner[0].getY() - m_corner[2].getY()) * (m_corner[0].getY() - m_corner[2].getY())));

                return sideA + sideB + sideC;
            }

    };

} //namespace mw

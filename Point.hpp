#pragma once

#include <iostream>
#include <string>

namespace mw{

/**
 * \brief Represents a point in 2D space.
 *
 * The Point class stores two non-negative integer coordinates (x, y)
 * and provides basic operations such as comparison, addition,
 * subtraction, and coordinate modification.
 */
    class Point {
        private:
            /**
             * \brief X coordinate of the point.
             *
             * Must be a non-negative integer.
             */
            int m_x;

            /**
             * \brief Y coordinate of the point.
             *
             * Must be a non-negative integer.
             */
            int m_y;
        
        public:
            /**
             * \brief Creates a point at (0, 0).
             *
             * Default constructor that initializes both coordinates to zero.
             */
            Point() : m_x(0), m_y(0) {}

            /**
             * \brief Creates a point with given coordinates.
             *
             * Initializes the point with coordinates (x, y).
             * Both values must be non-negative.
             *
             * \param x X coordinate.
             * \param y Y coordinate.
             *
             * \throw const char* If x or y is less than 0.
            */
            Point(int x, int y) : m_x(x), m_y(y) {
                setX(x);
                setY(y);
            }

            /**
             * \brief Default destructor.
             */
                ~Point() = default;
    
            /**
             * \brief Returns the X coordinate.
             *
             * \return X coordinate of the point.
             */
            int getX() const {
                return m_x;
            }

            /**
             * \brief Returns the Y coordinate.
             *
             * \return Y coordinate of the point.
             */
            int getY() const {
                return m_y;
            }

            /**
             * \brief Sets the X coordinate.
             *
             * \param x New X coordinate (must be non-negative).
             *
             * \throw const char* If x is less than 0.
             */
            void setX(int x) {
                if (x < 0) {
                    throw "x cannot be less than 0";
                }
                m_x = x;
            }

            /**
             * \brief Sets the Y coordinate.
             *
             * \param y New Y coordinate (must be non-negative).
             *
             * \throw const char* If y is less than 0.
             */
            void setY(int y) {
                if (y < 0) {
                    throw "y cannot be less than 0";
                }
                m_y = y;
            }

            /**
             * \brief Compares two points for equality.
             *
             * Two points are equal if both their X and Y coordinates are equal.
             *
             * \param other Point to compare with.
             * \return True if points are equal, false otherwise.
             */
            bool operator==(const Point& other) {
                if((m_x == other.m_x) && (m_y == other.m_y)) {
                    return true;
                }
                else{
                    return false;
                }
            }   

            /**
             * \brief Adds two points.
             *
             * Creates a new point whose coordinates are the sum of
             * the corresponding coordinates of the two points.
             *
             * \param other Point to add.
             * \return New point representing the sum.
             */
            Point operator+(const Point& other) {
                return Point(m_x + other.m_x, m_y + other.m_y);
            }

            /**
             * \brief Adds another point to this point.
             *
             * Modifies the current point by adding the coordinates
             * of the given point.
             *
             * \param other Point to add.
             * \return Reference to the modified point.
             */
            Point& operator+=(const Point& other) {
                m_x += other.m_x;
                m_y += other.m_y;
            return *this;
            }

            /**
             * \brief Subtracts another point from this point.
             *
             * Creates a new point whose coordinates are the difference
             * of the corresponding coordinates.
             *
             * \param other Point to subtract.
             * \return New point representing the difference.
             */
            Point operator-(const Point& other) {
                return Point(m_x - other.m_x, m_y - other.m_y);
            }
    
            /**
             * \brief Subtracts another point from this point.
             *
             * Modifies the current point by subtracting the coordinates
             * of the given point.
             *
             * \param other Point to subtract.
             * \return Reference to the modified point.
             */
            Point& operator-=(const Point& other) {
                m_x -= other.m_x;
                m_y -= other.m_y;
                return *this;
            }
    };

} // namespace mw
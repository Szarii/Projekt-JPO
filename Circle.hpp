#pragma once

#include "Figure.hpp"
#include <cmath>

namespace mw{

/**
 * \brief Represents a circle.
 *
 * This class models a geometric circle defined by its center point and radius.
 * It provides methods to compute the circle's area and perimeter, as well as
 * accessors and mutators for the radius.
 */ 
    class Circle : public Figure {
        private:
            /**
             * \brief The radius of the circle.
             *
             * Stores the radius value of the circle. The radius must be non-negative.
             */
            double m_radius;
        
        public:
            /**
             * \brief Creates a new Circle with a given radius and center.
             *
             * Initializes a circle with the specified radius and center point.
             * The radius is validated to ensure it is not negative.
             *
             * \param r Radius of the circle.
             * \param center Center point of the circle.
             */
            Circle(double r, const Point &center): m_radius(r), Figure(center, "Circle"){
                setRadius(r);
            }

            /**
             * \brief Default constructor.
             *
             * Creates a circle with default-initialized values.
             */
            Circle() = default;

            /**
             * \brief Destructor.
             *
             * Default destructor for the Circle class.
             */
            ~Circle() = default;

            /**
             * \brief Calculates the area of the circle.
             *
             * Uses the formula π * r² to compute the area.
             *
             * \return The area of the circle.
             */
            double area() const override{
                return M_PI * m_radius * m_radius;
            }

            /**
             * \brief Calculates the perimeter of the circle.
             *
             * Uses the formula 2 * π * r to compute the perimeter.
             *
             * \return The perimeter (circumference) of the circle.
             */
            double perimeter() const override{
                return 2 * M_PI * m_radius;
            }

            /**
             * \brief Sets the radius of the circle.
             *
             * Updates the circle's radius. The radius must not be negative.
             *
             * \param r New radius value.
             *
             * \throws const char* If the radius is less than zero.
             */
            void setRadius(const double &r){
                if (r < 0) {
                    throw "Radius cannot be less than 0";
                }
                m_radius = r;
            }

            /**
             * \brief Returns the radius of the circle.
             *
             * \return The current radius of the circle.
             */
            double getRadius() const {
                return m_radius;
            }

    };
}// namespace mw
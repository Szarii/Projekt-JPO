#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"

namespace mw{
/**
 * \brief Represents a geometric figure.
 *
 * The Figure class is an abstract base class for all 2D geometric figures.
 * It stores a center point and a name for the figure. It also declares
 * pure virtual functions for area and perimeter, which must be implemented
 * by derived classes.
 */
    class Figure {
        private:
            /**
             * \brief Center point of the figure.
             */
            Point m_point;

            /**
             * \brief Name of the figure.
             */
            std::string m_name;

        public:
            /**
             * \brief Creates a figure with a given center point and name.
             *
             * \param p Center point of the figure.
             * \param name Name of the figure.
             */
            Figure(const Point &p, const std::string &name) : m_point(p), m_name(name) {}

            /**
             * \brief Creates a figure at the origin with a given name.
             *
             * The center point is set to (0,0) by default.
             *
             * \param name Name of the figure.
             */
            Figure(const std::string &name) : m_point(0,0), m_name(name) {}

            /**
             * \brief Default destructor.
             */
            ~Figure() = default;

            /**
             * \brief Calculates the area of the figure.
             *
             * This is a pure virtual function and must be implemented by derived classes.
             *
             * \return Area of the figure.
             */
            virtual double area() const = 0;

            /**
             * \brief Calculates the perimeter of the figure.
             *
             * This is a pure virtual function and must be implemented by derived classes.
             *
             * \return Perimeter of the figure.
             */
            virtual double perimeter() const = 0;

            /**
             * \brief Sets the center point of the figure.
             *
             * \param p New center point.
             */
            void setCenter(const Point &p){
                m_point = p;
            }

            /**
             * \brief Returns the center point of the figure.
             *
             * \return Center point as a Point object.
             */
            Point getCenter() const {
                return m_point;
            }

            /**
             * \brief Sets the name of the figure.
             *
             * \param n New name of the figure.
             */
            void setName(const std::string &n){
                m_name = n;
            }

            /**
             * \brief Returns the name of the figure.
             *
             * \return Name of the figure as a string.
             */
            std::string getName() const {
                return m_name;
            }
    };
}//namespace mw
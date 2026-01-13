#pragma once

#include "Figure.hpp"
#include <cmath>
#include <array>

namespace mw{

/**
 * \brief Represents a rhombus.
 *
 * This class models a rhombus defined either by its side length, acute angle,
 * and center point, or by four corner points. It provides methods to compute
 * the rhombus area and perimeter, as well as validation of its geometry.
 */
    class Rhombus : public Figure {
        private:
            /**
             * \brief Length of the rhombus side.
             *
             * All sides of a rhombus have equal length. This value must be positive.
             */
            double m_sideA;

            /**
             * \brief Acute interior angle of the rhombus (in degrees).
             *
             * Stores the acute angle between two adjacent sides of the rhombus.
             * The angle must be greater than 0 and less than 90 degrees.
             */
            short int m_angle;

            /**
             * \brief Corner points of the rhombus.
             *
             * Stores the four vertices of the rhombus.
             */
            std::array<Point, 4> m_corner {};

        public:
            /**
             * \brief Corner points of the rhombus.
             *
             * Stores the four vertices of the rhombus.
             */
            Rhombus(double a, short int angle, const Point &center) : m_sideA(a), m_angle(angle), Figure(center, "Rhombus") {
                setAngle(angle);
            }

            /**
             * \brief Creates a rhombus from four corner points.
             *
             * Validates whether the provided points form a valid, non-degenerate
             * rhombus and computes its side length and interior angle.
             *
             * \param corners Array of four corner points.
             */
            Rhombus(const std::array<Point,4> corners) : m_corner(corners), Figure("Rhombus") {
                validateCorners();
            }

            /**
             * \brief Destructor.
             *
             * Default destructor for the Rhombus class.
             */
            ~Rhombus() = default;

            /**
             * \brief Calculates the area of the rhombus.
             *
             * Uses the formula A = a² · sin(α), where α is the acute interior angle.
             *
             * \return The area of the rhombus.
             */
            double area() const override{
                double alpha = (m_angle*M_PI)/180;
                return  m_sideA * m_sideA * sin(alpha);
            }

            /**
             * \brief Calculates the perimeter of the rhombus.
             *
             * Uses the formula P = 4a.
             *
             * \return The perimeter of the rhombus.
             */
            double perimeter() const override{
                return 4 * m_sideA;
            }

            /**
             * \brief Sets the side length of the rhombus.
             *
             * Updates the side length. The value must not be negative.
             *
             * \param a New side length.
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
             * \brief Returns the side length of the rhombus.
             *
             * \return Length of the rhombus side.
             */
            double getA() const{
                return m_sideA;
            }

            /**
             * \brief Sets the acute interior angle of the rhombus.
             *
             * The angle must be acute (greater than 0 and less than 90 degrees).
             *
             * \param a Angle value in degrees.
             *
             * \throws const char* If the angle is not acute.
             */
            void setAngle(int a) {
                if (a <= 0 || a >= 90) {
                    throw "alpha must be an acute angle";
                }
                m_angle = a;
            }

            /**
             * \brief Returns the acute interior angle of the rhombus.
             *
             * \return Angle value in degrees.
             */
            int getAngle() const{
                return m_angle;
            }

            /**
             * \brief Validates corner points and computes rhombus properties.
             *
             * Checks whether the four stored points form a valid rhombus by analyzing
             * pairwise distances, ensuring four equal sides and two diagonals.
             * Computes the side length and acute interior angle.
             *
             * \throws const char* If the points do not form a valid rhombus or form
             *         a degenerate shape.
             */
            void validateCorners() {
                double d[6];
                int k = 0;

                // Compute squared distances between all point pairs
                for (int i = 0; i < 4; ++i) {
                    for (int j = i + 1; j < 4; ++j) {
                        double dx = m_corner[i].getX() - m_corner[j].getX();
                        double dy = m_corner[i].getY() - m_corner[j].getY();
                        d[k++] = dx * dx + dy * dy;
                    }
                }

                const double eps = 1e-6;

                // Find the smallest non-zero distance (side length squared)
                double side2 = 0;
                for (int i = 0; i < 6; ++i) {
                    if (d[i] > eps && (side2 == 0 || d[i] < side2)) {
                    side2 = d[i];
                    }
                }

                if (side2 == 0) {
                    throw "Degenerate rhombus";
                }

                // Count occurrences of side length
                int count = 0;
                for (int i = 0; i < 6; ++i) {
                    if (std::abs(d[i] - side2) < eps){
                    count++;
                    }
                }

                if (count != 4) {
                    throw "Points do not form a rhombus";
                }

                m_sideA = std::sqrt(side2);

                // Identify diagonals
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

                // Compute acute angle using diagonal lengths
                double cosAlpha = (diag1 + diag2 - 4 * side2) / (2 * std::sqrt(diag1 * diag2));

                // Compute acute angle using diagonal lengths
                double alpha = std::acos(cosAlpha) * 180.0 / M_PI;

                if (alpha <= 0 || alpha >= 90){
                    throw "Angle must be acute";
                }

                m_angle = static_cast<short int>(alpha);
            }
    };
} // namespace mw
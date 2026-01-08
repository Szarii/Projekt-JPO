#pragma once

#include <array>
#include "Figure.hpp"

class Triangle : public Figure
{
private:
    std::array<Point, 3> m_corner;

public:
    Triangle(const std::array<Point, 3>& corners)
        : m_corner(corners), Figure(corners[0], "Triangle")
    {
        setCorners(corners);
    }

    void setCorners(const std::array<Point, 3>& corners)
    {
        if (((m_corner[0].getX() == m_corner[1].getX()) && (m_corner[1].getX() == m_corner[2].getX())) || ((m_corner[0].getY() == m_corner[1].getY()) && (m_corner[1].getY() == m_corner[2].getY())))
        {
            throw "Point cannot be in one line";
        }
        m_corner = corners;
    }

    const std::array<Point, 3>& getCorners() const
    {
        return m_corner;
    }

    std::array<Point, 3>& getCorners()
    {
        return m_corner;
    }

    double area() const override
    {
        return (0.5) * abs((m_corner[1].getX() - m_corner[0].getX()) * 
        (m_corner[2].getY() - m_corner[0].getY()) -
        (m_corner[1].getY() - m_corner[0].getY()) *
        (m_corner[2].getX() - m_corner[0].getX()));
    }

    double perimeter() const override
    {
        double sideA = sqrt(((m_corner[1].getX() - m_corner[0].getX()) * (m_corner[1].getX() - m_corner[0].getX())) + ((m_corner[1].getY() - m_corner[0].getY()) * (m_corner[1].getY() - m_corner[0].getY())));

        double sideB = sqrt(((m_corner[2].getX() - m_corner[1].getX()) * (m_corner[2].getX() - m_corner[1].getX())) + ((m_corner[2].getY() - m_corner[1].getY()) * (m_corner[2].getY() - m_corner[1].getY())));

        double sideC = sqrt(((m_corner[0].getX() - m_corner[2].getX()) * (m_corner[0].getX() - m_corner[2].getX())) + ((m_corner[0].getY() - m_corner[2].getY()) * (m_corner[0].getY() - m_corner[2].getY())));

        return sideA + sideB + sideC;
    }

};

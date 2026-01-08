#pragma once

#include <iostream>
#include <string>


class Point {
private:
    int m_x;
    int m_y;
public:
    // parametrized constructor

    Point() : m_x(0), m_y(0) {}
    Point(int x, int y) : m_x(x), m_y(y) {
        setX(x);
        setY(y);
    }

    int getX() const {
        return m_x;
    }

    int getY() const {
        return m_y;
    }

    void setX(int x) {
       if (x < 0) {
            throw "x cannot be less than 0";
        }
        m_x = x;
    }
    void setY(int y) {
       if (y < 0) {
            throw "y cannot be less than 0";
        }
        m_y = y;
    }

    bool operator==(const Point& other) {
        if((m_x == other.m_x) && (m_y == other.m_y)) {
            return true;
        }
        else{
            return false;
        }
    }

    Point operator+(const Point& other) {
        return Point(m_x + other.m_x, m_y + other.m_y);
    }

    Point& operator+=(const Point& other) {
        m_x += other.m_x;
        m_y += other.m_y;
        return *this;
    }

    Point operator-(const Point& other) {
        return Point(m_x - other.m_x, m_y - other.m_y);
    }

    Point& operator-=(const Point& other) {
        m_x -= other.m_x;
        m_y -= other.m_y;
        return *this;
    }
};
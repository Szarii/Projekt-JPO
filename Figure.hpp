#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"

class Figure {
private:
    Point m_point;
    std::string m_name;
public:
    Figure(const Point &p, const std::string &name) : m_point(p), m_name(name) {}
    Figure(const std::string &name) : m_point(0,0), m_name(name) {}

    ~Figure() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    void setCenter(const Point &p){
        m_point = p;
    }

    Point getCenter() const {
        return m_point;
    }

    void setName(const std::string &n){
        m_name = n;
    }

    std::string getName() const {
        return m_name;
    }
};
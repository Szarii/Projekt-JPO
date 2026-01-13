#include <iostream>
#include "Rhombus.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include <array>

using namespace mw;

void describe(const Figure& block)
{
    std::cout << "My name: " << block.getName() << std::endl;
    std::cout << "My area: " << block.area() << std::endl;
    std::cout << "My perimeter: " << block.perimeter() << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void test_point_operators(){
    std::cout << "=== Testing Point Operators ===" << std::endl;

    std::cout << "\n--- Testing operator== ---" << std::endl;
    Point p1(2, 3);
    Point p2(2, 3);
    
    if (p1 == p2) {
        std::cout << "p1(2,3) == p2(2,3)" << std::endl;
    } else {
        throw "p1(2,3) should equal p2(2,3)";
    }
    
    std::cout << "\n--- Testing operator+ ---" << std::endl;
    Point p4(3, 4);
    Point p5(2, 1);
    Point p6 = p4 + p5;
    
    std::cout << "p4(3,4) + p5(2,1) = p6(" << p6.getX() << "," << p6.getY() << ")" << std::endl;
    if (p6.getX() == p4.getX() + p5.getX() && p6.getY() == p4.getY() + p5.getY()) {
        std::cout << "operator+ works correctly" << std::endl;
    } else {
        throw "operator+ result should be (5,5)";
    }
    
    std::cout << "\n--- Testing operator+= ---" << std::endl;
    Point p7(10, 20);
    Point p8(5, 10);
    std::cout << "Before: p7(" << p7.getX() << "," << p7.getY() << ")" << std::endl;

    p7 += p8;
    std::cout << "After p7 += p8(5,10): p7(" << p7.getX() << "," << p7.getY() << ")" << std::endl;
    if (p7.getX() == 15 && p7.getY() == 30) {
        std::cout << "operator+= works correctly" << std::endl;
    } else {
        throw "operator+= result should be (15,30)";
    }
    
    std::cout << "\n--- Testing operator- ---" << std::endl;
    Point p9(10, 8);
    Point p10(3, 2);
    Point p11 = p9 - p10;
    
    std::cout << "p9(10,8) - p10(3,2) = p11(" << p11.getX() << "," << p11.getY() << ")" << std::endl;
    if (p11.getX() == p9.getX() - p10.getX() && p11.getY() == p9.getY() - p10.getY()) {
        std::cout << "operator- works correctly" << std::endl;
    } else {
        throw "operator- result should be (7,6)";
    }
    
    std::cout << "\n--- Testing operator-= ---" << std::endl;
    Point p12(20, 15);
    Point p13(8, 5);
    std::cout << "Before: p12(" << p12.getX() << "," << p12.getY() << ")" << std::endl;
    p12 -= p13;

    std::cout << "After p12 -= p13(8,5): p12(" << p12.getX() << "," << p12.getY() << ")" << std::endl;
    if (p12.getX() == 12 && p12.getY() == 10) {
        std::cout << "operator-= works correctly" << std::endl;
    } else {
        throw "operator-= result should be (12,10)";
    }
    
    std::cout << "\n=== All Point Operator Tests Complete ===" << std::endl;
}

void test_figure() {

    std::cout << "\n--- Testing circle ---" << std::endl;

    try{
        Circle circle1(3, Point(1, 1));
        describe(circle1);

        Circle circle2(-2, Point(2,3));
        describe(circle2);
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }
    catch(...){
        std::cout << "Error /n";
    }

    std::cout << "\n--- Testing triangle ---" << std::endl;

    try{
        Triangle triangle1({Point(6,3), Point(2,4), Point(1,10)});
        describe(triangle1);

        Triangle triangle2({Point(-5,3), Point(2,4), Point(1,-2)});
        describe(triangle2);        
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }
    catch(...){
        std::cout << "Error /n";
    }

    std::cout << "\n--- Testing rhombus ---" << std::endl;
    try{
        Rhombus rhombus1(5, 60, Point(1, 1));
        describe(rhombus1);

        Rhombus rhombus2({Point(1,1), Point(6,1), Point(4,5), Point(9,5)});
        describe(rhombus2);

        Rhombus rhombus3(5, 107, Point(1, 1));
        describe(rhombus3);
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }
    catch(...){
        std::cout << "Error /n";
    }

    std::cout << "\n--- Testing rectangle ---" << std::endl;

    try{
        Rectangle rectangle1(4, 5, Point(1,3));
        describe(rectangle1);

        std::array<Point, 4> array{Point(1,5), Point(1,2), Point(6,5), Point(6,2)};
        Rectangle rectangle2(array);
        describe(rectangle2);

        Rectangle rectangle3(-5, 3, Point(1,2));
        describe(rectangle3);
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }
    catch(...){
        std::cout << "Error /n";
    }

    std::cout << "\n--- Testing square ---" << std::endl;

    try{
        Square square1(3, Point(1, 1));
        describe(square1);

        Square square2({Point(2,2), Point(7,7), Point(2,7), Point(7,2)});
        describe(square2);

        Square square3({Point(2,6), Point(3,7), Point(8,7), Point(9,2)});
        describe(square3);
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }
    catch(...){
        std::cout << "Error /n";
    }

    std::cout << "\n=== All Figure Operator Tests Complete ===" << std::endl;
}

int main() {

    test_point_operators();

    test_figure();

    return 0;
        
}

#include <iostream>
#include "Rhombus.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include <array>


void describe(const Figure& block)
{
    std::cout << "My name: " << block.getName() << std::endl;
    std::cout << block.area() << std::endl;
    std::cout << block.perimeter() << std::endl;
}

int main() {

    /*try{
        Rhombus romb1(5, 60, Point(1, 1));
        std::cout << romb1.perimeter() << std::endl; 
        std::cout << romb1.area() << std::endl;
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }

    try{
        Circle kolo(3, Point(1, 1));
        std::cout << kolo.perimeter() << std::endl; 
        std::cout << kolo.area() << std::endl;
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }

    try{
        Square kwadrat(5, Point(1, 1));
        std::cout << kwadrat.perimeter() << std::endl; 
        std::cout << kwadrat.area() << std::endl;
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }
    
    try{
        Rectangle figure1(4, 5, Point(1,3));
        std::cout << figure1.perimeter() << std::endl; 
        std::cout << figure1.area() << std::endl;
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }*/
    
    try{
        Triangle trojkat({Point(6,3), Point(2,4), Point(1,10)});
        describe(trojkat);
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }

    try{
        std::array<Point, 4> tablica{Point(1,5), Point(1,2), Point(6,5), Point(6,2)};
        Rectangle test(tablica);
        describe(test);
    }
    catch(const char* s) {
        std::cout << "Error:" << s << std::endl;
    }
    catch(...){
        std::cout << "Error /n";
    }
    

    return 0;
        
}

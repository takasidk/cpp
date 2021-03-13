/* A test driver for the Circle class (TestCircle.cpp) */
#include <iostream>
#include "Circle.h" // using Circle class
using namespace std;

int main()
{
    // Construct an instance of Circle c1
    Circle c1(1.2, "red");
    cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()
         << " Color=" << c1.getColor() << endl;

    c1.setRadius(2.1); // Change radius and color of c1
    c1.setColor("blue");
    cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()
         << " Color=" << c1.getColor() << endl;

    // Construct another instance using the default constructor
    Circle c2;
    cout << "Radius=" << c2.getRadius() << " Area=" << c2.getArea()
         << " Color=" << c2.getColor() << endl;
    return 0;
}
/*
g++ -c Circle.cpp
g++ TestCircle.cpp Circle.o
./a.out
output:
Radius=1.2 Area=4.52389 Color=red
Radius=2.1 Area=13.8544 Color=blue
Radius=1 Area=3.14159 Color=red
*/
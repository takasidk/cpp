/* Test Substituting a subclass instance to a superclass reference
   (TestSubstitution.cpp) */
#include <iostream>
#include "MovablePoint.h" // included "Point.h"
using namespace std;

int main()
{
    // Substitute a subclass instance to a superclass reference

    // Using Object Pointer
    Point *ptrP1 = new MovablePoint(11, 12, 13, 14); // upcast
    ptrP1->print();                                  // Point @ (11,12) - Run superclass version!!
    cout << endl;
    // ptrP1->move();  // error: 'class Point' has no member named 'move'
    delete ptrP1;

    // Using Object Reference
    MovablePoint mp2(21, 22, 23, 24);
    Point &p2 = mp2; // upcast
    p2.print();      // Point @ (21,22) - Run superclass version!!
    cout << endl;
    // p2.move();      // error: 'class Point' has no member named 'move'

    // Using object with explicit constructor
    Point p3 = MovablePoint(31, 32, 33, 34); // upcast
    p3.print();                              // Point @ (31,32) - Run superclass version!!
    cout << endl;
    // p3.move();      // error: 'class Point' has no member named 'move'
}
/*
without using polymorphism
Point @ (11,12)
Point @ (21,22)
Point @ (31,32)
//using polymorphism
// Point.h
class Point {
   ......
   virtual void print() const;
}
/* Test Substituting a subclass instance to a superclass reference.
   (TestSubstitution.cpp) 
    #include <iostream>
    #include "MovablePoint.h"   // included "Point.h"
    using namespace std;
    
    int main() {
    // Substitute a subclass instance to a superclass reference
    
    // Using Object Pointer
    Point * ptrP1 = new MovablePoint(11, 12, 13, 14);   // upcast
    ptrP1->print(); // MovablePoint @ (11,12) Speed=(13,14)
                    //   - Run subclass version!!
    cout << endl;
    delete ptrP1;
    
    // Using Object Reference
    MovablePoint mp2(21, 22, 23, 24);
    Point & p2 = mp2;  // upcast
    p2.print();     // MovablePoint @ (21,22) Speed=(23,24)
                    //   - Run subclass version!!
    cout << endl;
    
    // Using object with explicit constructor
    Point p3 = MovablePoint(31, 32, 33, 34);  // upcast
    p3.print();     // Point @ (31,32) - Run superclass version!!
    cout << endl;
}
*/
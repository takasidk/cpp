/* A test driver program (TestPoint.cpp) */
#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
    // Instances (Objects)
    Point p1;       // Invoke default constructor
                    // OR Point p1 = Point(); NOT Point p1();
    Point p2(2, 2); // Invoke constructor
                    // OR Point p2 = Point(2, 2);
    p1.print();     // Point @ (0,0)
    cout << endl;
    p2.print(); // Point @ (2,2)
    cout << endl;

    // Object Pointers with dynamic allocation
    Point *ptrP3, *ptrP4; // Declare two Point pointers
    ptrP3 = new Point();  // Dynamically allocate storage via new
                          // with default constructor
    ptrP4 = new Point(4, 4);
    ptrP3->print(); // Point @ (0,0)
                    // prtPoint1->print() is the same as (*ptrP3).print()
    cout << endl;
    ptrP4->print(); // Point @ (4,4)
    cout << endl;

    delete ptrP3; // Remove storage via delete
    delete ptrP4;

    // Object Reference (Alias)
    Point &p5 = p2; // Reference (alias) to an existing object
    p5.print();     // Point @ (2,2)
    cout << endl;

    /********************
    * ARRAYS           *
    ********************/

    // Array of Objects - Static Memory Allocation
    Point ptsArray1[2];   // Array of Point objects
                          // Use default constructor for all elements of the array
    ptsArray1[0].print(); // Point @ (0,0)
    cout << endl;
    ptsArray1[1].setXY(11, 11);
    (ptsArray1 + 1)->print(); // Point @ (11,11)
                              // same as ptsArray1[1].print()
    cout << endl;

    Point ptsArray2[3] = {Point(21, 21), Point(22, 22), Point()};
    // Initialize array elements via constructor
    ptsArray2[0].print(); // Point @ (21,21)
    cout << endl;
    (ptsArray2 + 2)->print(); // Point @ (0,0)
                              // same as ptsArray2[2].print()
    cout << endl;

    // Array of Object Pointers - Need to allocate elements dynamically
    Point *ptrPtsArray3 = new Point[2];
    ptrPtsArray3[0].setXY(31, 31);
    ptrPtsArray3->print(); // Point @ (31,31)
                           // same as ptrPtsArray3[0].print()
    cout << endl;
    (ptrPtsArray3 + 1)->setXY(32, 32); // same as ptrPtsArray3[1].setXY(32, 32)
    ptrPtsArray3[1].print();           // Point @ (32,32)
    cout << endl;

    delete[] ptrPtsArray3; // Free storage

    // C++ does not support Array of References
    // Point & pts[2] = {p1, p2};  // error: declaration of 'pts' as array of references
}
/*
Point @ (0,0)
Point @ (2,2)
Point @ (0,0)
Point @ (4,4)
Point @ (2,2)
Point @ (0,0)
Point @ (11,11)
Point @ (21,21)
Point @ (0,0)
Point @ (31,31)
Point @ (32,32)
*/
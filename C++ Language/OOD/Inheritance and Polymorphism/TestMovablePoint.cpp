/* Test Driver Program for MovablePoint (TestMovablePoint.cpp) */
#include <iostream>
#include "MovablePoint.h" // included "Point.h"
using namespace std;

int main()
{
    Point p1(4, 5); // superclass
    p1.print();     // Point @ (4,5)
    cout << endl;

    MovablePoint mp1(11, 22); // subclass, default speed
    mp1.print();              // MovablePoint @ (11,22) Speed=(0,0)
    cout << endl;
    mp1.setXSpeed(8);
    mp1.move();
    mp1.print(); // MovablePoint @ (19,22) Speed=(8,0)
    cout << endl;

    MovablePoint mp2(11, 22, 33, 44);
    mp2.print(); // MovablePoint @ (11,22) Speed=(33,44)
    cout << endl;
    mp2.move();
    mp2.print(); // MovablePoint @ (44,66) Speed=(33,44)
    cout << endl;
}
/*
friday@ubuntu:~/Temp$ g++ TestMovablePoint.cpp Point.cpp MovablePoint.cpp
friday@ubuntu:~/Temp$ ./a.out
Point @ (4,5)
MovablePoint @ (11,22) Speed=(0,0)
MovablePoint @ (19,22) Speed=(8,0)
MovablePoint @ (11,22) Speed=(33,44)
MovablePoint @ (44,66) Speed=(33,44)
*/
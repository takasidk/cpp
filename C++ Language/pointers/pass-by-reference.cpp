/* Pass-by-value into function (TestPassByValue.cpp) */
#include <iostream>
using namespace std;

int square(int);
void squareByPointer(int *);
void squareByReference(int &);
int main()
{
    int number = 8;
    cout << "In main(): " << &number << endl; // 0x22ff1c
    cout << number << endl;                   // 8
    cout << square(number) << endl;           // 64 pass-by-value
    cout << number << endl;                   // 8 - no change
    //pass-by-refernce with pointer argument
    cout << "In main(): " << &number << endl; // 0x22ff1c
    cout << number << endl;                   // 8
    squareByPointer(&number);                 // Explicit referencing to pass an address
    cout << number << endl;                   // 64
    //pass-by-reference with reference argument
    //number = 8;                               // set number to 8 again
    cout << "In main(): " << &number << endl; // 0x22ff1c
    cout << number << endl;                   // 8
    squareByReference(number);                // Implicit referencing (without '&')
    cout << number << endl;                   // 64
}

int square(int n)
{                                          // non-const
    cout << "In square(): " << &n << endl; // 0x22ff00
    n *= n;                                // clone modified inside the function
    return n;
}
void squareByPointer(int *pNumber)
{                                               // Function takes an int pointer (non-const)
    cout << "In square(): " << pNumber << endl; // 0x22ff1c
    *pNumber *= *pNumber;                       // Explicit de-referencing to get the value pointed-to
}
void squareByReference(int &rNumber)
{                                                // Function takes an int reference (non-const)
    cout << "In square(): " << &rNumber << endl; // 0x22ff1c
    rNumber *= rNumber;                          // Implicit de-referencing (without '*')
}
/*
In main(): 0x7ffe079878f4
8
In square(): 0x7ffe079878dc
64
8
In main(): 0x7ffe079878f4
8
In square(): 0x7fff9313fda4
64
In main(): 0x7fff9313fda4
64
In square(): 0x7fff9313fda4
4096
*/
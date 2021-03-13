#include <iostream>
using namespace std;
struct A
{
    /* data */
    A()
    {
        cout << "A constructed..." << endl;
    }
    ~A()
    {
        cout << "A distructed..." << endl;
    }
};

int main()
{
    A *p1 = new A;
    A *p2 = new A[2];
    delete (p1);  //step2
    delete[](p2); //step2
    cout << "C way of allocating memory" << endl;
    A *p3 = (A *)malloc(sizeof(A));
    A *p4 = (A *)malloc(2 * sizeof(A));
    free(p3);
    free(p4);
    const int SIZE = 5;
    int *pArray;

    pArray = new int[SIZE]; // Allocate array via new[] operator

    // Assign random numbers between 0 and 99
    for (int i = 0; i < SIZE; ++i)
    {
        *(pArray + i) = rand() % 100;
    }
    // Print array
    for (int i = 0; i < SIZE; ++i)
    {
        cout << *(pArray + i) << " ";
    }
    cout << endl;

    delete[] pArray; // Deallocate array via delete[] operator

    return 0;
}
//C++03 does not allow your to initialize the dynamically-allocated array. C++11 does with the brace initialization, as follows:

// C++11
//int * p = new int[5] {1, 2, 3, 4, 5};

/*
step1:
A constructed...
A constructed...
A constructed...
step2:free ing pointers
A constructed...
A constructed...
A constructed...
A distructed...
A distructed...
A distructed...
*/
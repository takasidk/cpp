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
    return 0;
}
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
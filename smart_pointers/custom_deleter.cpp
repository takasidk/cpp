#include <iostream>
#include <memory>
using namespace std;
struct A
{
    /* data */
    A()
    {
        cout << "A constr..." << endl;
    }
    ~A()
    {
        cout << "A dist...." << endl;
    }
    void print()
    {
        cout << "custom release" << endl;
    }
};
void deleteA(A *aptr)
{
    cout << "deleting A" << endl;
    if (aptr)
    {
        aptr->print();
        delete aptr;
    }
}
int main()
{
    shared_ptr<A> p1(new A, &deleteA);
    // another way
    shared_ptr<A> p2(new A(), [](A *ptr) {
        cout << "deleting A.." << endl;
        ptr->print();
        delete ptr;
    });
    // another way by functor
}
/*
out:
A constr...
A constr...
deleting A..
custom release
A dist....
deleting A
custom release
A dist....
*/
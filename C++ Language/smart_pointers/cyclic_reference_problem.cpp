#include <iostream>
#include <memory>
using namespace std;

struct A
{
    weak_ptr<A> adjacent; //step 3 //step1:shared_ptr<A> adjacent
    A()
    {
        cout << "A constructed..." << endl;
    }
    ~A()
    {
        cout << "A destructed..." << endl;
    }
    void printA()
    {
        cout << "A struct...." << endl;
    }
    void set_adjacent(shared_ptr<A> ptr)
    {
        adjacent = ptr;
    }
};
int main()
{
    shared_ptr<A> sp1(new A);
    shared_ptr<A> sp2(new A);
    weak_ptr<A> wp1 = sp1;
    /*Way of using weak ptr as a copy of shared pointer
    by using lock() or can use expired().
    To get address stored for smart pointers use p1.get() where
    p1 is smart pointer declared(ex:sp1.get() or wp1.get()).
    */
    wp1.lock()->printA();   //step2
    sp1->set_adjacent(sp2); //step2
    sp2->set_adjacent(sp1);
    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;
    return 0;
}
/*
step1 output:
A constructed...
A constructed...
2
2
step2 output:
A constructed...
A constructed...
A struct....
2
2
step 3 output:
A constructed...
A constructed...
A struct....
1
1
A destructed...
A destructed...
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    cout << "Pointer Arthematic..." << endl;
    int arr[10] = {1, 2, 3, 4, 5};
    int *p = arr;
    for (auto i = 0; i < 10; i++)
    {
        cout << i << " " << p++ << endl;
    }

    cout << "\ncharacter pointer..." << endl;
    char c = 'a';
    char *cptr = &c;
    cout << cptr << "gives wrong address" << endl;
    cout << (void *)cptr << "gives correct address by type casting it" << endl;

    cout << "\nchar pointer to a string litteral" << endl;
    char c1[] = "abcd";
    cout << "string is:" << c1 << endl;
    cout << strlen(c1) << " is length of string" << endl;
    cout << sizeof(c1) << " is size of c1" << endl;

    cout << "\nchar pointer to a string " << endl;
    char const *c2 = "abcd";
    cout << "string is:" << c2 << endl;
    cout << strlen(c2) << " is length of string" << endl;
    cout << sizeof(c2) << " is size of c2" << endl;
}
/*
Pointer Arthematic...
0 0x7ffd7f3e6c30
1 0x7ffd7f3e6c34
2 0x7ffd7f3e6c38
3 0x7ffd7f3e6c3c
4 0x7ffd7f3e6c40
5 0x7ffd7f3e6c44
6 0x7ffd7f3e6c48
7 0x7ffd7f3e6c4c
8 0x7ffd7f3e6c50
9 0x7ffd7f3e6c54

character pointer...
a
gives wrong address
0x7ffd7f3e6c13gives correct address by type casting it

char pointer to a string litteral
string is:abcd
4 is length of string
5 is size of c1

char pointer to a string 
string is:abcd
4 is length of string
8 is size of c1
*/
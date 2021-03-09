/*
stack implementation using arrays
push,pop,top,isEMpty operations in O(1)constant time
limitation:
if we have large data to push then overflow may occur
So,we can use dynamic array implementation where,we 
create a new array of double the prev size and copy 
the prev array in to the new array and delete the prev array
But,the cost of the this is O(n) which is costly and Our push 
worst case time will be O(n) which we cant afford to do
*/
#include <iostream>
#define MAX 101
using namespace std;
int A[MAX];
int top = -1;
void push(int x)
{
    if (top == MAX - 1)
    {
        cout << "Error:Stack Overflow" << endl;
        return;
    }
    A[++top] = x;
}
void pop()
{
    top--;
}
void Top()
{
    cout << A[top] << " " << endl;
}
void print()
{ // only to verify the test case
    for (int i = 0; i <= top; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(2);
    print();
    push(5);
    print();
    push(6);
    print();
    pop();
    print();
    Top();
    push(3);
    print();
    return 0;
}
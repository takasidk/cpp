/*
Stack implementation using linked list:
So,here we can have two options
1.insert/delete at tail
2.insert/delete at the beginning
But,at tail insertion and deletions we traverse 
the whole linked list which costs us O(n) time 
whic we cant afford
So, its straight forward to us we should do at the beginning
*/
#include <iostream>
using namespace std;
struct Node
{
    /* data */
    int data;
    Node *next;
};
Node *top = NULL;
Node *push(int x, Node *top)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->next = top;
    top = newNode;
    return top;
}
Node *pop(Node *top)
{
    if (top == NULL)
    {
        cout << "empty" << endl;
        return top;
    }
    Node *temp = top;
    top = top->next;
    free(temp);
    return top;
}
void Top()
{
    cout << "top is:" << top->data << endl;
}
void print()
{ // just to check test case
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    top = push(2, top);
    print();
    top = push(3, top);
    print();
    Top();
    top = push(19, top);
    print();
    top = pop(top);
    print();
    return 0;
}
/*
out:
2 
3 2 
top is:3
19 3 2 
3 2 
*/
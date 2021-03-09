/*
Queue ADT:(FIFO)
    First In First Out
    A list or collection with restriction that insertion can be performed at
    one end (rear end) and deletion can be performed at one end (front)
Operations-
enqueue(x)
dequeue()
front()/peek()
isEmpty()
These will be having constant time complexity O(1).
Ex:
let say we have a printer shared in a network and printer can print only one
at a point of time So, it can take only one request at a time So, queue ADT
is something like that so we can use here queue structure process requestions
the requests made by computers will be queued 
Implementation:
1.with array:
2.with linked list
*/
#include <iostream>
#define MAX 10
using namespace std;
int A[MAX];
int front = -1, rear = -1;
void enqueue(int x);
void dequeue();
int peek();
bool isEmpty();
bool isFull();
void print()
{
    for (int i = front; i != rear; i = (i + 1) % MAX)
    {
        cout << A[i] << " ";
    }
    cout << A[rear] << " " << endl;
}
int main()
{
    enqueue(2);
    print();
    enqueue(5);
    print();
    enqueue(7);
    print();
    dequeue();
    print();
    enqueue(3);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    print();
    cout << peek() << endl;
}
void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (isFull())
    {
        cout << "!Reached max size cant enqueue any further" << endl;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    A[rear] = x;
}
void dequeue()
{
    if (isEmpty())
    {
        cout << "queue is Empty-No elements to delete" << endl;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}
int peek()
{
    if (isEmpty())
    {
        cout << "!No Elements error:" << endl;
        return -1;
    }
    return A[front];
}
bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    return false;
}
bool isFull()
{
    if ((rear + 1) % MAX == front)
        return true;
    return false;
}
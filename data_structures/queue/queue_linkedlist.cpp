/*
queue-
deletion at front end 
insertion at rear end
In queue implementation using array we used circular array so that we will 
be able to use the whole array size But, if we more data to insert and array is full
we can create a array double the size of prev array and copy all the elements
to new array and delete the prev array But, this is a costly process and 
one more limitation is we will be having more unused memory when we have a big array
So, we can use linked list implementation to get out of this limitation/
drawback
Coming to implementation using linkedlist :
in linkedlist insertion /deltion at front will O(1) But, insertion/deletion
at end will O(n) because we need traverse to end to insert/delete 
So, what we can do is we can declare a pointer rear which we store address
of the end element (will point to the rear Node) so that we no need to 
traverse the whole list 
*/
#include <iostream>
using namespace std;
bool isEmpty();
struct Node
{
    /* data */
    int data;
    Node *next;
};
Node *front = NULL;
Node *rear = NULL;
void enqueue(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue()
{
    if (isEmpty())
    {
        cout << "!Error No element to delete" << endl;
        return;
    }
    else if (front == rear)
    {
        front = rear = NULL;
    } //when there is only one element
    //and u need to delete it then after deletion we need intialize them front and rear to NULL
    Node *temp = front;
    front = temp->next;
    delete (temp);
}
void peek()
{
    cout << "front is:" << front->data << endl;
}
bool isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return true;
    }
    return false;
}
void print()
{
    if (isEmpty())
    {
        cout << "NO elements in the list:" << endl;
    }
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    print();
    peek();
    dequeue();
    print();
    peek();
}
/*
out:
1 2 3 3 3 3 
front is:1
2 3 3 3 3 
front is:2
*/
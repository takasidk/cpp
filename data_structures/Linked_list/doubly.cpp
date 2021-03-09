#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node *head = NULL;
Node *getNewNode(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
Node *insertAtHead(int x, Node *head)
{
    Node *newNode = getNewNode(x);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    return head;
}
Node *insertAtTail(int x, Node *head)
{
    Node *newNode = getNewNode(x);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}
void print()
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    head = NULL;
    head = insertAtHead(1, head);
    head = insertAtHead(2, head);
    head = insertAtHead(3, head);
    head = insertAtHead(4, head);
    head = insertAtHead(5, head);
    print();
    head = insertAtTail(1, head);
    head = insertAtTail(2, head);
    head = insertAtTail(3, head);
    head = insertAtTail(4, head);
    head = insertAtTail(5, head);
    print();
    return 0;
}
/*
5 4 3 2 1 1 2 3 4 5 
*/
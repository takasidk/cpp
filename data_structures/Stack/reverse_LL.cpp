#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    /* data */
    int data;
    Node *next;
};
Node *head;
Node *insertAtBack(Node *head, int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
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
    }
    return head;
}
Node *reverse(Node *head)
{
    Node *temp = head;

    stack<Node *> s;

    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    head = temp;
    s.pop();
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    head = NULL;
    head = insertAtBack(head, 1);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 3);
    head = insertAtBack(head, 4);
    head = insertAtBack(head, 5);
    cout << "before reversal:" << endl;
    print();
    head = reverse(head);
    cout << "after reversal:" << endl;
    print();
}
/*
out:
before reversal:
1 2 3 4 5 
after reversal:
5 4 3 2 1 
*/
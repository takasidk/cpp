#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head;
void insert(int x)
{
    Node *temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;
    Node *temp2 = head;
    if (head == NULL)
    {
        head = temp1;
    }
    else
    {
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
}
void del(int n)
{
    Node *temp = head;
    Node *temp1;
    if (n == 1)
    {
        head = temp->next;
        free(temp);
    }
    else
    {

        for (int i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}
void print()
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "empty" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}
int main()
{
    head = NULL;
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    cout << "enter the position" << endl;
    int n;
    cin >> n;
    del(n);
    print();
    return 0;
}
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
Node *reverseitr(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *af, *bf, *cur; //af=after,bf=before,cur=current
    bf = NULL;
    cur = head;
    while (cur != NULL)
    {
        af = cur->next;
        cur->next = bf;
        bf = cur;
        cur = af;
    }
    head = bf;
    return head;
}
void reverserecur(Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverserecur(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}
void printitr()
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
void printrecur(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    printrecur(p->next);
    cout << p->data << " ";
}
int main()
{
    head = NULL;
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    printitr();
    cout << "after reversal iteratively:" << endl;
    head = reverseitr(head);
    printitr();
    cout << "after double reversal recursively:" << endl;
    reverserecur(head);
    printitr();
    return 0;
}
/*
out:
2 3 4 5 after reversal iteratively:
5 4 3 2 after double reversal recursively:
2 3 4 5 
*/
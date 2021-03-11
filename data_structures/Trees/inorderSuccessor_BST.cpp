/*

*/
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    /* data */
    int data;
    Node *left;
    Node *right;
};
Node *getNewNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        root = getNewNode(x);
        return root;
    }
    else if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }
    return root;
}
Node *findMin(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    //cout << temp->data << " ";
    return temp;
}
Node *search(Node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        //cout << root->data;
        return root;
    }
    else if (x < root->data)
    {
        return search(root->left, x);
    }
    else
        return search(root->right, x);
}
Node *getSuccessor(Node *root, int x)
{
    Node *current = search(root, x);
    //cout << current->data << endl;

    if (current == NULL)
    {
        return NULL;
    }
    if (current->right != NULL)
    { // if the target node has right subtree then u need to find the min in the right subtree
        return findMin(current->right);
    }
    else
    {
        Node *successor = NULL;
        Node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data) //deppest node will be the successor
            {
                successor = ancestor; // so far this is the deppest
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
int main()
{
    Node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 17);
    root = insert(root, 14);
    root = insert(root, 18);
    cout << "enter the number " << endl;
    int num;
    cin >> num;
    cout << "successor of " << num << " is:" << getSuccessor(root, num)->data << endl;
}
/*
out:
enter the number 
17
successor of 17 is:18
friday@ubuntu:~/Temp$ ./a.out
enter the number 
9
successor of 9 is:12
*/
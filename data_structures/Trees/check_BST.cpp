/*
check if a Binary tree is a binary search tree:
which means a binary tree obeys BST restrictions will be BST
So, idea would taking an interval (-inf,+inf) and from root while traversing 
left the upperbound will be changed and while going right the lower bound
will be changed so while traversing we should check whether the node
present is in between the bounds or not 
another way would be find the FindMax(leftsubtree) and findMin (rightsubtree)
then our root should be greater then the max and lesser then min then its BST
*/
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
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
    else if (x <= root->data)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }
    return root;
}
bool isBstUtill(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data <= max && isBstUtill(root->left, min, root->data) && isBstUtill(root->right, root->data, max))
    {
        return true;
    }
    else
        return false;
}
bool isBST(Node *root)
{
    return isBstUtill(root, INT_MIN, INT_MAX);
}
int main()
{
    Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 100);
    root = insert(root, 30);
    root = insert(root, 30);
    root = insert(root, 14);
    root = insert(root, 52);
    root = insert(root, 61);
    root = insert(root, 7);
    if (isBST(root))
    {
        cout << "It is BST:)" << endl;
    }
    else
        cout << "NO!" << endl;
}
/*
It is BST:)
*/
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
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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
    // cout << root->data << endl;
    cout << "preorder is:";
    preOrder(root);
    cout << "\ninOrder is:";
    inOrder(root);
    cout << "\npostOrder is:";
    postOrder(root);
}
/*
out:
preorder is:1 100 30 30 14 7 52 61 
inOrder is:1 7 14 30 30 52 61 100 
postOrder is:7 14 30 61 52 30 100 1
*/
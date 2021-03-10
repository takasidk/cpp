#include <iostream>
using namespace std;
struct BSTNode
{
    /* data */
    int data;
    BSTNode *left;
    BSTNode *right;
};
BSTNode *getNewNode(int x)
{
    BSTNode *newNode = new BSTNode();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
BSTNode *insert(BSTNode *root, int x)
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
bool search(BSTNode *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    else if (x <= root->data)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
    return false;
}
int main()
{
    BSTNode *root = NULL;
    root = insert(root, 100);
    root = insert(root, 30);
    root = insert(root, 30);
    root = insert(root, 14);
    root = insert(root, 52);
    root = insert(root, 61);
    root = insert(root, 7);
    int num;
    cout << "enter the number u want to search:" << endl;
    cin >> num;
    if (search(root, num))
    {
        cout << "found:)" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}
/*
out:
enter the number u want to search:
7
found:)
enter the number u want to search:
17
not found
*/
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
int recurMin(BSTNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty!" << endl;
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
        return recurMin(root->left);
}
int findMin(BSTNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty!" << endl;
        return -1;
    }
    BSTNode *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}
int findMax(BSTNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty!" << endl;
        return -1;
    }
    BSTNode *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
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
    cout << "MIN = " << findMin(root) << endl;
    cout << "MAX = " << findMax(root) << endl;
    cout << "recur MIN = " << recurMin(root) << endl;
}
/*
out:
MIN = 7
MAX = 100
recur MIN = 7
*/
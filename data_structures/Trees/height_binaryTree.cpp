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
int height(BSTNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
        return max(height(root->left) + 1, height(root->right) + 1);
}
int main()
{
    BSTNode *root = NULL;
    // root = insert(root, 100);
    root = insert(root, 30);
    root = insert(root, 30);
    root = insert(root, 14);
    root = insert(root, 52);
    root = insert(root, 61);
    //root = insert(root, 7);
    cout << "height of tree = " << height(root) << endl;
}
/*
out:
height of tree = 4
friday@ubuntu:~/Temp$ g++ height_binaryTree.cpp
friday@ubuntu:~/Temp$ ./a.out
height of tree = 3 when 7 node removed
friday@ubuntu:~/Temp$ g++ height_binaryTree.cpp
friday@ubuntu:~/Temp$ ./a.out
height of tree = 2 when 7 and 100 are removed
*/
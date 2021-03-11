/*
deleteing a node would be tricky beacuase we may lose the property of BST
case 1: if the node is leaf there is no change of property
case 2: if the node is having only one child there is no change in property
case 3: if the node is having 2 children then there is change in property
 - So,here in case 3 we can reduce it to case 2 by find min in the right
    subtree and copy the value in target node and delete the duplicate from right 
    sub tree which will be having only one child (case 2) (or) u can do vise versa i.e find the max from left subtree 
    copy the value in target node and delete the dupicate from left subtree
    which will be a leaf node of left subtree (case 1)
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
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *del(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    else if (x < root->data)
    {
        root->left = del(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = del(root->right, x);
    }
    else // this is when we found the node and we need to delete here
    {
        if (root->left == NULL && root->right == NULL) //CASE 1:
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        { //CASE 2:only right child
            Node *temp = root;
            root = temp->right;
            delete temp;
        }
        else if (root->right == NULL)
        { //CASE 2: only left child
            Node *temp = root;
            root = temp->left;
            delete temp;
        }
        else
        { //case 3: two childs
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
    }
    return root;
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
    inOrder(root);
    cout << "\nenter the number u want to delete" << endl;
    int num;
    cin >> num;
    root = del(root, num);
    cout << "after the deletion of " << num << " List is:" << endl;
    inOrder(root);
}
/*
out:
1 3 5 7 9 12 13 14 15 17 18 
enter the number u want to delete
15
after the deletion of 15 List is:
1 3 5 7 9 12 13 14 17 18
*/
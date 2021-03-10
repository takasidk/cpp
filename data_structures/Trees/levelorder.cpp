/*
algo would be:
taking a queue pushed with root intially and then 
while queue is not empty:
    visit the first unvisited node and push its left and right into the queue
    and dequeue the visited node
complexities:
time=O(n) because we need to traverse all the nodes
space=O(1)->best(in atree which is having all nodes having only one type of child),O(n)->worst/avg
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
void levelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "!Empty" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    Node *current;
    while (!q.empty())
    {
        // cout << "S" << endl;
        current = q.front();
        cout << current->data << " ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
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
    levelOrder(root);
}
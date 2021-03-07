#include<bits/stdc++.h>
using namespace std;

struct Node {
      int val;
      Node *left;
      Node *right;
      Node() : val(0), left(nullptr), right(nullptr) {}
      Node(int x) : val(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
  };
 void inorder(Node*root){
   if(root==NULL)return;
   
    inorder(root->left);
      cout<<root->val<<" ";
    inorder(root->right);
}
void preorder(Node*root){
   if(root==NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node*root){
   if(root==NULL)return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
//iterative way for inorder
vector<int> inorderIter(Node* root){
        vector<int> v;
         stack<Node*>S;
        Node*cur=root;
       
     while(cur!=NULL || !S.empty()) //-imp step
     {
         while(cur!=NULL){
             cur=cur->left;
             if(cur)S.push(cur);

         }
         cur=S.top();
         S.pop();
        // cout<<cur->val<<" ";
         v.push_back(cur->val);          
         cur=cur->right;if(cur)S.push(cur);
     }
     return v;
      }

int main() {
   Node*n1=new Node(1);
    Node*n2=new Node(2);
    Node*n3=new Node(3);
    Node*n4=new Node(4);
    Node*n5=new Node(5);
    Node*n6=new Node(6);
    Node*n7=new Node(7);
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n3->left=n5;
    n3->right=n6;
    n4->right=n7;
    Node*root=n1;
    inorder(root);
    cout<<endl;
    preorder(root);
     cout<<endl;
    postorder(root);
     cout<<endl;
}
/*
Linear Data Structures:
array,linkedlist,stack,queue
How should i decide which data structures to use?
- what needs to be stored
- cost of operations
-  memory usage and smetimes ease of implementation
NOn-linear data structure:
tree:
terminologies-
root
children
parent
siblings
leaf
(if say we can go from A to B in given tree Then A is ancestor of B and B is descendent of A)
ancestor
descendent
cousin
grand parent
uncle
Tree--> is recursive data structure where root will be having links to its sub-trees
--> N nodes,N-1 edges in valid tree
depth:
depth of x Node=length of x from root or No of edges in path from root to x
depth of root=0
height:
height of x= No of edges in the longest path from x to a leaf Node
height of a tree =height of the root
height of a empty tree is =-1
height of atree with 1 node =0
Binary Tree--> a tree in whic each Node can have at most two children
struct Node{
    int data;
    Node * left;
    Node * right;
}
strict/proper bInary tree-binary tree in which each Node has either 2 or 0 children
complete Binary tree:binary tree in which all levels are completely filled except
last level which is should be completely filled or all nodes are as left side as possible
max No of Nodes at level i:2power(i)
perfect binary tree:in which all levels are completely filled
max no of Nodes in tree of height h=2power(h+1)-1=2power(No of levels )-1
Balanced Binary Tree: absolute difference between height of left and right sub tree for every Node is not more than 1(mostly 1)

Appllication:
1.storing natuarlly heirarchial data Ex: file system in ours computers
2. organize data for quick search,insertion and deletion Ex: Binary search trees(bst)
3. Trie: used for storing dictionary (fast and efficient)used to dynamic spell check
4. network routing algorithms
we can implement binary tree using:
1.dynamically created Nodes
2.arrays ( used for complete binary trees):
    for node at index i;
    left-child-index=2i+1
    right-child-index=2i+2
Table of complexities
Binary search tree:
a binary tree in which for each node value of all Nodes in left subtree is lesser or equal and
right subtree is greater   
*/
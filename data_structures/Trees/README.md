- <ins>Linear Data Structures</ins>:<ins></ins>
array,linkedlist,stack,queue
- How should i decide which data structures to use?\
what needs to be stored\
cost of operations\
memory usage and sometimes ease of implementation
* <ins>NOn-linear data structure</ins>:
## Trees:
* <ins>terminologies</ins>:\
1.root\
2.children\
3.parent\
4.siblings\
5.leaf
(if say we can go from A to B in given tree Then A is ancestor of B and B is descendent of A)\
6.ancestor\
7.descendent\
8.cousin\
9.grand parent\
10.uncle
* Tree is recursive data structure where root will be having links to its sub-trees
* N nodes,N-1 edges in valid tree
- <ins>Depth</ins>:\
depth of x Node=length of x from root or No of edges in path from root to x\
depth of root=0
- <ins>Height</ins>:\
height of x= No of edges in the longest path from x to a leaf Node\
height of a tree =height of the root\
height of a empty tree is =-1\
height of atree with 1 node =0
- <ins>Binary Tree</ins>: a tree in which each Node can have at most two children
   >  struct Node{\
   >  int data;\
   >  Node * left;\
   >  Node * right;\
   >         }
- <ins>strict/proper bInary tree</ins>:\binary tree in which each Node has either 2 or 0 children
- <ins>complete Binary tree</ins>:\binary tree in which all levels are completely filled except
last level which is should be completely filled or all nodes are as left side as possible\
max No of Nodes at level i:2power(i)
- <ins>perfect binary tree</ins>:in which all levels are completely filled\
max no of Nodes in tree of height h=2power(h+1)-1=2power(No of levels )-1\
- <ins>Balanced Binary Tree</ins>: absolute difference between height of left and right sub tree for every Node is not more than 1(mostly 1)
- <ins>Appllications</ins>:\
     1.storing natuarlly heirarchial data Ex: file system in ours computers.\
     2. organize data for quick search,insertion and deletion Ex: Binary search trees(bst).\
     3. Trie: used for storing dictionary (fast and efficient)used to dynamic spell check.\
     4. network routing algorithms.
- <ins>we can implement binary tree using</ins>:\
1.dynamically created Nodes\
2.array:
  - used for complete binary trees:
    > for node at index i\
    > left-child-index=(2i+1)\
    > right-child-index=(2i+2)   
- <ins>Table of complexities</ins>:\
Will be Updated 
#### Binary search tree:
a binary tree in which for each node value of all Nodes in left subtree is lesser or equal and
right subtree is greater   
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/BST.cpp)

#### MIN and MAX of BST 
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/min_max_BST.cpp)
#### Height of Binary Tree 
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/height_binaryTree.cpp)
#### Tree Traversals: Process to visit all the nodes in the tree exactly once
1.Breadth first: Level order (also called)
  - algo would be:

        taking a queue pushed with root intially and then 
        while queue is not empty:
            visit the first unvisited node and push its left and right into the queue
            and dequeue the visited node
  - complexities:
        time=O(n) because we need to traverse all the nodes\
        space=O(1)->best(in atree which is having all nodes having only one type of child),O(n)->worst/avg \
        [Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/levelorder.cpp)
        
2.Depth First: 
  > inorder `<left><root><right> (<left><data><right>)` LDR\
  > preorder `<root><left><right> (<data><left><right>)` DLR\
  > postorder `<left><right><root> (<left><right><data>)` LRD
  - inorder traversal of BST will give sorted list\
    [Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/dfs_BST.cpp)

#### Check if a binary tree is BST:
A binary tree which obeys BST restrictions will be BST
So, idea would taking an interval (-inf,+inf) and from root while traversing 
left the upperbound will be changed to prev node data and while going right the lower bound
will be changed to prev node data so while traversing we should check whether the node
present is in between the bounds or not 
- another way would be find the FindMax(leftsubtree) and findMin (rightsubtree)
then our root should be greater then the max and lesser then min then its BST\
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/check_BST.cpp)
#### Deleting a Node from BST:
deleteing a node would be tricky beacuase we may lose the property of BST\
case 1: if the node is leaf there is no change of property\
case 2: if the node is having only one child there is no change in property\
case 3: if the node is having 2 children then there is change in property
 - So,here in case 3 we can reduce it to case 2 by find min in the right
    subtree and copy the value in target node and delete the duplicate from right 
    sub tree which will be having only one child (case 2) (or) u can do vise versa i.e find the max from left subtree 
    copy the value in target node and delete the dupicate from left subtree
    which will be a leaf node of left subtree (case 1)\
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/Delete_BST.cpp)
#### inorderSuccessor in a BST:
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/inorderSuccessor_BST.cpp)

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

            struct Node{
                int data;
                Node * left;
                Node * right;
            }
- <ins>strict/proper bInary tree</ins>:\binary tree in which each Node has either 2 or 0 children
- <ins>complete Binary tree</ins>:\binary tree in which all levels are completely filled except
last level which is should be completely filled or all nodes are as left side as possible\
max No of Nodes at level i:2power(i)
- <ins>perfect binary tree</ins>:in which all levels are completely filled\
max no of Nodes in tree of height h=2power(h+1)-1=2power(No of levels )-1\
- <ins>Balanced Binary Tree</ins>: absolute difference between height of left and right sub tree for every Node is not more than 1(mostly 1)
- <ins>Appllication</ins>:\
1.storing natuarlly heirarchial data Ex: file system in ours computers
2. organize data for quick search,insertion and deletion Ex: Binary search trees(bst)
3. Trie: used for storing dictionary (fast and efficient)used to dynamic spell check
4. network routing algorithms
- <ins>we can implement binary tree using</ins>:\
1.dynamically created Nodes
2.arrays ( used for complete binary trees):

    for node at index i;
    left-child-index=2i+1
    right-child-index=2i+2
- <ins>Table of complexities</ins>:

- <ins>Binary search tree</ins>:\
a binary tree in which for each node value of all Nodes in left subtree is lesser or equal and
right subtree is greater   
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/BST.cpp)

- MIN and MAX of BST [Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/min_max_BST.cpp)
- Height of Binary Tree [Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/height_binaryTree.cpp)
- Tree Traversals: Process to visit all the nodes in the tree exactly once\
1.Breadth first: Level order (also called)
  - algo would be:

        taking a queue pushed with root intially and then 
        while queue is not empty:
            visit the first unvisited node and push its left and right into the queue
            and dequeue the visited node
  - complexities:
        time=O(n) because we need to traverse all the nodes\
        space=O(1)->best(in atree which is having all nodes having only one type of child),O(n)->worst/avg \
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Trees/levelorder.cpp)\
2.Depth First: 

    inorder <left><root><right> (<left><data><right>) LDR
    preorder <root><left><right> (<data><left><right>) DLR
    postorder <left><right><root> (<left><right><data>) LRD
  - inorder traversal of BST will give sorted list

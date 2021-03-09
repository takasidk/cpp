## stack 
implementation using arrays\
push,pop,top,isEMpty operations in O(1)constant time\
limitation:\
if we have large data to push then overflow may occur\
So,we can use dynamic array implementation where,we \
create a new array of double the prev size and copy \
the prev array in to the new array and delete the prev array\
But,the cost of the this is O(n) which is costly and Our push \
worst case time will be O(n) which we cant afford to do\
Stack implementation using linked list:
So,here we can have two options
1.insert/delete at tail
2.insert/delete at the beginning
But,at tail insertion and deletions we traverse 
the whole linked list which costs us O(n) time 
whic we cant afford
So, its straight forward to us we should do at the beginning

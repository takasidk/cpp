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
So, its straight forward to us we should do at the beginning\
writing expressions are of different ways
infix---> <operand>operator><operand>
Human readable But,we get ambiguity in solving
expersions are evaluated by BODMAS-operator precedence rules.
parentheses-->exponents(right to left)--> multliplication and 
division(left to right)--> addition and subtraction(left to right)
prefix--> <operator><operand><operand>
postfix--> <operand><operand><operator>
most prefered method beacause its fst and takes less space
and less ambiguity
example: conversion 
infix=a+(b*c)
infix to prefix   a+(b*c) --> a+(*bc) --> +a(*bc) --> +a*bc
infix to postfix a+(b*c) --> a+(bc*) --> a(bc*)+ --> abc*+
another example
a*b+c*d-e --> {(a*b)+(c*d)}-e --> {(ab*)+(c*d)}-e --> {(ab*)+(cd*)}-e
--> {(ab*)(cd*)+}-e --> {(ab*)(cd*)+}e- --> ab*cd*+e-
Evalution of prefix and Postfix
postfix:
find the first <operand><operand><operator> sequence from left
and evaluate them accordingly and repeat the steps untill no
operators are there in the expression
Ex:
(2,3,*,5,4,*,+,9,-) this is my postfix expression
--> 6,5,4,*,+,9,- --> 6,20,+,9,- --> 26,9,- --> 17
So,the idea to implement program will keeping a list of operands  and while 
iterating the expression and when we get operator then take 
the top two operands from the list and evaluate them with the
operator and push back into  the list.So, this type of list LiFO will be a stack
prefix:
conversion example--
(2,*,3,+,5,*,4,-,9) --> {(2*3)+(5*4)}-9 --> {(*2,3)+(5*4)}-9 
--> {(*2,3)+(*4,5)}-9 --> {+(*2,3)(*4,5)}-9 --> -{+(*2,3)(*4,5)}9
--> -,+,*,2,3,*4,5,9
evaluation:
so here similarly as postfix we will find first occuring 
<operator><operand><operand> sequence from right left iteration

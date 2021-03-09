## stack 
#### implementation using arrays:
push,pop,top,isEMpty operations in O(1)constant time\
limitation:\
if we have large data to push then overflow may occur So,we can use dynamic array implementation where,we 
create a new array of double the prev size and copy 
the prev array in to the new array and delete the prev array
But,the cost of the this is O(n) which is costly and Our push 
worst case time will be O(n) which we cant afford to do.\
[code](https://github.com/takasidk/cpp/blob/master/data_structures/Stack/stack_array.cpp)

---
#### Stack implementation using linked list:
So,here we can have two options\
1.insert/delete at tail\
2.insert/delete at the beginning\
But,at tail insertion and deletions we traverse 
the whole linked list which costs us O(n) time 
whic we cant afford
So, its straight forward to us we should do at the beginning\
[code](https://github.com/takasidk/cpp/blob/master/data_structures/Stack/stack_linkedlist.cpp)

---
#### infix,prefix and postfix:
writing expressions are of different ways
1.infix---> <operand>operator><operand>
Human readable But,we get ambiguity in solving
expersions are evaluated by BODMAS-operator precedence rules.
parentheses-->exponents(right to left)--> multliplication and 
division(left to right)--> addition and subtraction(left to right)
2.prefix--> <operator><operand><operand>
3.postfix--> <operand><operand><operator>
most prefered method beacause its fst and takes less space
and less ambiguity
example: conversion 
infix=a+(b*c)
'infix to prefix   a+(b*c) --> a+(*bc) --> +a(*bc) --> +a*bc'
'infix to postfix a+(b*c) --> a+(bc*) --> a(bc*)+ --> abc*+'
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
<operator><operand><operand> sequence from right left iteration\
  what ever the conversions we do , the order of operands will not be changed
so the algorithm to write a program to convert infix to postfix 
would be:
    while traversing the experssion given :
        if we get a operand:
            we append it to the postfix string
        else if we get a operator:
            if (stack empty) or we have a higher precedent operator at the top of stack:
                we push the operator into the stack
            else if we got a operator lower precedent then top elem in stack
                while stack not empty and our operator is lower precedent then top of stack elem
                    append the operator to the postfix and pop the elem in stack 
            then after push this operator into the stack
if(stack is not empty after all this):
    while stack is not empty:
        then append the top elem and pop 
finally output the postfix exp

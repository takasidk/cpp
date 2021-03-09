## Stack 
#### Implementation using arrays:
- push(),pop(),top(),isEmpty() operations in O(1)constant time\
**Limitation**:
- If we have large data to push then overflow may occur So,we can use dynamic array implementation where,we 
create a new array of double the prev size and copy 
the prev array in to the new array and delete the prev array
But,the cost of the this is O(n) which is costly and Our push 
worst case time will be O(n) which we cant afford to do.\
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Stack/stack_array.cpp)

---
#### Stack implementation using linked list:
- So,here we can have two options\
1.Insert/delete at tail\
2.Insert/delete at the beginning
- But,at tail insertion and deletions we traverse 
the whole linked list which costs us O(n) time 
which we cant afford
So, its straight forward to us we should do at the beginning\
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Stack/stack_linkedlist.cpp)

---
#### Reverse string using: [Code](https://github.com/takasidk/cpp/blob/master/data_structures/Stack/reverse_string.cpp)
#### Reverse linked list: [Code](https://github.com/takasidk/cpp/blob/master/data_structures/Stack/reverse_LL.cpp)
#### Balanced parentheses: [Code](https://github.com/takasidk/cpp/blob/master/data_structures/Stack/balanced_parentheses.cpp)
#### Infix,Prefix and Postfix:
Writing expressions are of different ways
1.Infix:
  `<operand>operator><operand>`
- Human readable But,we get ambiguity in solving,
expersions are evaluated by BODMAS-operator precedence rules.
- Order:Parentheses&#8594;Exponents(right to left)&#8594; Multliplication and 
Division(left to right)&#8594; Addition and Subtraction(left to right)\
2.Prefix &#8594; `<operator><operand><operand>`\
3.Postfix &#8594; `<operand><operand><operator>`\
- Most prefered method beacause its fast and takes less space
and less ambiguity
- Example: conversion 
> infix=a+(b*c)\
> infix to prefix=  a+(b*c) &#8594; a+(*bc) &#8594; +a(*bc) &#8594; +a*bc\
> infix to postfix= a+(b*c) &#8594; a+(bc*) &#8594; a(bc*)+ &#8594; abc*+
> 
- Another example
> a*b+c*d-e &#8594; {(a*b)+(c*d)}-e &#8594; {(ab*)+(c*d)}-e &#8594; {(ab*)+(cd*)}-e
> &#8594; {(ab*)(cd*)+}-e &#8594; {(ab*)(cd*)+}e- &#8594; ab*cd*+e-
> 
#### Evaluation of prefix and Postfix:
- Postfix:
Find the first `<operand><operand><operator>` sequence from left
and evaluate them accordingly and repeat the steps untill no
operators are there in the expression
- Ex:
> (2,3,*,5,4,*,+,9,-)
> &#8594; 6,5,4,*,+,9,- &#8594; 6,20,+,9,- &#8594; 26,9,- &#8594; 17
> 
- So,the idea to implement program will be keeping a list of operands  and while 
iterating the expression and when we get operator then take 
the top two operands from the list and evaluate them with the
operator and push back into  the list.So, this type of list LiFO will be a stack
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/Stack/evaluate.cpp)
#### Infix to Prefix:
- Prefix:
Conversion example
> (2,*,3,+,5,*,4,-,9) &#8594; {(2*3)+(5*4)}-9 &#8594; {(*2,3)+(5*4)}-9 
> &#8594; {(*2,3)+(*4,5)}-9 &#8594; {+(*2,3)(*4,5)}-9 &#8594; -{+(*2,3)(*4,5)}9
> &#8594; -,+,*,2,3,*4,5,9
- evaluation:
so here similarly as postfix we will find first occuring 
`<operator><operand><operand>` sequence from right to left iteration\
#### Infix to Postfix:
- what ever the conversions we do , the order of operands will not be changed
* So the pseudo code for our algoritm to convert infix to postfix would be:

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
  [Code](https://github.com/takasidk/cpp/blob/master/data_structures/Stack/infixToPostfix.cpp)


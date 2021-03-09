/*
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
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int perform(char c, int op2, int op1);
bool isNumeric(char c);
bool isOperator(char c);

bool isNumeric(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
    {
        return true;
    }
    return false;
}
int perform(char c, int op2, int op1)
{
    if (c == '+')
    {
        return op1 + op2;
    }
    else if (c == '*')
    {
        return op1 * op2;
    }
    else if (c == '-')
    {
        return op1 - op2;
    }
    else if (c == '/')
    {
        return op1 / op2;
    }
    return 0;
}
int evaluatePostfix(string exp, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == ' ' || exp[i] == ',')
        {
            continue;
        }
        else if (isOperator(exp[i]))
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            s.push(perform(exp[i], op2, op1));
        }
        else if (isNumeric(exp[i]))
        {
            int op = 0;
            while (i < n && isNumeric(exp[i]))
            {
                op = op * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            s.push(op);
        }
    }
    return s.top();
}

int main()
{
    string str;
    cout << "enter the expression with comma seperated or space seperated:" << endl;
    cin >> str;
    cout << evaluatePostfix(str, str.length()) << endl;
}
/*
out:
enter the expression with comma seperated or space seperated:
2,3,*,5,4,*,+,9,-
17
*/
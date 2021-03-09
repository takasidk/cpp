/*
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
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isHigher(char c1, char c2);
string conv(string exp, int n);
bool isOperator(char c);
bool isOpening(char c);
bool isclosing(char c);
bool isOpeningPair(char c1, char c2);
bool isOperand(char c);
int main()
{
    string str;
    cout << "enter the infix expression :" << endl;
    cin >> str;
    cout << "Postfix expression is:" << endl;
    cout << conv(str, str.length());
}
string conv(string exp, int n)
{
    stack<char> s;
    string res = "";
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(')
        {
            s.push(exp[i]);
        }
        else if (isOperator(exp[i]))
        {
            while (!s.empty() && !isHigher(exp[i], s.top()) && s.top() != '(')
            {
                res = res + s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                res = res + s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperand(exp[i]))
        {
            res = res + exp[i];
        }
    }
    while (!s.empty())
    {
        res = res + s.top();
        s.pop();
    }
    return res;
}
bool isOpening(char c)
{
    if (c == '(' || c == '{' || c == '[')
        return true;
    return false;
}
bool isclosing(char c)
{
    if (c == ')' || c == '}' || c == ']')
        return true;
    return false;
}
bool isOpeningPair(char c1, char c2)
{
    if (c1 == '{' && c2 == '}')
        return true;
    else if (c1 == '(' && c2 == ')')
        return true;
    else if (c1 == '[' && c2 == ']')
        return true;
    return false;
}
bool isOperator(char c)
{
    if (c == '+' || c == '*' || c == '/' || c == '-')
        return true;
    return false;
}
bool isHigher(char c1, char c2)
{
    if (c1 == '*')
        return true;
    else if (c1 == '/' && (c2 == '+' || c2 == '-'))
        return true;
    return false;
}
bool isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else if (c >= 'a' && c <= 'z')
        return true;
    else if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}
/*
out:
enter the infix expression :
((a+b)*c-d)*e
Postfix expression is:
ab+c*d-e*
*/
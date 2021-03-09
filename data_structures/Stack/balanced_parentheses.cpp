#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool arePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening = '{' && closing == '}')
        return true;
    else if (opening = '[' && closing == ']')
        return true;

    return false;
}
bool checkBp(string exp)
{
    stack<char> s;
    char opening, closing;
    for (char i : exp)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            s.push(i);
            //cout << "p"
            // << " ";
        }
        else if (i == ')' || i == '}' || i == ']')
        {
            if (s.empty())
            {
                return false;
            }
            else
            {
                opening = s.top();
                closing = i;
                if (arePair(opening, closing))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return s.empty() ? true : false;
}
int main()
{
    string exp;
    cout << "enter an expression:" << endl;
    cin >> exp;
    if (checkBp(exp))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
}
/*
out:
enter an expression:
[][]
p p Balanced
enter an expression:
{[()]}
p p p Balanced
enter an expression:
{[(]})
Not Balanced
*/
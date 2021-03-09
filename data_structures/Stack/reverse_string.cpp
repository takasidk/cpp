#include <iostream>
#include <stack>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
void reverse_stack(string &c, int n) //pass by reference
{
    /*
    O(n)-time
    O(n)-space complexity
    */
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        s.push(c[i]);
    }
    for (int i = 0; i < n; i++)
    {
        c[i] = s.top();
        s.pop();
    }
}
void reverse_2pointers(string &c, int n)
{
    int i = 0, j = n - 1;
    while (i <= j)
    {
        swap(c[i], c[j]);
        i++;
        j--;
    }
}
int main()
{
    string c;
    /*other way of input 
    char c[101];
    cin>>c; // cstring function strlen(c) gives length
    */
    cout << "enter the string" << endl;
    getline(cin, c);
    reverse_stack(c, c.size());
    cout << c << endl;
    cout << "by using 2 pointer method:" << endl;
    reverse_2pointers(c, c.length());
    cout << c << endl;
}
/*
out:
enter the string
dinesh
hsenid
by using 2 pointer method:
dinesh
*/
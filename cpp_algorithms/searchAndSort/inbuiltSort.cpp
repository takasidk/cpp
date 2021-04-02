#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;
struct Interval
{
    /* data */
    int start, end;
};
bool cmp(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
void solve()
{
    //code here:
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "sort in acsending order:";
    sort(arr, arr + n);
    for (auto i : arr)
    {
        cout << i << " " << endl;
    }
    int arrb[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    n = sizeof(arrb) / sizeof(arrb[0]);
    cout << "sort in descending order:";
    sort(arrb, arrb + n, greater<int>());
    for (auto i : arrb)
    {
        cout << i << " " << endl;
    }
    Interval arrc[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    n = sizeof(arrc) / sizeof(arrc[0]);
    cout << "sort using compare function:";
    sort(arrc, arrc + n, cmp);
    for (auto i : arrc)
    {
        cout << i.start << " " << i.end << " " << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    init();
#endif
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
/*
sort in acsending order:0 
1 
2 
3 
4 
5 
6 
7 
8 
9 
sort in descending order:9 
8 
7 
6 
5 
4 
3 
2 
1 
0 
sort using compare function:1 9 
2 4 
4 7 
6 8 
*/
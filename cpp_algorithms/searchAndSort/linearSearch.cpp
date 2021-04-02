#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int MAX = 100000;
void Search()
{
    int n;
    cin >> n;
    int arr[MAX];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    //code here:
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        if (arr[i] == x)
        {
            cout << "Found at index:" << i << endl;
            return;
        }
    }
    cout << -1 << " Not Found!" << endl;
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
        Search();
    return 0;
}
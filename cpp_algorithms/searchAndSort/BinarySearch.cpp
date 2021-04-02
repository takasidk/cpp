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
    //cout << n << "Sn";
    int arr[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        //cout << "s" << arr[i] << " " << endl;
    }
    int x;
    cin >> x;
    //code here:
    int l = 0;
    int r = n - 1;
    //cout << arr[n - 1] << endl;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            cout << "Found at index: " << mid << endl;
            return;
        }
        else if (arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "Notfound!" << endl;
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
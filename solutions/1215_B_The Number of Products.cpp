// Author - Vedant Valsangkar
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, x;
    cin >> n;
    int cur = 1, pos = 1, neg = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x < 0)
            cur *= -1;
        if (cur == 1)
            pos++;
        else
            neg++;
    }
    cout << pos * neg << " " << (n * (n + 1)) / 2 - pos * neg << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // sieve();
    int tc = 1;
    // cin>>tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
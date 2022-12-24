// Author - Vedant Valsangkar
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
const int N = 1e5 + 5;
int a[N], b[N], dp[N][3];

int rec(int i, int p)
{
    if (i == n)
        return 0;
    int &ans = dp[i][p];
    if (ans != -1)
        return ans;
    ans = rec(i + 1, 2);
    if (p != 1)
        ans = max(ans, rec(i + 1, 1) + a[i]);
    if (p != 0)
        ans = max(ans, rec(i + 1, 0) + b[i]);
    return ans;
}

void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cout << rec(0, 2);
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
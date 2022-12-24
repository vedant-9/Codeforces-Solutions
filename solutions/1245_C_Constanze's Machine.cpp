// Author - Vedant Valsangkar
#include <bits/stdc++.h>
using namespace std;

#define int long long

string s;
int n;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
int dp[N];

int rec(int idx)
{
    if (idx == n)
        return 1;
    int &ans = dp[idx];
    if (ans != -1)
        return ans;
    ans = rec(idx + 1);
    if (idx + 1 < n and s[idx] == s[idx + 1] and (s[idx] == 'u' or s[idx] == 'n'))
        ans = (ans + rec(idx + 2)) % M;
    return ans;
}

void solve()
{
    cin >> s;
    n = s.length();
    for (auto c : s)
    {
        if (c == 'm' or c == 'w')
        {
            cout << 0;
            return;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0);
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
// Author - Vedant Valsangkar
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n, wt[N], deg[N];

void solve()
{
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> wt[i], sum += wt[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    vector<int> add;
    for (int i = 1; i <= n; i++)
    {
        while (deg[i]-- > 1)
            add.push_back(wt[i]);
    }

    sort(add.rbegin(), add.rend());
    
    for (auto x : add)
    {
        cout << sum << " ";
        sum += x;
    }
    cout << sum;
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // sieve();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
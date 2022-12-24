// Author - Vedant Valsangkar
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> pos(k), tmp(k);
    for (auto &x : pos)
        cin >> x;
    for (auto &x : tmp)
        cin >> x;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        ans[pos[i]] = tmp[i];
        pq.push({tmp[i], pos[i]});
    }

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int t = cur.first;
        int x = cur.second;

        int i = x - 1, j = t + 1;
        while (i >= 1 and (ans[i] == 0 or ans[i] > j))
            ans[i] = j, i--, j++;
        i = x + 1, j = t + 1;
        while (i <= n and (ans[i] == 0 or ans[i] > j))
            ans[i] = j, i++, j++;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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
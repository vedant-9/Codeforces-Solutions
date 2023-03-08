// Author - Vedant Valsangkar
// 2023 CP GOALS - Expert at CF and Guardian at Leetcode
// I WILL MAKE IT HAPPEN
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long

set<int> st;
void dfs(int cur, int cnt4, int cnt7)
{
    if(cur > 1e10) return;
    if (cnt4 == cnt7)
        st.insert(cur);
    dfs(10 * cur + 4, cnt4 + 1, cnt7);
    dfs(10 * cur + 7, cnt4, cnt7 + 1);
}

void solve()
{
    int n;
    cin >> n;
    cout << *st.lower_bound(n) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dfs(0, 0, 0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}

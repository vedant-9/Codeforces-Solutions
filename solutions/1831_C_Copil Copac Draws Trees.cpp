// Author - Vedant Valsangkar
// BELIEVE
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int long long
#define rep(i, s, e) for (int i = s; i < e; i++)
#define repr(i, s, e) for (int i = s; i >= e; i--)
#define uniq(a) a.erase(unique(all(a)), a.end())
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define endl '\n'

template <typename T>
istream& operator>>(istream& istream, vector<T>& v) {
    for (auto& it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream& operator<<(ostream& ostream, const vector<T>& c) {
    for (auto& it : c)
        cout << it << " ";
    return ostream;
}

bool per_square(ld x) {
    if (x < 0) return 0;
    ll sr = sqrt(x);
    return (sr * sr == x);
}
bool is_prime(ll x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int dfs(int cur, int par, int prevIdx, vector<vector<pair<int, int>>>& adj) {
    int mx = 0;
    for (auto next : adj[cur]) {
        if (next.first == par) continue;
        mx = max(mx, (next.second < prevIdx) + dfs(next.first, cur, next.second, adj));
    }
    return mx;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }
    int ans = dfs(0, -1, -1, adj) + 1;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}

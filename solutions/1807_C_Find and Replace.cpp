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

class dsu {
   public:
    vector<int> par, sz;
    int comps;
    dsu(int n) {
        par.resize(n);
        sz.resize(n);
        comps = n;
        for (int i = 0; i < n; i++)
            par[i] = i, sz[i] = 1;
    }
    int find_set(int x) {
        if (par[x] == x) return x;
        return find_set(par[x]);
    }
    bool same_set(int x, int y) {
        return find_set(x) == find_set(y);
    }
    void union_sets(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        comps--;
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    dsu d(26);
    vector<int> vis(26, 0);
    rep(i, 0, n) {
        vis[s[i] - 'a'] = 1;
        if (i & 1)
            d.union_sets(s[1] - 'a', s[i] - 'a');
        else
            d.union_sets(s[0] - 'a', s[i] - 'a');
    }
    set<int> st;
    rep(i, 0, 26) {
        if (vis[i]) st.insert(d.find_set(i));
    }
    if (st.size() == 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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

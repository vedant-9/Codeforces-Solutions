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

int n, m;
vector<vector<int>> a;
int rec(int i, int j) {
    if (i < 0 or j < 0 or i >= n or j >= m or a[i][j] == 0) return 0;
    int x = a[i][j];
    a[i][j] = 0;
    return x + rec(i + 1, j) + rec(i - 1, j) + rec(i, j + 1) + rec(i, j - 1);
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    rep(i, 0, n) a[i].resize(m);
    rep(i, 0, n) cin >> a[i];

    int ans = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (a[i][j]) ans = max(ans, rec(i, j));
        }
    }
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

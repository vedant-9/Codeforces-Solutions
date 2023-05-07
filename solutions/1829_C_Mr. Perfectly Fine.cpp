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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<string> b(n);
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
    }
    int mn = 1e9;
    rep(i, 0, n) {
        if (b[i] == "11") mn = min(mn, a[i]);
    }
    int mn1 = 1e9, mn2 = 1e9;
    rep(i, 0, n) {
        if (b[i][0] == '1') mn1 = min(mn1, a[i]);
        if (b[i][1] == '1') mn2 = min(mn2, a[i]);
    }
    mn = min(mn, mn1 + mn2);
    if (mn >= 1e9) mn = -1;
    cout << mn << endl;
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

// Author - Vedant Valsangkar
// 2023 CP GOALS - Expert at CF and Guardian at Leetcode
// I WILL MAKE IT HAPPEN
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int long long
#define rep(i, s, e) for (int i = s; i < e; i++)
#define repr(i, s, e) for (int i = s; i >= e; i--)
#define in(a) \
    for (auto &i : a) cin >> i
#define out(a)                          \
    for (auto &i : a) cout << i << " "; \
    cout << endl
#define uniq(a) a.erase(unique(all(a)), a.end())
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define endl '\n'

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
    in(a);
    int neg = 0;
    for (auto x : a)
        if (x < 0) neg++;
    int k = 0;
    rep(i, 0, n) {
        if (i < n - neg)
            cout << ++k << " ";
        else
            cout << --k << " ";
    }
    cout << endl;
    k = 0;
    rep(i, 0, n) {
        if (neg)
            cout << 1 << " " << 0 << " ", i++, neg--;
        else
            cout << ++k << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}

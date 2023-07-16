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
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> t(n, vector<int>(m));
    rep(i, 0, n) cin >> t[i];
    sort(all(t[0]));
    int pt = 0, pen = 0, ct = 0, prev = 0;
    rep(j, 0, m) {
        ct += t[0][j];
        if (ct > h) break;
        pt++;
        pen += ct;
    }

    int ans = 1;
    rep(i, 1, n) {
        sort(all(t[i]));
        int ctx = 0, ptx = 0, penx = 0, prevx = 0;
        rep(j, 0, m) {
            ctx += t[i][j];
            if (ctx > h) break;
            ptx++;
            penx += ctx;
        }
        if (ptx > pt or (ptx == pt and penx < pen)) ans++;
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

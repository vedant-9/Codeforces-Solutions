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
    vector<vector<int>> a(n);
    rep(i, 0, n) {
        int k;
        cin >> k;
        a[i].resize(k);
        cin >> a[i];
    }
    set<int> st;
    for (auto x : a[n - 1]) st.insert(x);
    vector<int> ans;
    ans.push_back(*st.begin());
    repr(i, n - 2, 0) {
        int f = 1;
        for (auto x : a[i]) {
            if (st.insert(x).second and f) {
                ans.push_back(x);
                f = 0;
            }
        }
        if (f == 1) {
            cout << -1 << endl;
            return;
        }
    }
    reverse(all(ans));
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

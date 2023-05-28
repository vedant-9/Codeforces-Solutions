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
    vector<int> a(n), b(n);
    cin >> a >> b;
    map<int, int> mxA, mxB;
    int i = 0;
    while (i < n) {
        int val = a[i], c = 0;
        while (i < n and val == a[i]) i++, c++;
        if (mxA.find(val) == mxA.end())
            mxA[val] = c;
        else
            mxA[val] = max(mxA[val], c);
    }
    i = 0;
    while (i < n) {
        int val = b[i], c = 0;
        while (i < n and val == b[i]) i++, c++;
        if (mxB.find(val) == mxB.end())
            mxB[val] = c;
        else
            mxB[val] = max(mxB[val], c);
    }
    int ans = 0;
    for (auto x : mxA) {
        if (mxB.find(x.first) != mxB.end()) {
            ans = max(ans, x.second + mxB[x.first]);
        } else {
            ans = max(ans, x.second);
        }
    }
    for (auto x : mxB) {
        ans = max(ans, x.second);
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

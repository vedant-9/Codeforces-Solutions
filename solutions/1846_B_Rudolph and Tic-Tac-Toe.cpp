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
    vector<string> a(3);
    cin >> a;
    rep(i, 0, 3) {
        if (a[i][0] != '.' and a[i][0] == a[i][1] and a[i][1] == a[i][2]) {
            cout << a[i][0] << endl;
            return;
        }
        if (a[0][i] != '.' and a[0][i] == a[1][i] and a[1][i] == a[2][i]) {
            cout << a[0][i] << endl;
            return;
        }
        if (a[0][0] != '.' and a[0][0] == a[1][1] and a[1][1] == a[2][2]) {
            cout << a[0][0] << endl;
            return;
        }
        if (a[2][0] != '.' and a[0][2] == a[1][1] and a[1][1] == a[2][0]) {
            cout << a[0][2] << endl;
            return;
        }
    }
    cout << "DRAW\n";
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

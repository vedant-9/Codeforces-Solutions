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
    int x;
    cin >> x;
    if (x <= 2) {
        cout << -1 << endl;
    } else if (x % 3 == 0) {
        int y = x / 3;
        cout << 4 * y << " " << 5 * y << endl;
    } else if (x % 4 == 0) {
        int y = x / 4;
        cout << 3 * y << " " << 5 * y << endl;
    } else if (x % 5 == 0) {
        int y = x / 5;
        cout << 3 * y << " " << 4 * y << endl;
    } else {
        if (x % 2 == 0) {
            int y = (x / 2) * (x / 2);
            cout << y - 1 << " " << y + 1 << endl;
        } else {
            cout << x * x / 2 << " " << x * x / 2 + 1 << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}

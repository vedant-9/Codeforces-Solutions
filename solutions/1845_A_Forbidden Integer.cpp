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
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES\n";
        cout << n << endl;
        rep(i, 0, n) cout << 1 << " ";
        cout << endl;
    } else {
        if (n % 2 != 0) {
            if (k < 3)
                cout << "NO\n";
            else {
                cout << "YES\n";
                vector<int> ans;
                ans.push_back(3);
                n -= 3;
                while (n) ans.push_back(2), n -= 2;
                cout << ans.size() << endl;
                cout << ans << endl;
            }
        } else {
            if (k < 2)
                cout << "NO\n";
            else {
                cout << "YES\n";
                vector<int> ans;
                while (n) ans.push_back(2), n -= 2;
                cout << ans.size() << endl;
                cout << ans << endl;
            }
        }
    }
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

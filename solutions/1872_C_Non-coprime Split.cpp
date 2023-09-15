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

const int maxN = 1e7 + 5;
vector<int> primes;
vector<int> pre(maxN + 1, 0);
vector<bool> spf(maxN + 1, true);
void sieve() {
    int n = maxN;
    spf[0] = spf[1] = 0;
    for (int p = 2; p * p <= n; p++) {
        if (spf[p]) {
            for (int i = p * p; i <= n; i += p)
                spf[i] = 0;
        }
    }
    for (int p = 2; p <= n; p++)
        if (spf[p]) primes.push_back(p);
}

void solve() {
    int l, r;
    cin >> l >> r;
    if (l == r and l & 1) {
        if (spf[l])
            cout << -1 << endl;
        else {
            for (auto x : primes) {
                if (l % x == 0) {
                    cout << x << " " << l - x << endl;
                    return;
                }
            }
            cout << -1 << endl;
        }
    } else {
        if (r & 1) r--;
        if (r == 2)
            cout << -1 << endl;
        else
            cout << r / 2 << " " << r / 2 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}

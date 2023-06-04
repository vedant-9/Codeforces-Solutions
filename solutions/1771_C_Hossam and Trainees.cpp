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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / (gcd(a, b)); }

bool check(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(a[i], a[j]) > 1) return 1;
        }
    }
    return 0;
}

const int maxN = 1e6 + 5;
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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    // cout << (check(a, n) ? "YES" : "NO") << endl;

    set<int> seen;
    for (auto x : a) {
        for (auto p : primes) {
            if (p * p > x) break;
            if (x % p == 0) {
                if (seen.find(p) != seen.end()) {
                    cout << "YES\n";
                    return;
                }
                seen.insert(p);
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) {
            if (seen.find(x) != seen.end()) {
                cout << "YES\n";
                return;
            }
            seen.insert(x);
        }
    }
    cout << "NO\n";
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

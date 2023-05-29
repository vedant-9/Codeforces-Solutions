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

const ll M = 1e9 + 7;
// const ll M = 998244353;
ll mod(ll a) { return ((a + M) % M); }
ll mod_add(ll a, ll b) {
    a = a % M;
    b = b % M;
    return (((a + b) % M) + M) % M;
}
ll mod_sub(ll a, ll b) {
    a = a % M;
    b = b % M;
    return (((a - b) % M) + M) % M;
}
ll mod_mul(ll a, ll b) {
    a = a % M;
    b = b % M;
    return (((a * b) % M) + M) % M;
}
ll mod_pow(ll a, ll b) {
    ll t = 1;
    while (b > 0) {
        if (b & 1) t = (t * a) % M;
        b /= 2;
        a = (a * a) % M;
    }
    return t % M;
}
ll mod_div(ll a, ll b) {
    a = a % M;
    b = b % M;
    return mod_mul(a, mod_pow(b, M - 2));
}
ll mod_inv(ll a) { return mod_pow(a, M - 2); }

void solve() {
    // 9 6 8 4 5 2
    // 4 1 5 6 3 1

    // 2 4 5 6 8 9
    // 1 1 3 4 5 6

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    sort(all(a));
    sort(all(b));
    int ans = 1, j = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            ans = 0;
            break;
        }
        while (j < n and a[i] > b[j]) {
            j++;
            cnt++;
        }
        ans = mod_mul(ans, cnt);
        cnt--;
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

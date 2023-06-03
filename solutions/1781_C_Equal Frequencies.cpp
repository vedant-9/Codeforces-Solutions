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
    string s;
    cin >> s;

    vector<pair<int, int>> count(26);
    for (int i = 0; i < 26; i++) count[i] = {0, i};
    for (int i = 0; i < n; i++) count[s[i] - 'a'] = {count[s[i] - 'a'].first + 1, s[i] - 'a'};
    sort(allr(count));

    // i - no of distinct chars
    // n/i - no of count of each char
    int min_ops = n, min_ops_i = -1;
    for (int i = 1; i <= min(n, 26LL); i++) {
        if (n % i != 0) continue;
        int ops = 0, req_cnt = n / i;
        for (int j = 0; j < i; j++) {
            if (count[j].first > req_cnt) ops += (count[j].first - req_cnt);
        }
        for (int j = i; j < 26; j++) {
            ops += count[j].first;
        }
        if (ops < min_ops) {
            min_ops = ops;
            min_ops_i = i;
        }
    }

    cout << min_ops << endl;
    // cout << min_ops_i << endl;

    int cnt = n / min_ops_i;
    vector<int> freq(26, 0);
    for (int j = 0; j < min_ops_i; j++) freq[count[j].second] = cnt;

    vector<int> vis(n, 0);
    rep(i, 0, n) {
        if (freq[s[i] - 'a']) {
            freq[s[i] - 'a']--;
            vis[i] = 1;
        }
    }

    // cout << freq << endl;

    int j = 0;
    rep(i, 0, n) {
        if (!vis[i]) {
            while (j < 26 and !freq[j]) j++;
            s[i] = (char)('a' + j);
            freq[j]--;
        }
    }

    cout << s << endl;
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

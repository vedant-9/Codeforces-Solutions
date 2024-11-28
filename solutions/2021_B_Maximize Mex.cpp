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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    // It will cause TLE for case - 
    // priority_queue<int, vector<int>, greater<int>> pq;
    // rep(i, 0, n) pq.push(a[i]);

    // int mex = 0;
    // while (mex < n) {
    //     if (pq.top() > mex) break;
    //     if (pq.top() == mex) {
    //         mex++;
    //         pq.pop();
    //     } else {
    //         int top = pq.top();
    //         int d = (mex - top + x - 1) / x;
    //         pq.pop();
    //         pq.push(top + d * x);
    //     }
    // }
    // cout << mex << endl;

    vector<int> freq(n+1, 0);
    rep(i, 0, n) {
        if(a[i] < n) freq[a[i]]++;
    }

    int mex = 0;
    while (mex < n) {
        if(freq[mex] == 0) break;
        if(freq[mex] > 0) {
            int d = freq[mex];
            if(mex + x < n) freq[mex + x] += d-1;
        }
        mex++;
    }

    cout << mex << endl;
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

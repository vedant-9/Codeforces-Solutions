// Author - Vedant Valsangkar
// 2023 CP GOALS - Expert at CF and Guardian at Leetcode
// I WILL MAKE IT HAPPEN
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 1) a[i]++;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] % a[i - 1] == 0) a[i]++;
    }
    for (auto x : a) cout << x << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}

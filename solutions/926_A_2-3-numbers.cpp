// Author - Vedant Valsangkar
// 2023 CP GOALS - Expert at CF and Guardian at Leetcode
// I WILL MAKE IT HAPPEN
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long

void solve() {
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            int x = pow(2, i) * pow(3, j);
            if (l <= x and x <= r) cnt++;
        }
    }
    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}

// Author - Vedant Valsangkar
// 2023 CP GOALS - Expert at CF and Guardian at Leetcode
// I WILL MAKE IT HAPPEN
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long

bool is_palindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    for (int i = 0; i < 2 * n - 2; i++) {
        string x;
        cin >> x;
        if (x.length() == n - 1) {
            if (s == "")
                s = x;
            else
                t = x;
        }
    }
    if (s.substr(1) == t.substr(0, n - 2)) {
        s += t;
        if (is_palindrome(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    } else {
        t += s;
        if (is_palindrome(t))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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

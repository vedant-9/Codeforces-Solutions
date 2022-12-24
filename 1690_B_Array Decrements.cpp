#include <bits/stdc++.h>
using namespace std;

#define     int         long long
#define     pb          push_back
#define     size(x)     (int)((x).size())
#define     memf(a)     memset(a,false,sizeof(a))
#define     F           first
#define     S           second
#define     all(v)      v.begin(),v.end()
#define     fr(i, n)    for(int i=0;i<n;i++)
#define     tr(v)       for(auto it=v.begin();it!=v.end();it = next(it))

const int inf = 1e16;
const int N = 1e5 + 1;
const int mod = 1e9 + 7;

void solve() {
	int n; cin >> n;
	int a[n], b[n];
	fr(i, n) cin >> a[i];
	fr(i, n) cin >> b[i];

	set<int> s;
	int mx = -1;
	fr(i, n) {
		if (b[i] > a[i]) {
			cout << "No\n"; return;
		}
		if (b[i] != 0) {
			s.insert(a[i] - b[i]);
		}
		else {
			mx = max(mx, a[i]);
		}
	}

	if (size(s) > 1) {
		cout << "No\n";
		return;
	}

	if (s.empty() or mx <= *s.begin()) {
		cout << "Yes\n";
		return;
	}

	cout << "No\n";
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}
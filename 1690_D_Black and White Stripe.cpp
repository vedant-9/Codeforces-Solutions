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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int z = 0, mx = k;
	fr(i, k) if (s[i] == 'W') z++;
	mx = z;
	for (int i = k; i < n; i++) {
		if (s[i - k] == 'W') z--;
		if (s[i] == 'W') z++;
		mx = min(mx, z);
	}
	cout << mx << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define tc     \
	int tt;    \
	cin >> tt; \
	while (tt--)
#define in(arr, n)              \
	for (int i = 0; i < n; i++) \
	cin >> arr[i]
#define out(arr, n)             \
	for (int i = 0; i < n; i++) \
	cout << arr[i] << " "
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// #ifndef ONLINE_JUDGE
	//     freopen("in.txt","r",stdin);
	//     freopen("out.txt","w",stdout);
	// #endif
	int n;
	cin >> n;
	if (n % 2 == 0 && n>2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
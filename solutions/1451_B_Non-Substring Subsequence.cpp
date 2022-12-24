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
	tc
	{
		int n, q;
		cin >> n >> q;

		string s;
		cin >> s;

		int min0, max0, min1, max1;

		min0 = s.find('0');
		max0 = s.rfind('0');
		min1 = s.find('1');
		max1 = s.rfind('1');

		int l, r, flag;
		while (q--)
		{
			cin >> l >> r;
			l--;
			r--;

			int i,flag=0;

			if (s[l] == '0')
			{
				if (min0 < l)
					flag = 1;
			}
			else
			{
				if (min1 < l)
					flag = 1;
			}
			if (s[r] == '0')
			{
				if (max0 > r)
					flag = 1;
			}
			else
			{
				if (max1 > r)
					flag = 1;
			}

			if (flag == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}

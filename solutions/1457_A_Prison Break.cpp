#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define tc int tt; cin>>tt; while(tt--)
#define in(arr, n) for(int i=0; i<n; i++) cin>>arr[i]
#define out(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" "
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n,m,r,c;

	tc
	{
		cin>>n>>m>>r>>c;
		ll res,x,y;

		if(r>n/2)
			x = 1;
		else
		{
			x = n;
		}
		if(c>m/2)
			y = 1;
		else
		{
			y = m;
		}
		
		res = abs(r-x) + abs(y-c);

		cout<<res<<endl;
	}

	return 0;
}
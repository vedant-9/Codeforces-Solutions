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
	cin.tie(NULL);
	tc
	{
		ll n;
		cin>>n;
		int ans=0;
		if(n==1)
			ans = 0 ;
		else if(n==2)
			ans = 1 ;
		else if(n==3 || n%2==0)
			ans = 2 ;
		else
			ans = 3;
		cout<<ans<<endl;
	}

	return 0;
}
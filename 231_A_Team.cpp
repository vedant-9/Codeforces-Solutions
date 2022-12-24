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

	int res=0;
	tc
	{
		int a,b,c;
		cin>>a>>b>>c;

		if(!((a==0 && b==0) || (b==0 && c==0) || (c==0 && a==0)))
			res++;
	}
	cout<<res<<endl;
	return 0;
}
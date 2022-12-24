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
		int n;
		cin>>n;

		cout<<n<<" ";
		for(int i=1;i<n;i++)
			cout<<i<<" ";
		cout<<endl;

	}

	return 0;
}
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

	int n,m;
	cin>>n>>m;

	int *A = new int[n];
	in(A,n);

	int res = 0;
	for(int i=0;i<n;i++)
	{
		if(A[i]>=A[m-1] && A[i]!=0)
			res++;
	} 
	cout<<res<<endl;

	return 0;
}
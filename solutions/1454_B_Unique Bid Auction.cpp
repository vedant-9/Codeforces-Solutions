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

		int *A = new int[n];
		in(A,n); 

		map<int,int> M;
		int i;
		for(i=0;i<n;i++)
		{	
			if(M.find(A[i])==M.end())
				M.insert(make_pair(A[i],1));
			else
			{
				M[A[i]]++;
			}
		}	
		map<int, int>::iterator itr; 
		int min = INT32_MAX;
		for (itr = M.begin();itr!=M.end();itr++)
		{
			if(itr->second==1 && itr->first<min)
				min = itr->first;
		}
		if(min==INT32_MAX)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(min==A[i])
			{
				cout<<i+1<<endl;
				break;
			}
		}
	}

	return 0;
}
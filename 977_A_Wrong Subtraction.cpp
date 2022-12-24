#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k;
	cin>>n>>k;

	for(int i=0;i<k;i++)
	{
		if(n%10==0)
			n /= 10;
		else
			n -= 1;
	}
	cout<<n<<endl;
	
	return 0;
}
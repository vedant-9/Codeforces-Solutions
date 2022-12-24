#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,a;
	cin>>n>>m>>a;
	
	int res,t=0,p=0;
	if(n%a!=0)
		t=1;
	if(m%a!=0)
		p=1;
	res = (n/a+t) * (m/a+p);  
	
	cout<<res<<endl;

	return 0;
}
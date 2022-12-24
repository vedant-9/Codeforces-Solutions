#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin>>tt;
	while (tt--)
	{
		string s;
		cin>>s;
		int l=s.length();
		if(l<=10)
		{
			cout<<s<<endl;
		}
		else
		{
			cout<<s[0]<<l-2<<s[l-1]<<endl;
		}
	}

	

	return 0;
}
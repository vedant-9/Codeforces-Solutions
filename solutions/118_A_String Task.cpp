// #include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin>>s;

	int i,j=0;

	char s2[300];
	string q = "AEYIOUaeyiou";
	for(i=0;i<s.length();i++)
	{
		if(q.find(s[i])== string::npos)
		{
			s2[j++] = '.';
			if(s[i]>='A' && s[i]<='Z')
				s[i] += 32;
			s2[j++] = s[i];
		}
	}
	s2[j] = '\0';
	cout<<s2<<endl;
	return 0;
}
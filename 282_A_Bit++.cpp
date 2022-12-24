#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt;
    cin>>tt;
    long long x=0;
    while(tt--)
    {
        string s;
        cin>>s;
        if(s.find("++")!=std::string::npos)
            x++;
        else
            x--;
    }
    cout<<x<<endl;
    return 0;
}
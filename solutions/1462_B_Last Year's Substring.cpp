#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define tc int tt; cin>>tt; while(tt--)
#define in(arr, n) for(ll i=0; i<n; i++) cin>>arr[i]
#define out(arr, n) for(ll i=0; i<n; i++) cout<<arr[i]<<" "
#define pb push_back

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    string s;
    tc
    {
        cin>>n>>s;

        if(s.find("2020")==0 || s.rfind("2020")==n-4)
        {
            cout<<"YES"<<endl;
            continue;
        }
        
        if(s.find("2")==0 && s.rfind("020")==n-3)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(s.find("20")==0 && s.rfind("20")==n-2)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(s.find("202")==0 && s.rfind("0")==n-1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define tc int tt; cin>>tt; while(tt--)
#define in(arr, n) for(ll i=0; i<n; i++) cin>>arr[i]
#define out(arr, n) for(ll i=0; i<n; i++) cout<<arr[i]<<" "
#define pb push_back

using namespace std;

void solve()
{
    ll w,h,n;
    cin>>w>>h>>n;
    ll s = 1;
    if(n==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    while(w%2==0 || h%2==0)
    {
        if(w%2==0)
            w/=2;
        else if(h%2==0)
            h/=2;
        s *= 2;
    }
    if(s>=n)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}

int main()
{
    fastio;

    tc
    {
        solve();
    }

    return 0;
}
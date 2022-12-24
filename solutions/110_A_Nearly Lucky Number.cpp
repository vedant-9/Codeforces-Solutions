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
    string s;
    cin>>s;
    ll n = count(s.begin(),s.end(),'4');
    n += count(s.begin(),s.end(),'7');
    if(n==4 || n==7)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main()
{
    fastio;

    solve();

    return 0;
}
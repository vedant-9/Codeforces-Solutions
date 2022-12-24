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
    ll n;
    cin>>n;
    cout<<ceil(n*1.0/5)<<endl;
}

int main()
{
    fastio;

    // tc
    // {
    //     solve();
    // }

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef set<ll> sll;
typedef map<ll,ll> mll;
typedef map<string,ll> msl;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define tc int tt; cin>>tt; while(tt--)
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repr(i,s,e) for(ll i=s;i>=e;i--)
#define in(arr) for(auto &i : arr) cin>>i
#define out(arr) for(auto &i : arr) cout<<i<<" "
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define bs binary_search

void solve()
{
    ll a,b,n,i=0;
    cin>>a>>b>>n;
    while(a<=n && b<=n)
    {
        if(a<b)
            a+=b;
        else
        {
            b += a;
        }
        i++;
    }
    cout<<i<<endl;
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
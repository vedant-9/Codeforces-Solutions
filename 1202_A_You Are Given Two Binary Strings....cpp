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
#define setbits __bulitin_popcount
#define bs binary_search

void solve()
{
    string a,b;
    cin>>a>>b;
    ll s=0, m=0;
    while(b[b.size()-1-s]=='0')
        s++;
    // cout<<s<<endl;
    while(a[a.size()-1-s-m]=='0')
        m++;
    cout<<m<<endl;
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
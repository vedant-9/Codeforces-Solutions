// Author - Vedant Valsangkar
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef long long    ll;
typedef long double  ld;
#define int          long long
#define rep(i,s,e)   for(int i=s;i<e;i++)
#define repr(i,s,e)  for(int i=s;i>=e;i--)
#define in(a)        for(auto &i:a) cin>>i
#define out(a)       for(auto &i:a) cout<<i<<" "; cout<<endl
#define uniq(a)      a.erase(unique(all(a)),a.end())
#define all(a)       a.begin(),a.end()
#define allr(a)      a.rbegin(),a.rend()
#define endl         '\n'

bool per_square(ld x){if(x<0) return 0; ll sr=sqrt(x); return (sr*sr==x);}
bool is_prime(ll x){for(int i=2;i*i<=x;i++) if(x%i==0) return 0; return 1;}

void solve()
{
    int n,k; cin>>n>>k;
    int a[n][n]; memset(a,0,sizeof(a));
    int i=0,j=0;
    while(k--) {
        a[i][j]=1;
        i++,j++; j%=n;
        if(i==n) i=0,j++,j%=n;
    }
    int mxr=0,mnr=n,mxc=0,mnc=n;
    rep(i,0,n) {
        int c1=0,c2=0;
        rep(j,0,n) if(a[i][j]) c1++;
        rep(j,0,n) if(a[j][i]) c2++;
        mxr=max(mxr,c1);
        mnr=min(mnr,c1);
        mxc=max(mxc,c2);
        mnc=min(mnc,c2);
    }
    cout<<(mxr-mnr)*(mxr-mnr)+(mxc-mnc)*(mxc-mnc)<<endl;
    rep(i,0,n) {
        rep(j,0,n) cout<<a[i][j]; cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
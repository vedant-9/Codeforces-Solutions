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
bool is_prime(ll x){rep(i,2,sqrt(x)+1) if(x%i==0) return 0; return 1;}

void solve()
{
    int n,x; cin>>n>>x; vector<pair<int,int>> a(n);
    rep(i,0,n) cin>>a[i].first>>a[i].second;
    int idx=-1,f=0,mxd=-1,mx=-1;
    rep(i,0,n) {
        if(a[i].first>=x) { f=1; break;}
        mx=max(mx,a[i].first);
        int d=a[i].first-a[i].second;
        if(d>0) {
            if(d>mxd) mxd=d,idx=i;
            else if(d==mxd and a[i].first>a[idx].first) idx=i;
        }
    }
    if(f) cout<<1<<endl;
    else if(idx!=-1) {
        x-=mx;
        int ans=1+x/mxd+(x%mxd!=0); 
        cout<<ans<<endl;
    } else cout<<-1<<endl;
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
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
    int n; cin>>n;
    vector<int> a(n),b(n); in(a); in(b);
    int ans=abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
    int mnv1,mnv2,mnv3,mnv4;
    mnv1=mnv2=mnv3=mnv4=INT_MAX;
    rep(i,0,n) mnv1=min(mnv1,abs(a[0]-b[i])); 
    rep(i,0,n) mnv2=min(mnv2,abs(b[0]-a[i])); 
    rep(i,0,n) mnv3=min(mnv3,abs(a[n-1]-b[i])); 
    rep(i,0,n) mnv4=min(mnv4,abs(b[n-1]-a[i])); 
    ans=min(ans,abs(a[0]-b[0])+abs(a[n-1]-b[n-1]));
    ans=min(ans,abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));
    ans=min(ans,abs(a[0]-b[0])+mnv4+mnv3); 
    ans=min(ans,abs(a[n-1]-b[n-1])+mnv1+mnv2); 
    ans=min(ans,abs(a[0]-b[n-1])+mnv2+mnv3); 
    ans=min(ans,abs(a[n-1]-b[0])+mnv1+mnv4); 
    ans=min(ans,mnv1+mnv2+mnv3+mnv4); // 😒😒😒😒😒
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    cin>>tc;
    for(int t=1;t<=tc;t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
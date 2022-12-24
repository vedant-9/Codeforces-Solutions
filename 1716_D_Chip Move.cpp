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

// const ll M = 1e9+7;
const ll M = 998244353;
ll mod(ll a){return ((a+M)%M);}
ll mod_add(ll a,ll b){a=a%M;b=b%M;return(((a+b)%M)+M)%M;}
ll mod_mul(ll a,ll b){a=a%M;b=b%M;return(((a*b)%M)+M)%M;}
ll mod_sub(ll a,ll b){a=a%M;b=b%M;return(((a-b)%M)+M)%M;}
ll mod_pow(ll a,ll b){ll t=1; while(b>0){if(b&1) t=(t*a)%M; b/=2; a=(a*a)%M;}return t%M;}

void solve()
{
    int n,k; cin>>n>>k;
    vector<int> ways(n+1,0), prev(n+1,0);
    prev[0] = 1;
    while(1) {
        vector<int> cur(n+1,0);
        for(int i=0; i<=n-k; i++) {
            cur[i+k] = mod_add(cur[i],prev[i]);
        }
        if(cur == prev) break;
        prev = cur;
        rep(i,1,n+1) ways[i] = mod_add(ways[i],prev[i]);
        k++;
    }
    rep(i,1,n+1) cout<<ways[i]<<" ";
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    // cin>>tc;
    for(int t=1;t<=tc;t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
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

const int N=2e5+5;
int n; string s;
map<char,int> m = {{'R',0},{'G',1},{'B',2}};
map<int,char> rm = {{0,'R'},{1,'G'},{2,'B'}};
int b[N],dp[N][4];

int rec(int idx,int prev) {
    if(idx==n) return 0;
    if(dp[idx][prev]!=-1) return dp[idx][prev];
    int ans=INT_MAX;
    rep(i,0,3) {
        if(i!=prev) ans=min(ans,rec(idx+1,i)+(i!=b[idx])); 
    }
    return dp[idx][prev]=ans;
}

void path(int idx,int prev) {
    if(idx==n) return;
    int ans=dp[idx][prev];
    rep(i,0,3) {
        if(i!=prev and ans==(i!=b[idx])+rec(idx+1,i)) {
            cout<<rm[i]; path(idx+1,i); return;
        }
    }
}

void solve()
{
    cin>>n>>s; memset(dp,-1,sizeof(dp));
    rep(i,0,n) {
        b[i]=m[s[i]];
    }
    int ans=rec(0,3);
    cout<<ans<<endl;
    path(0,3);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    // cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
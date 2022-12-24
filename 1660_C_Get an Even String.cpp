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

const int N=2e5+5;
string s;
int n;
vector<int> r;
int dp[N];

int rec(int idx) {
    if(idx==n) return 0;
    int &ans=dp[idx];
    if(ans!=-1) return ans;
    ans=INT_MAX;
    int next=r[idx];
    if(next!=-1) ans=rec(next+1)+(next-idx-1);
    ans=min(ans,rec(idx+1)+1);    
    return ans;
}

void solve()
{
    cin>>s; n=s.size(); r.clear(); r.resize(n); memset(dp,-1,sizeof(dp));
    vector<int> pos(26,-1);
    repr(i,n-1,0) {
        r[i] = pos[s[i]-'a'];
        pos[s[i]-'a'] = i;
    }
    cout<<rec(0)<<endl;
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
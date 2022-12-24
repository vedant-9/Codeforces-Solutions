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

vector<vector<int>> adj;
vector<int> leaves;
int intersection=0; 
void dfs(int cur, int par) {
    int deg=0;
    for(auto next:adj[cur]) {
        if(next==par) continue;
        dfs(next,cur);
        deg++;
    }
    if(!deg) leaves.push_back(cur);
}

void solve()
{
    int n,cnt=0; cin>>n; adj.resize(n);
    rep(i,0,n-1) {
        int u,v; cin>>u>>v; u--,v--; adj[u].push_back(v); adj[v].push_back(u);
    }
    rep(i,0,n) {
        if(cnt>1) {
            cout<<"No\n"; return;
        }
        if(adj[i].size()>2) {
            cnt++; intersection=i;
        }
    }
    if(cnt>1) {
        cout<<"No\n"; return;
    }
    cout<<"Yes\n";
    dfs(intersection,-1);
    cout<<leaves.size()<<endl;
    for(auto l:leaves) {
        cout<<intersection+1<<" "<<l+1<<endl;
    }
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
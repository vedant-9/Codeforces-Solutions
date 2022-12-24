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

const int N = 2e5+5;
int n;
vector<int> adj[N];
vector<vector<int>> res;
int vis[N];

void dfs(int cur, vector<int> &tmp) {
    vis[cur]=1;
    for(auto next:adj[cur]) {
        if(!vis[next]) {
            tmp.push_back(next+1);
            dfs(next,tmp);
            tmp.clear();
        }
    }
    if(!tmp.empty()) res.push_back(tmp);
}

void solve()
{
    cin>>n; res.clear(); 
    rep(i,0,n) adj[i].clear(),vis[i]=0;
    int root=-1;
    rep(i,0,n) {
        int x; cin>>x; x--;
        if(x!=i) {
            adj[x].push_back(i);
        } else {
            root=i;
        }
    }
    // rep(i,0,n) {
    //     cout<<i<<" -> "; out(adj[i]);
    // }
    vector<int> tmp; tmp.push_back(root+1);
    dfs(root,tmp);
    cout<<res.size()<<endl;
    for(auto v:res) {
        cout<<v.size()<<endl;
        out(v);
    }
    cout<<endl;
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
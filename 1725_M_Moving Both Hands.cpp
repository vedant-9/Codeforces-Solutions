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

const int N = 1e6+5;
const int INF = 1e18;

vector<int> dijkstra(int src, vector<vector<pair<int,int>>> &adj) {
    int n=adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> vis(n,0); vector<int> ans(n,INF); pq.push({0,src});
    while(!pq.empty()) {
        auto cur=pq.top(); pq.pop();
        if(vis[cur.second]) continue;
        vis[cur.second]=1; ans[cur.second]=cur.first;
        for(auto x:adj[cur.second]) {
            if(!vis[x.first]) pq.push({cur.first+x.second,x.first});
        }
    }
    return ans;
}

void solve()
{
    // let v be middle vertex where two hands meet
    // d(1,p) = short(1,v) + short(p,v)
    // d(1,p) = short(1,v) + short'(v,p)(in reverse graph)
    // no need for v
    // add short(1,v) dist to reverse graph for any different vertex(n)
    // d(1,p) = short'(n,p)  ... (in reverse graph)
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    vector<vector<pair<int,int>>> adj2(n+1);
    rep(i,0,m) {
        int u,v,w; cin>>u>>v>>w; u--; v--;
        adj[u].push_back({v,w});
        adj2[v].push_back({u,w});
    }
    // add min dist direct edges into nth vertex to reverse graph 
    auto dr = dijkstra(0, adj);
    rep(i,0,n) {
        adj2[n].push_back({i,dr[i]});
    }
    // normal dijkstra from nth vertex to each p
    auto ans = dijkstra(n, adj2);
    rep(i,1,n) {
        if(ans[i]==INF) ans[i]=-1;
        cout<<ans[i]<<" ";
    }
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
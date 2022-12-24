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

void dfs(int cur, int par, int opp, vector<vector<pair<int,int>>> &adj, vector<int> &xo) {
    if(cur==opp) return;
    for(auto next: adj[cur]) {
        if(next.first != par) {
            xo[next.first] = (xo[cur]^next.second);
            dfs(next.first, cur, opp, adj, xo); 
        }
    }
}

void solve()
{
    int n,a,b; cin>>n>>a>>b; a--,b--;
    vector<vector<pair<int,int>>> adj(n);
    rep(i,0,n-1) {
        int u,v,w; cin>>u>>v>>w; u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> atot(n,-1), ttob(n,-1);
    atot[a] = 0, ttob[b] = 0;
    dfs(a,-1,b,adj,atot);
    dfs(b,-1,-1,adj,ttob);

    // out(atot);
    // out(ttob);

    set<int> st;
    rep(i,0,n) {
        if(i!=a and i!=b and atot[i]!=-1) st.insert(atot[i]);
    }

    rep(i,0,n) {
        if(i!=b and (ttob[i]==0 or (ttob[i]!=-1 and st.find(ttob[i])!=st.end()))) {
            cout<<"YES\n"; return;
        }
    } 

    cout<<"NO\n";
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
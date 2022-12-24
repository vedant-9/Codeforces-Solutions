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
    // Two way BFS using states
    int n,k; cin>>n>>k;
    vector<int> friends(k); in(friends);

    vector<vector<int>> adj(n);
    rep(i,0,n-1) {
        int u,v; cin>>u>>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    
    // -1 - Not reached till by anyone
    // 0 - vlad's friend/s reached that cell
    // 1 - vlad reached that cell
    vector<int> state(n, -1);
    queue<int> q;

    // NOTE - First push friends coz need to check meet corridor condition
    // Other side vlad's friends
    for(auto &f: friends) {
        f--;
        q.push(f);
        state[f] = 0;
    }

    // One side vlad 
    q.push(0);
    state[0] = 1;
    
    // Propogate the states
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: adj[cur]) {
            // yet to reach
            if(state[next]==-1) {
                state[next] = state[cur];
                q.push(next);
            }
        }
    }

    rep(i,1,n) {
        // connected by only one corridor (leaf) reached by vlad or not
        if(adj[i].size()==1 and state[i]==1) {
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
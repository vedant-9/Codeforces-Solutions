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

typedef long long              ll;
typedef long double            ld;
#define int                    long long
#define rep(i,s,e)             for(ll i=s; i<e; i++)
#define repr(i,s,e)            for(ll i=s; i>=e; i--)
#define in(A)                  for(auto &i : A) cin>>i
#define out(A)                 for(auto &i : A) cout<<i<<" "; cout<<endl
#define uniq(A)                A.erase(unique(all(A)),A.end())
#define all(A)                 A.begin(),A.end()
#define allr(A)                A.rbegin(),A.rend()
#define endl                   '\n'

bool per_square(ld a) { if(a<0) return 0; ll sr = sqrt(a); return (sr*sr == a); }
bool is_prime(ll x) { rep(i,2,sqrt(x)+1) if(x%i == 0) return 0; return 1; }
int xor_1ton(int n){ int A[4] = {n,1,n+1,0}; return A[n%4];}
template<typename T>bool is_pali(T A){ int n=A.size(); rep(i,0,n/2) { if(A[i]!=A[n-i-1])return 0;} return 1;}

void solve()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n);
    rep(i,0,m) {
        int u,v; cin>>u>>v; u--,v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    queue<int> q; q.push(0);
    vector<int> dist(n,1e9);
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto x:adj[cur]) {
            if(dist[x]==1e9) {
                dist[x]=dist[cur]+1; q.push(x);
            }
        }
    }
    vector<int> even,odd;
    rep(i,0,n) {
        if(dist[i]&1) odd.push_back(i+1);
        else even.push_back(i+1);
    }
    if(even.size()<odd.size()) {
        cout<<even.size()<<endl;
        out(even);
    } else {
        cout<<odd.size()<<endl;
        out(odd);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
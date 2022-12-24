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

int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

const int N=2e5+5;
map<int,int> ind[N];

void solve()
{
    int n; cin>>n;
    vector<pair<int,int>> v(n),ans(n);
    rep(i,0,n) { 
        cin>>v[i].first>>v[i].second; 
        ind[v[i].first][v[i].second]=i;
    }

    // adjacent possible nearest valid point
    // queue of indices not of points
    queue<int> q;
    vector<int> vis(n,0);
    rep(i,0,n) {
        int x=v[i].first,y=v[i].second;
        for(auto d:dir) {
            int nx=x+d[0],ny=y+d[1];
            if(ind[nx].find(ny)==ind[nx].end()) {
                q.push(i);
                vis[i]=1;
                ans[i]={nx,ny};
            }
        }
    }
    
    // bfs 
    while(!q.empty()) {
        int cur=q.front(); q.pop();
        int x=v[cur].first,y=v[cur].second;
        for(auto d:dir) {
            int nx=x+d[0],ny=y+d[1];
            if(ind[nx].find(ny)==ind[nx].end()) continue;
            int id=ind[nx][ny]; // index of shortest dist point
            if(vis[id]) continue;
            ans[id]=ans[cur];
            q.push(id);
            vis[id]=1;
        }
    }   

    rep(i,0,n) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl; 
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
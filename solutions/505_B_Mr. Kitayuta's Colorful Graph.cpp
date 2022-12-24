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

class dsu {
public:
    vector<int> p,s;
    dsu(int n) {
        p.resize(n); s.resize(n);
        for(int i=0;i<n;i++)
            p[i] = i,s[i] = 1;
    }
    int find_set(int x) {
        if(p[x]==x) return x;
        return find_set(p[x]);
    }
    bool same_set(int x, int y) {
        return find_set(x)==find_set(y);
    }
    void union_sets(int x, int y) {
        x = find_set(x); y = find_set(y);
        if(x==y) return;
        if(s[x]<s[y]) swap(x,y);
        p[y] = x; s[x] += s[y];
    }
};

void solve()
{
    int n,m; cin>>n>>m;
    vector<dsu> a(m,dsu(n));
    rep(i,0,m) {
        int u,v,c; cin>>u>>v>>c; u--,v--; c--;
        a[c].union_sets(u,v);
    }
    int q; cin>>q;
    while(q--) {
        int u,v; cin>>u>>v; u--,v--;
        int ans=0;
        rep(i,0,m) {
            if(a[i].same_set(u,v)) ans++;
        }
        cout<<ans<<endl;
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
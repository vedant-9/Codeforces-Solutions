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
    vector<int> par,sz;
    int comps;
    dsu(int n) {
        par.resize(n); sz.resize(n); comps=n;
        for(int i=0;i<n;i++)
            par[i]=i,sz[i]=1;
    }
    int find_set(int x) {
        if(par[x]==x) return x;
        return find_set(par[x]);
    }
    bool same_set(int x,int y) {
        return find_set(x)==find_set(y);
    }
    void union_sets(int x,int y) {
        x=find_set(x); y=find_set(y);
        if(x==y) return;
        if(sz[x]<sz[y]) swap(x,y);
        par[y]=x; sz[x]+=sz[y]; comps--;
    }
};

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    string res = "";
    int vis[26] = {0};

    int edge[26][26] = {0};
    dsu d(26);

    rep(i,0,n) {
        int x = s[i]-'a';   
        int f = 0;
        rep(j,0,26) {
            if(x==j) continue;
            if(edge[x][j]) {
                res += (char)(j+'a');
                vis[j] = 1;
                f = 1;
                break;
            }
        }
        if(f) continue;
        rep(j,0,26) {
            if(x==j) continue;
            if(!edge[x][j] and !vis[j] and !d.same_set(x,j)) {
                res += (char)(j+'a');
                edge[x][j] = 1;
                d.union_sets(x,j);
                vis[j] = 1;
                f = 1;
                break;
            }
        }
        if(!f) {
            rep(j,0,26) {
                if(x == j) continue;
                if(!edge[x][j] and !vis[j]) {
                    res += (char)(j+'a');
                    edge[x][j] = 1;
                    vis[j] = 1;
                    f = 1;
                    break;
                }
            }
        }
    }

    cout<<res<<endl;
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
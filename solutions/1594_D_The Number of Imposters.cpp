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

class dsu {
public:
    vector<int> p,s;
    dsu(int n) {
        p.resize(n+1); s.resize(n+1);
        for(int i=1;i<=n;i++)
            p[i] = i,s[i] = i<=n/2;
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
    // 1. Create dsu of 2*n (1 indexing used) 
    // 2. dsu from 1 to n represents crewmate and n to 2*n represents imposter
    // 3. x->y states crewmate then x and y both are in same set either c or i
    // 4. x->y states imposter then x and y are in different set
    // 5. For each component i and i+n has same parent then -1 as each one can either be c or i not both
    // 6. Add max of sz of comp x and y to ans
    int n,m,ans=0; cin>>n>>m;
    dsu d(2*n);
    while(m--) {
        int x,y; string t; cin>>x>>y>>t; 
        if(t=="crewmate") d.union_sets(x,y),d.union_sets(x+n,y+n);
        else d.union_sets(x,y+n),d.union_sets(x+n,y);
    }
    vector<int> vis(2*n+1,0);
    rep(i,1,n+1) {
        int x=d.find_set(i),y=d.find_set(i+n);
        if(x==y) {
            cout<<-1<<endl; return;
        } else if(vis[x]) continue;
        else {
            vis[x]=vis[y]=1;
            ans+=max(d.s[x],d.s[y]);
        }
    }
    cout<<ans<<endl;
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
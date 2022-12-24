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
    int n,q; cin>>n>>q;
    ordered_set<int> rows,cols;
    map<int,int> r,c;
    while(q--) {
        int t; cin>>t;
        if(t==1) {
            int x,y; cin>>x>>y;
            r[x]++; c[y]++;
            rows.insert(x); cols.insert(y);
        } else if(t==2) {
            int x,y; cin>>x>>y;
            r[x]--; c[y]--;
            if(!r[x]) rows.erase(x); 
            if(!c[y]) cols.erase(y);
        } else {
            // check if x1 to x2 in rows or y1 to y2 in cols
            int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
            auto p = rows.order_of_key(x1+1);
            auto q = rows.order_of_key(x2+1);
            auto r = cols.order_of_key(y1+1);
            auto s = cols.order_of_key(y2+1);
            // for(auto x:rows) cout<<x<<" "; cout<<endl;
            // for(auto x:cols) cout<<x<<" "; cout<<endl;
            if((rows.find(x1)!=rows.end() and rows.find(x2)!=rows.end() and q-p==x2-x1) or (cols.find(y1)!=cols.end() and cols.find(y2)!=cols.end() and s-r==y2-y1)) cout<<"Yes\n";
            else cout<<"No\n";
        }
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
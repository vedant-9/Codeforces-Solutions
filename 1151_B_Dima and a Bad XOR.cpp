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
bool is_prime(ll x){rep(i,2,sqrt(x)+1) if(x%i==0) return 0; return 1;}

int n,m; 
int a[501][501];

void solve()
{
    cin>>n>>m; 
    rep(i,0,n) {
        rep(j,0,m) {
            cin>>a[i][j];
        }
    }
    int x=0;
    rep(i,0,n) x^=a[i][0];
    if(x) {
        cout<<"TAK\n";
        rep(i,0,n) cout<<1<<" "; cout<<endl;
        return;
    }
    rep(i,0,n) {
        rep(j,1,m) {
            if(a[i][j]!=a[i][0]) {
                cout<<"TAK\n";
                rep(k,0,n) if(k==i) cout<<j+1<<" "; else cout<<1<<" "; cout<<endl;
                return;
            }
        }
    }
    cout<<"NIE\n";
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
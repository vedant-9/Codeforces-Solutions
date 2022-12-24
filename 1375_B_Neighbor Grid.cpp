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
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,0,n) rep(j,0,m) cin>>a[i][j];

    int f=0;
    rep(i,0,n) {
        rep(j,0,m) {
            if((i==0 and j==0) or (i==0 and j==m-1) or (i==n-1 and j==0) or (i==n-1 and j==m-1)) {
                if(a[i][j]>2) f=1;
                else a[i][j] = 2;
            }
            else if(i==0 or j==0 or i==n-1 or j==m-1) {
                if(a[i][j]>3) f=1;
                else a[i][j] = 3;
            }
            else {
                if(a[i][j]>4) f=1;
                else a[i][j] = 4;
            }
            if(f==1) {
                cout<<"NO\n"; return;
            }
        }
    }

    cout<<"YES\n";
    rep(i,0,n) {
        rep(j,0,m) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
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
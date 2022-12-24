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

bool check(int a[2][2])
{
    if(a[0][0]<a[0][1] and a[1][0]<a[1][1] and a[0][1]<a[1][1] and a[0][0]<a[1][0]) return 1;
    return 0;
}

void shift(int a[2][2]) {
    int b[2][2];
    b[0][0] = a[1][0];
    b[0][1] = a[0][0];
    b[1][0] = a[1][1];
    b[1][1] = a[0][1];
    rep(i,0,2) rep(j,0,2) a[i][j] = b[i][j];
}   

void solve()
{
    int a[2][2]; 
    rep(i,0,2) rep(j,0,2) cin>>a[i][j];

    if(check(a)) {
        cout<<"YES"<<endl;
        return;
    }

    shift(a);
    // rep(i,0,2) rep(j,0,2) cout<<a[i][j]<<" "; cout<<endl;
    if(check(a)) {
        cout<<"YES"<<endl;
        return;
    }

    shift(a);
    if(check(a)) {
        cout<<"YES"<<endl;
        return;
    }

    shift(a);
    if(check(a)) {
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;
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
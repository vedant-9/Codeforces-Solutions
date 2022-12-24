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
    int n; cin>>n;
    if(n%2 or n<3) cout<<-1<<endl;
    else if(n<12) {
        if(n==4) cout<<1<<" "<<1<<endl;
        else if(n==6) cout<<1<<" "<<1<<endl;
        else if(n==8) cout<<2<<" "<<2<<endl;
        else if(n==10) cout<<2<<" "<<2<<endl;
    }
    else {
        int t=n; t=(t/12)*12;
        int mn=t/6,mx=t/4;
        if(n%12==0) cout<<mn<<" "<<mx<<endl;
        else if(n%12==2) cout<<mn+1<<" "<<mx<<endl;
        else if(n%12==4) cout<<mn+1<<" "<<mx+1<<endl;
        else if(n%12==6) cout<<mn+1<<" "<<mx+1<<endl;
        else if(n%12==8) cout<<mn+2<<" "<<mx+2<<endl;
        else if(n%12==10) cout<<mn+2<<" "<<mx+2<<endl;
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
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
    vector<int> a(n); in(a);

    int odd=0,even=0;
    rep(i,0,n) if(a[i]&1) odd++; else even++;

    if(odd==0 or even==0) {
        cout<<n-1<<endl;
        repr(i,n-2,0) cout<<i+1<<" "<<n<<endl;
        return;
    }

    // odd - odd
    if(a[0]%2==1 and a[n-1]%2==1) {
        cout<<n-1<<endl;
        cout<<1<<" "<<n<<endl;
        rep(i,1,n-1) {
            if(a[i]%2==1) cout<<i+1<<" "<<n<<endl;
            else cout<<1<<" "<<i+1<<endl;
        }
        return;
    }

    // odd - even
    if(a[0]%2!=a[n-1]%2 and a[0]%2==1) {
        cout<<n-1<<endl;
        cout<<1<<" "<<n<<endl;
        rep(i,1,n-1) {
            if(a[i]%2==0) cout<<1<<" "<<i+1<<endl;
            else cout<<i+1<<" "<<n<<endl;
        }
        return;
    }

    // even - odd
    if(a[0]%2!=a[n-1]%2 and a[0]%2==0) {
        cout<<n-1<<endl;
        cout<<1<<" "<<n<<endl;
        rep(i,1,n-1) {
            if(a[i]%2==1) cout<<1<<" "<<i+1<<endl;
            else cout<<i+1<<" "<<n<<endl;
        }
        return;
    }

    // even - even
    if(a[0]%2==0 and a[n-1]%2==0) {
        cout<<n-1<<endl;
        cout<<1<<" "<<n<<endl;
        rep(i,1,n-1) {
            if(a[i]%2==1) cout<<1<<" "<<i+1<<endl;
            else cout<<i+1<<" "<<n<<endl;
        }
        return;
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
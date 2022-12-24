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
    // if k>=26 then string will be 'aaaa...'
    // mx is maximum char can be converted into 'a'
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int mx=0;
    for(auto &ch:s) {
        int d=ch-'a';
        
        // already less than mx can be converted..
        if(d<=mx) continue;

        // need d-mx ops to convert into 'a' check if we have that much
        if(k>=(d-mx)) {
            k-=(d-mx);
            mx=d;
        } else {
            // we can't convert ch to 'a' 
            // so use k ops to convert greater chars
            char cur=ch;
            for(auto &ch2:s) {
                if((ch2-'a')>mx and ch2<=cur) {
                    char b=cur-k;       // post op char
                    if(b<ch2) ch2=b;    // it will be always >mx can't convert to 'a'
                }
            }
            break;
        }
    }
    // convert all chars which are less equal to mx to 'a'
    for(auto &ch:s) {
        if(ch-'a'<=mx) ch='a';
    }
    cout<<s<<endl;
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
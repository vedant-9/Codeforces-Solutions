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

    int x = n;
    int p2 = 0, p5 = 0;
    while(x%5==0) x/=5, p5++;
    while(x%2==0) x/=2, p2++;

    // cout<<p2<<" "<<p5<<endl;

    int ans = n;
    while(1) {
        if(p2 > p5) {
            if(m < 5) {
                ans *= m; break;
            } else {
                m /= 5;
                ans *= 5;
                p5++;
            }
        } else if(p5 > p2) {
            if(m < 2) {
                ans *= m; break;
            } else {
                m /= 2;
                ans *= 2;
                p2++;
            }
        } else {
            if(m < 10) {
                ans *= m; break;
            } else {
                m /= 10;
                ans *= 10;
            }
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
    for(int t=1;t<=tc;t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
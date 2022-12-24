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

int gcd(int a,int b){ if(b==0) return a; return gcd(b,a%b); }
int lcm(int a,int b){ return a*b/(gcd(a,b)); }

void solve()
{
    int n; cin>>n;
    vector<int> a(n); in(a);
    int g = 0;
    for(auto i:a) g = gcd(g,i);

    if(g!=1) {
        cout<<-1<<endl; return;
    }

    int pos[1001];
    memset(pos,-1,sizeof(pos));
    rep(i,0,n) pos[a[i]] = i+1;

    int ans = -1;
    rep(i,1,1001) {
        rep(j,i,1001) {
            if(pos[i]!=-1 and pos[j]!=-1 and gcd(i,j)==1) {
                ans = max(ans, pos[i]+pos[j]);
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
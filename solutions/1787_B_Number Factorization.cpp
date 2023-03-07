// Author - Vedant Valsangkar
// 2023 CP GOALS - Expert at CF and Guardian at Leetcode
// I WILL MAKE IT HAPPEN
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

vector<pair<int,int>> prime_facs(int x) {
    vector<pair<int,int>> res;
    int c=0; while(x%2==0) c++,x/=2; if(c) res.push_back({c,2});
    for(int i=3;i*i<=x;i+=2) {
        c=0; while(x%i==0) c++,x/=i; if(c) res.push_back({c,i});
    }
    if(x>2) res.push_back({1,x});
    return res;
}

void solve()
{
    int n; cin>>n;
    auto v = prime_facs(n);
    // 2 ^ 2 * 5 ^ 2
    // 4 + 10 = 14
    // 10 ^ 2 => 10 * 2 = 20

    // 27 => 3^3, 3^2*3^1 => 9
    // 36 => 6^2, 2^2*3^2 => 12

    sort(allr(v));

    int mxcnt = 0;
    rep(i,0,v.size()) mxcnt = max(mxcnt, v[i].first);

    int ans = 0;
    rep(i,0,mxcnt) {
        int tmp = 1;
        rep(i,0,v.size()) {
            if(v[i].first<=1) continue;
            v[i].first--;
            tmp *= v[i].second;
        }
        if(tmp!=1) ans += tmp;
    }
    int tmp = 1;
    rep(i,0,v.size()) {
        if(v[i].first==1) tmp *= v[i].second;
    }
    if(tmp!=1) ans += tmp;
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

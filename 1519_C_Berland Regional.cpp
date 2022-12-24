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
    vector<int> u(n),s(n); in(u); in(s);
    map<int,vector<int>> mp;
    rep(i,0,n) {
        mp[u[i]].push_back(s[i]);
    }
    for(auto &it:mp) {
        auto &v=it.second;
        sort(allr(v));
        rep(i,1,v.size()) {
            v[i]+=v[i-1];
        }
        // out(v);
    }
    rep(k,1,n+1) {
        int ans=0;
        vector<int> toerase;
        for(auto &it:mp) {
            int sz=it.second.size();
            int x=sz/k*k-1;
            if(x>=0) ans+=it.second[x];
            if(it.second.size()==k) toerase.push_back(it.first);
        }
        for(auto t:toerase) mp.erase(t);
        cout<<ans<<" ";
    }
    cout<<endl;
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
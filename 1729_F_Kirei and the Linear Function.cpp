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
    string s; cin>>s;
    int w,m,n; cin>>w>>m; n=s.size();

    vector<int> pre_sum(n+1,0);
    rep(i,1,n+1) {
        pre_sum[i] = pre_sum[i-1]+(s[i-1]-'0');
    }

    map<int,vector<int>> mp;
    rep(i,0,n-w+1) {
        mp[(pre_sum[i+w]-pre_sum[i])%9].push_back(i);
    }

    while(m--) {
        int l,r,k; cin>>l>>r>>k; 
        int x = (pre_sum[r]-pre_sum[l-1])%9;

        pair<int,int> ans = {n,n};
        rep(u,0,9) {
            if(mp[u].size()>1 and (u*x+u)%9==k) 
                ans = min(ans, {mp[u][0],mp[u][1]}); 
            rep(v,0,9) {
                if(u==v) continue;
                if(mp[u].size() and mp[v].size() and (u*x+v)%9==k) 
                    ans = min(ans, {mp[u][0],mp[v][0]});
            }
        }
        if(ans==make_pair(n,n)) ans = {-2,-2};
        cout<<ans.first+1<<" "<<ans.second+1<<endl;
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
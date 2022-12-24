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
    map<int,int> mp;
    vector<int> cnta(10,0), cntb(10, 0);
    rep(i,0,n) {
        int x; cin>>x; 
        if(x>9) mp[x]++;
        else cnta[x]++;
    }

    int ans = 0;
    rep(i,0,n) {
        int x; cin>>x;
        if(x>9) {
            if(mp.find(x)==mp.end()) {
                cntb[(int)to_string(x).length()]++;
                ans++;
            } else {
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
            }
        }
        else cntb[x]++;
    }

    for(auto it:mp) {
        int l = to_string(it.first).length();
        cnta[l] += it.second;
        ans+=it.second;
    }

    rep(i,2,10) {
        int mn = min(cnta[i],cntb[i]);
        cnta[i] -= mn; cntb[i] -= mn;
        if(cnta[i]>0) cnta[1]+=cnta[i],ans+=cnta[i];
        if(cntb[i]>0) cntb[1]+=cntb[i],ans+=cntb[i];
    }

    int x = min(cnta[1],cntb[1]);
    ans += max(cnta[1]-x,cntb[1]-x);

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
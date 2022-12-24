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
    // What could be 1st x -> largest + diff arr[i]
    // Simply try for all x check whether next chain continues and we get n pairs
    // In next chain always pick largest and obv we have (prev) x so .....
    int n; cin>>n; vector<int> a(2*n); in(a); sort(all(a));
    auto check=[&](int x)->vector<pair<int,int>>{
        multiset<int,greater<int>> s;
        rep(i,0,2*n) s.insert(a[i]);
        vector<pair<int,int>> res;
        rep(i,0,n) {
            auto it1=s.begin();
            int y=x-*it1;
            s.erase(it1); 
            auto it2=s.find(y);
            if(it2==s.end()) return {};
            s.erase(it2);
            res.push_back({x-y,y});
            x=max(x-y,y);
        }
        return res;
    };
    rep(i,0,2*n-1) {
        // possible x
        int x = a[i]+a[2*n-1];
        auto v = check(x);
        if(v.size()) {
            cout<<"YES\n"; cout<<x<<endl;
            for(auto it:v) cout<<it.first<<" "<<it.second<<endl;
            return;
        }
    }
    cout<<"NO\n";
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
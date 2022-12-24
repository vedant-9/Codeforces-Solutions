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
typedef unsigned long long ull;
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

vector<int> facs;

void solve()
{
    // 110, 1100, 
    // 30 -> 24 + 6
    int n,ans; cin>>n;
    ans=__builtin_popcountll(n);
    int sz=facs.size()-1,flag=0;
    while(facs[sz]>n) sz--,flag=1;
    sz++; if(flag) sz++;
    rep(i,1,(1<<sz)) {
        set<int> takes;
        int sum=0;
        rep(j,0,sz) {
            if(i&(1<<j)) sum+=facs[j],takes.insert(facs[j]);
        }
        if(sum<=n and !takes.count(n-sum)) {
            ans=min(ans,(int)takes.size()+__builtin_popcountll(n-sum));
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int i=4,cur=6; 
    while(cur<1e12) {
        facs.push_back(cur);
        cur*=i;
        i++;
    }
    sort(allr(facs));
    // out(facs);
    // for(auto f:facs) {
    //     bitset<40> b(f);
    //     cout<<b.to_string()<<endl;
    // }
    int tc = 1;
    cin>>tc;
    for(int t=1;t<=tc;t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
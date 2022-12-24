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
bool is_prime(ll x){rep(i,2,sqrt(x)+1) if(x%i==0) return 0; return 1;}

void solve()
{
    // 1. If k>= n or m then cancel all flights from _ to _ & print -1.
    // 2. Find max ans over each i....i flights has to be cancelled from a then rem=k-i
    //    flights can be cancelled from b so find lower_bound of a[i]+ta to take journey 
    //    from b and then delete rem flights from b so ans would be b[it+rem]+tb
    // 3. If at any point m-it that means tot_rem less than or equals by rem then 
    //    cancel all tot_rem flights & print -1.
    int n,m,ta,tb,k; cin>>n>>m>>ta>>tb>>k; 
    vector<int> a(n),b(m); in(a); in(b);
    if(k>=n or k>=m) { cout<<-1<<endl; return;}
    int ans=0;
    rep(i,0,min(k,n)+1) {
        int rem=k-i;
        auto it=lower_bound(all(b),a[i]+ta)-b.begin();
        if(m-it<=rem) { cout<<-1<<endl; return;}
        ans=max(ans,b[it+rem]+tb);
    }   
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    // cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
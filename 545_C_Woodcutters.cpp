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

int rec(int i, int prevState, vector<pair<int,int>> &a, vector<vector<int>> &dp) {
    int n = a.size();
    if(i == n) return 0;

    int &ans = dp[i][prevState];
    if(ans != -1) return ans;

    // don't cut the tree
    ans = rec(i+1, 0, a, dp);

    // cut the tree and fall to left if can
    int prev = INT_MIN;
    if(i-1 >= 0) {
        if(prevState!=2) prev = a[i-1].first;
        else prev = a[i-1].first+a[i-1].second;
    } 

    if(i==0 or prev < a[i].first-a[i].second) {
        ans = max(ans, rec(i+1, 1, a, dp)+1);
    }

    // cut the tree and fall to right if can
    if(i == n-1 or (i+1 < n and (a[i].first+a[i].second < a[i+1].first))) {
        ans = max(ans, rec(i+1, 2, a, dp)+1);
    }

    return ans;
}

void solve()
{
    int n; cin>>n;
    vector<pair<int,int>> a(n); 
    rep(i,0,n) cin>>a[i].first>>a[i].second;
    // sort(all(a));
    vector<vector<int>> dp(n, vector<int>(3, -1));
    cout<<rec(1, 1, a, dp)+1<<endl;
}   

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    // cin>>tc;
    for(int t=1;t<=tc;t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
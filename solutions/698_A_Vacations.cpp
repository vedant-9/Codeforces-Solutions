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

typedef long long              ll;
typedef long double            ld;
#define int                    long long
#define rep(i,s,e)             for(ll i=s; i<e; i++)
#define repr(i,s,e)            for(ll i=s; i>=e; i--)
#define in(A)                  for(auto &i : A) cin>>i
#define out(A)                 for(auto &i : A) cout<<i<<" "; cout<<endl
#define uniq(A)                A.erase(unique(all(A)),A.end())
#define all(A)                 A.begin(),A.end()
#define allr(A)                A.rbegin(),A.rend()
#define endl                   '\n'

bool per_square(ld a) { if(a<0) return 0; ll sr = sqrt(a); return (sr*sr == a); }
bool is_prime(ll x) { rep(i,2,sqrt(x)+1) if(x%i == 0) return 0; return 1; }
int xor_1ton(int n){ int A[4] = {n,1,n+1,0}; return A[n%4];}
template<typename T>bool is_pali(T A){ int n=A.size(); rep(i,0,n/2) { if(A[i]!=A[n-i-1])return 0;} return 1;}

const int N = 1e5;
vector<int> a;
int n;
int dp[N][2][2];

int rec(int i, int g, int c) {
    if(i==n) return 0;
    if(dp[i][g][c]!=-1) return dp[i][g][c];
    int ans;
    if(a[i]==0) ans=1+rec(i+1,0,0);
    if(a[i]==1) {
        if(c) ans=1+rec(i+1,0,0);
        else ans=min(1+rec(i+1,0,0),rec(i+1,0,1));
    }
    if(a[i]==2) {
        if(g) ans=1+rec(i+1,0,0);
        else ans=min(1+rec(i+1,0,0),rec(i+1,1,0));
    }
    if(a[i]==3) {
        if(g) ans=min(1+rec(i+1,0,0),rec(i+1,0,1));
        else if(c) ans=min(1+rec(i+1,0,0),rec(i+1,1,0));
        else ans=min({1+rec(i+1,0,0),rec(i+1,0,1),rec(i+1,1,0)});
    }
    return dp[i][g][c]=ans;
}

void solve()
{
    cin>>n; a.resize(n); in(a);
    cout<<rec(0,0,0)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    memset(dp,-1,sizeof(dp));
    int tc = 1;
    // cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
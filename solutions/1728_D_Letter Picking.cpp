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

const int N = 2222;
int dp[N][N];

int n; 
string s;

// -1 - Bob wins, 0 - Draw, 1 - Alice wins
int comp(int pre, char a, char b) {
    if(pre==1) return pre;
    if(a==b) return 0;
    if(a<b) return 1;
    return -1;
}

int win(int i, int j) {
    if(i==j) return 0;

    int &ans = dp[i][j];
    if(ans!=-2) return ans;

    int pat[4] = {};                                 // Alice  -  Bob
    pat[0] = comp(win(i+2, j), s[i], s[i+1]);        // i      -  i+1
    pat[1] = comp(win(i+1, j-1), s[i], s[j-1]);      // i      -  j-1
    pat[2] = comp(win(i+1, j-1), s[j-1], s[i]);      // j-1    -  i
    pat[3] = comp(win(i, j-2), s[j-1], s[j-2]);      // j-1    -  j-2

    return ans = max(min(pat[0],pat[1]),min(pat[2],pat[3]));
}

void solve()
{
    cin>>s;
    n = s.length();

    rep(i,0,n+2) {
        rep(j,0,n+2) 
            dp[i][j] = -2;
    } 

    int ans = win(0, n);

    if(ans==1) cout<<"Alice\n";
    else if(ans==0) cout<<"Draw\n";
    else cout<<"Bob\n";
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
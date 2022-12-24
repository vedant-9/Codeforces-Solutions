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
    string s,t; cin>>s>>t;
    int i=0;
    while(i<n and s[i]==t[i]) i++;
    if(i==n) {
        cout<<"YES\n"; return;
    }
    int cur = (s[i]=='B'?0:(t[i]=='B'?1:-1)), j = i;
    while(i<n) {
        if(s[i]=='B' and cur==0 and t[i]=='B') cur=1,s[i]='W';
        else if(t[i]=='B' and cur==1 and s[i]=='B') cur=0,t[i]='W';
        else {
            if(cur==0 and s[i]=='B') s[i]='W';
            else if(cur==1 and t[i]=='B') t[i]='W';
            else break;
            i++;
        }
    }
    while(j<n) {
        if(s[j]=='B' or t[j]=='B') {
            cout<<"NO\n"; return;
        }
        j++;
    }
    cout<<"YES\n";
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
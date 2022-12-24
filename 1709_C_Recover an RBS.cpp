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

bool balanced(string s) {
    int n = s.size();
    int cnt = 0;
    rep(i,0,n) {
        if(s[i]=='(') cnt++;
        else cnt--;
        if(cnt<0) return 0;
    }
    return (cnt==0);
}

void solve()
{
    string s; cin>>s;
    int n = s.size();

    int open = n/2, closed = n/2;
    vector<int> ind;
    rep(i,0,n) {
        if(s[i]=='(') open--;
        else if(s[i]==')') closed--;
        else ind.push_back(i);
    }

    int sz = ind.size();
    rep(i,0,sz) {
        if(i<open) s[ind[i]]='(';
        else s[ind[i]]=')';
    }

    // cout<<s<<endl;
    if(open>0 and closed>0) {
        swap(s[ind[open]],s[ind[open-1]]);
        if(balanced(s)) {
            cout<<"NO\n"; return;
        }
    }
    cout<<"YES"<<endl;
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
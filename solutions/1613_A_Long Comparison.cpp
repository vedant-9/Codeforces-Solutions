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
    string x1,x2; int p1,p2; cin>>x1>>p1>>x2>>p2;
    if(x1.length()+p1<x2.length()+p2) {
        cout<<"<\n";
    } else if(x1.length()+p1>x2.length()+p2) {
        cout<<">\n";
    } else {
        int i=0,j=0; 
        while(i<x1.length() and j<x2.length()) {
            if(x1[i]<x2[j]) {
                cout<<"<\n"; return;
            } else if(x1[i]>x2[j]) {
                cout<<">\n"; return;
            }
            i++; j++;
        }
        while(i<x1.length() and x1[i]=='0') i++;
        while(j<x2.length() and x2[j]=='0') j++;
        if(i==x1.length() and j==x2.length()) {
            cout<<"=\n";
        } else if(i==x1.length()) {
            cout<<"<\n";
        } else {
            cout<<">\n";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
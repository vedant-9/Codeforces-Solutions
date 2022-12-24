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
    int n; cin>>n; vector<int> a(n); in(a);
    pair<int,int> mx = {0,0};
    pair<int,int> ans = {n,0};
    int i=0;
    while(i<n) {
        if(a[i]==0) {
            i++; continue;
        }
        int j=i,cn=0,c2=0,c1=0;
        vector<int> neg;
        vector<pair<int,int>> till;
        while(i<n and a[i]!=0) {
            if(a[i]<0) {
                cn++; neg.push_back(i);
                till.push_back({c2,c1});
            }
            if(abs(a[i])==2) c2++;
            else c1++;
            i++;
        }
        if(cn%2==0) {
            if(c2>mx.first or (c2==mx.first and mx.second==0 and c1)) {
                mx={c2,c1}; ans={j,n-i};
            } 
        } else {
            pair<int,int> right = {c2-till[0].first-(abs(a[neg[0]])==2),c1-till[0].second-abs(a[neg[0]]==1)};
            pair<int,int> left = till.back();
            if(right.first<left.first or (right.first==left.first and right.second==0 and left.second)) {
                if(left.first>mx.first or (left.first==mx.first and  left.second and mx.second==0)) {
                    mx=left; ans={j,n-neg.back()};
                }
            } else {
                if(right.first>mx.first or (right.first==mx.first and right.second and mx.second==0)) {
                    mx=right; ans={neg[0]+1,n-i};
                }
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
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
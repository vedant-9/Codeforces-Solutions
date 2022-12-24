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
    string s; cin>>s;
    int n = s.size();

    char st = s[0], en = s[n-1];

    vector<pair<char,int>> v;
    rep(i,1,n-1) {
        v.push_back({s[i],i+1});
    }

    if(st < en) {
        sort(all(v));

        int cost = 0, jumps = 0;  
        char prev = st;

        vector<int> ans;
        ans.push_back(1);

        int i = 0;
        while(i<v.size() and v[i].first < st) {
            i++;
        }

        while(i<v.size() and v[i].first <= en) {
            cost += abs(v[i].first - prev);
            ans.push_back(v[i].second);
            prev = v[i].first;
            i++;
        }

        cost += abs(en - prev);
        ans.push_back(n);

        cout<<cost<<" "<<ans.size()<<endl;
        out(ans);
    }
    else {
        sort(allr(v));

        int cost = 0, jumps = 0;  
        char prev = st;

        vector<int> ans;
        ans.push_back(1);

        int i = 0;
        while(i<v.size() and v[i].first > st) {
            i++;
        }

        while(i<v.size() and v[i].first >= en) {
            cost += abs(v[i].first - prev);
            ans.push_back(v[i].second);
            prev = v[i].first;
            i++;
        }

        cost += abs(en - prev);

        ans.push_back(n);

        cout<<cost<<" "<<ans.size()<<endl;
        out(ans);
    }
    
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
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

void solve()
{
    int n; cin>>n;
    string l,r; cin>>l>>r;
    vector<pair<int,int>> ans;
    map<char,queue<int>> mp1,mp2;
    rep(i,0,n) {
        mp1[l[i]].push(i);
        mp2[r[i]].push(i);
    }

    for(auto &it:mp1) {
        if(it.first=='?') continue;
        auto &q1 = it.second;
        auto &q2 = mp2[it.first];
        while(!q1.empty() and !q2.empty()) {
            ans.push_back({q1.front(),q2.front()});
            q1.pop(); q2.pop();
        }
        if(!q1.empty()) {
            auto &q3 = mp2['?'];
            while(!q1.empty() and !q3.empty()) {
                ans.push_back({q1.front(),q3.front()});
                q1.pop(); q3.pop();
            }
        }
    }
    auto &q1 = mp1['?'];
    for(auto &it:mp2) {
        auto &q2 = mp2[it.first];
        while(!q1.empty() and !q2.empty()) {
            ans.push_back({q1.front(),q2.front()});
            q1.pop(); q2.pop();
        }
    }
    cout<<ans.size()<<endl;
    for(auto p:ans) {
        cout<<p.first+1<<" "<<p.second+1<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    // cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
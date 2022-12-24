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

int n,r1,c1,r2,c2;
vector<string> a;

vector<pair<int,int>> b,c;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

void dfs(int i, int j, int f) {
    if(i<0 or j<0 or i>=n or j>=n or a[i][j]!='0')
        return;
    a[i][j]='2'; if(f) c.push_back({i,j}); else b.push_back({i,j});
    dfs(i-1,j,f); dfs(i,j-1,f); dfs(i+1,j,f); dfs(i,j+1,f);
}

void solve()
{
    cin>>n>>r1>>c1>>r2>>c2; r1--,r2--,c1--,c2--;
    a.resize(n); in(a);
    dfs(r1,c1,0);
    if(a[r2][c2]=='2') {
        cout<<0<<endl;
        return;
    }
    dfs(r2,c2,1);
    int mn = INT_MAX;
    for(auto p1:b) {
        for(auto p2:c) {
            int t = (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
            mn = min(mn,t);
        }
    }
    cout<<mn<<endl;
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
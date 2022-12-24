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

int n,m;
bool val(int i, int j) { return (i>=0 and j>=0 and i<n and j<m); }

void solve()
{
    int ans=0; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m)),vis(n,vector<int>(m,0));
    rep(i,0,n) rep(j,0,m) cin>>a[i][j]; vector<int> sz;
    rep(i,0,n) {
        rep(j,0,m) {
            if(!vis[i][j]) {
                queue<pair<int,int>> q; q.push({i,j}); vis[i][j]=1; int cnt=0;
                while(!q.empty()) {
                    auto cur=q.front(); q.pop(); int x=cur.first,y=cur.second; cnt++;
                    bitset<4> bit(a[x][y]);
                    if(!bit[3] and val(x-1,y) and !vis[x-1][y]) q.push({x-1,y}),vis[x-1][y]=1; 
                    if(!bit[2] and val(x,y+1) and !vis[x][y+1]) q.push({x,y+1}),vis[x][y+1]=1; 
                    if(!bit[1] and val(x+1,y) and !vis[x+1][y]) q.push({x+1,y}),vis[x+1][y]=1; 
                    if(!bit[0] and val(x,y-1) and !vis[x][y-1]) q.push({x,y-1}),vis[x][y-1]=1; 
                }
                sz.push_back(cnt);
            }
        }
    }
    sort(allr(sz)); out(sz);
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
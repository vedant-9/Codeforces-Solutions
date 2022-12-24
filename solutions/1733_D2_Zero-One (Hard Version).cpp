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

int n,x,y; 
const int N = 5010;
int dp[N][N];

int rec(int l, int r, vector<int> &ind) {
    if(l>r) return 0;

    int &ans = dp[l][r];
    if(ans!=-1) return ans;

    ans=1e17;

    if(ind[l]+1 == ind[r]) 
        ans = min(ans, min(2*y,x) + rec(l+1,r-1,ind));
    else 
        ans = min(ans, min(y, x*(ind[r]-ind[l])) + rec(l+1,r-1,ind));
    
    if(ind[l]+1 == ind[l+1]) 
        ans = min(ans, min(2*y,x) + rec(l+2,r,ind));
    else 
        ans = min(ans, min(y, x*(ind[l+1]-ind[l])) + rec(l+2,r,ind));
    
    if(ind[r-1]+1 == ind[r])
        ans = min(ans, min(2*y,x) + rec(l,r-2,ind));
    else 
        ans = min(ans, min(y, x*(ind[r]-ind[r-1])) + rec(l,r-2,ind));

    return ans;
}

void solve()
{
    cin>>n>>x>>y;
    string a,b; cin>>a>>b;

    vector<int> ind;
    rep(i,0,n) {
        if(a[i]!=b[i]) ind.push_back(i);
    }

    int sz = ind.size();
    if(sz==0) {
        cout<<0<<endl;
        return;
    }
    if(sz%2==1) {
        cout<<-1<<endl;
        return;
    }

    if(x>=y) {
        if(sz==2) {
            if(ind[0]+1==ind[1]) cout<<min(x,2*y)<<endl;
            else cout<<y<<endl;
        } else {
            cout<<y*(sz/2)<<endl;
        }
        return;
    }

    rep(i,0,sz) rep(j,0,sz) dp[i][j] = -1;

    cout<<rec(0,sz-1,ind)<<endl;
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
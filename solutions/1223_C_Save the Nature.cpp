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

int gcd(int a,int b){ if(b==0) return a; return gcd(b,a%b); }
int lcm(int a,int b){ return a*b/(gcd(a,b)); }

void solve()
{
    int n; cin>>n; vector<int> prices(n+1,0); rep(i,1,n+1) cin>>prices[i],prices[i]/=100; 
    sort(prices.begin()+1,prices.end(),greater<int>());
    rep(i,1,n+1) prices[i]+=prices[i-1];
    int x,a,y,b; cin>>x>>a>>y>>b; int req; cin>>req;
    if(x>y) swap(x,y),swap(a,b);
    int cxy=0,cx=0,cy=0;
    rep(i,1,n+1) {
        if(i%a==0 and i%b==0) cxy++;
        else if(i%a==0) cx++;
        else if(i%b==0) cy++;
        int tot=0,j=1;
        tot+=(prices[cxy+j-1]-prices[j-1])*(x+y); j+=cxy;
        tot+=(prices[cy+j-1]-prices[j-1])*(y); j+=cy;
        tot+=(prices[cx+j-1]-prices[j-1])*(x);
        if(tot>=req) {
            cout<<i<<endl; return;
        }
    }
    cout<<-1<<endl;
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
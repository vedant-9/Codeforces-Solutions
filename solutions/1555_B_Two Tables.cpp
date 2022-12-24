// Author - Vedant Valsangkar
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long              ll;
typedef long double            ld;
typedef unsigned long long     ull;
typedef vector<ll>             vll;
typedef vector<string>         vst;
typedef set<ll>                sll;
typedef map<ll,ll>             mll;
typedef pair<ll,ll>            pll;
typedef vector<pll>            vpll;
typedef multiset<ll>           msll;

#define int                    long long
#define rep(i,s,e)             for(ll i=s; i<e; i++)
#define repr(i,s,e)            for(ll i=s; i>=e; i--)
#define repit(it,A)            for(auto it = A.begin();it!=A.end();it++)
#define in(A)                  for(auto &i : A) cin>>i
#define out(A)                 for(auto &i : A) cout<<i<<" "; cout<<endl
#define uniq(A)                A.erase(unique(all(A)),A.end())
#define all(A)                 A.begin(),A.end()
#define allr(A)                A.rbegin(),A.rend()
#define pb                     push_back
#define mem1(A)                memset(A,-1,sizeof(A))
#define mem0(A)                memset(A,0,sizeof(A))
#define ppcll                  __builtin_popcountll
#define M_PI                   3.14159265358979323846
#define ss                     second
#define ff                     first
#define INF                    1e18
#define sz(A)                  (int)((A).size())
#define spre(x)                fixed<<setprecision(x)
#define endl                   '\n'

bool per_square(ld a) { if(a<0) return false; ll sr = sqrt(a); return (sr*sr == a); }
bool is_prime(ll x) { rep(i,2,sqrt(x)+1) if(x%i == 0) return false; return true; }
bool sort_by_sec(const pll &a, const pll &b) { return (a.second < b.second); } 
template<typename T>bool is_pali(T A){ int n=sz(A); rep(i,0,n/2) { if(A[i]!=A[n-i-1])return 0;} return 1;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

void solve()
{
    int w,h;
    cin>>w>>h;
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;

    int ww,hh;
    cin>>ww>>hh;

    // check the shorter distance from room to our given table from all corners
    int ans = INT_MAX;
	if (x2 - x1 + ww <= w) 
    {
		ans = min(ans, max(0LL, ww - x1));
		ans = min(ans, max(0LL, x2 - (w - ww)));
	}
	if (y2 - y1 + hh <= h) 
    {
		ans = min(ans, max(0LL, hh - y1));
		ans = min(ans, max(0LL, y2 - (h - hh)));
	}
	if (ans == INT_MAX)
		cout << -1 << endl;
	else
		cout << ld(ans) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<spre(9);
    // sieve();
    int tests = 1;
    cin>>tests;
    for(int test=1;test<=tests;test++)
    {
        // cout << "Case #" << test << ": ";
        solve();
    }
    // cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}